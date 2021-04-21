/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: source code of simulator
*/
#include "Heap.h"
#include "simulator.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

simulator::simulator(const string thisfile, const double maxWaitTime1){

    maxWaitTime = maxWaitTime1;
    file = thisfile;
    actualAverageTime = 0;
    requestNo = 0;
    h = NULL;
}

simulator::~simulator(){
   // if (h != NULL)
    //    delete h;
}

void simulator::displaySimulation(const int printerNo){

    cout << "Simulation with " << printerNo << " printers:" << endl;
    int time = 1;
    int totalWaitTime = 0;
    Request r;
    Request printer[printerNo];
    int printerTime[printerNo];

    // read request file
    ifstream RequestFile(file.c_str());

    string stringId;
    string stringP;
    string stringRt;
    string stringPt;

    int id;
    int priority;
    int requestTime;
    int processTime;

    string line;

    for( int i = 0; getline(RequestFile,line); i++){
        stringstream   linestream(line);
        string         text;

        if (i == 0){ // read the first line
            string stringRequestNo;
            getline(linestream, text, ' ');
            stringRequestNo = text;
            stringstream ssRn(stringRequestNo);
            ssRn >> requestNo;

            // initialize heap
            h = new Heap(requestNo);
        }
        else { // rest of the file
            for( int j = 0; getline(linestream, text, ' '); j++){
                switch(j) {
                    case 0: stringId = text;
                    case 1: stringP = text;
                    case 2: stringRt = text;
                    default: cout << "";
                }

            }
            stringPt = text;

            stringstream ssId(stringId);
            ssId >> id;

            stringstream ssP( stringP);
            ssP >> priority;

            stringstream ssRt( stringRt);
            ssRt >> requestTime;

            stringstream ssPt( stringPt);
            ssPt >> processTime;

            // finished reading the first line, now insert it to the heap
            if (time == requestTime){
                Request r(id, priority, requestTime, processTime);
                h->insert(r);

            }
            else{
                do{
                    if (time == requestTime){
                        Request r(id, priority, requestTime, processTime);
                        h->insert(r);
                    }

                    for (int a = 0; a < printerNo; a++){
                        if (time == printerTime[a] + printer[a].getProcessTime()){
                            printer[a].complete();
                            printerTime[a] = 0;
                        }

                        if (printer[a].getId() == 0){
                            if(!(h->heapIsEmpty())){
                                h->remove(r);
                                printer[a] = r;
                                printerTime[a] = time;
                                totalWaitTime = totalWaitTime + time - r.getRequestTime();
                                cout << "Printer " << a << " prints print request " << r.getId() << " at minute " << time << " (wait: " << time-r.getRequestTime() << " mins)" << endl;
                            }
                        }
                    }
                }while(time++ != requestTime);
            }
        }
    }


    while (!(h->heapIsEmpty())){
        for (int a = 0; a < printerNo; a++){
            if (time == printerTime[a] + printer[a].getProcessTime()){
                printer[a].complete();
                printerTime[a] = 0;
            }
            if (printer[a].getId() == 0){
                h->remove(r);
                printer[a] = r;
                printerTime[a] = time;
                totalWaitTime = totalWaitTime + time - r.getRequestTime();
                cout << "Printer " << a << " prints print request " << r.getId() << " at minute " << time << " (wait: " << time-r.getRequestTime() << " mins)" << endl;
            }
        }
        time++;
    }
    delete h;
}

double simulator::getAverageTime(){
    return actualAverageTime;
}

int simulator::getMinPrinterCount(){
    int printerCount = 1;
    double ave = maxWaitTime + 1;

    while (ave > maxWaitTime){
        calculateAveWith(printerCount,ave);
        printerCount++;
    }
    actualAverageTime = ave;
    return printerCount-1;
}

void simulator::calculateAveWith(const int printerNo, double& ave){ // calculates the average time with this many printers

    int time = 1;
    int totalWaitTime = 0;
    Request r;
    Request printer[printerNo];
    int printerTime[printerNo];

    // read request file
    ifstream RequestFile(file.c_str());

    string stringId;
    string stringP;
    string stringRt;
    string stringPt;

    int id;
    int priority;
    int requestTime;
    int processTime;

    string line;

    for( int i = 0; getline(RequestFile,line); i++){
        stringstream   linestream(line);
        string         text;

        if (i == 0){ // read the first line
            string stringRequestNo;
            getline(linestream, text, ' ');
            stringRequestNo = text;
            stringstream ssRn(stringRequestNo);
            ssRn >> requestNo;

            // initialize heap
            h = new Heap(requestNo);
        }
        else { // rest of the file
            for( int j = 0; getline(linestream, text, ' '); j++){
                switch(j) {
                    case 0: stringId = text;
                    case 1: stringP = text;
                    case 2: stringRt = text;
                    default: cout << "";
                }

            }
            stringPt = text;

            stringstream ssId(stringId);
            ssId >> id;

            stringstream ssP( stringP);
            ssP >> priority;

            stringstream ssRt( stringRt);
            ssRt >> requestTime;

            stringstream ssPt( stringPt);
            ssPt >> processTime;

            // finished reading the first line, now insert it to the heap
            if (time == requestTime){
                Request r(id, priority, requestTime, processTime);
                h->insert(r);
            }
            else{
                do{
                    if (time == requestTime){
                        Request r(id, priority, requestTime, processTime);
                        h->insert(r);
                    }

                    for (int a = 0; a < printerNo; a++){
                        if (time == printerTime[a] + printer[a].getProcessTime()){
                            printer[a].complete();
                            printerTime[a] = 0;
                        }

                        if (printer[a].getId() == 0){
                            if(!(h->heapIsEmpty())){
                                h->remove(r);
                                printer[a] = r;
                                printerTime[a] = time;
                                totalWaitTime = totalWaitTime + time - r.getRequestTime();
                            }
                        }
                    }
                }while(time++ != requestTime);
            }
        }
    }
    while (!(h->heapIsEmpty())){
        for (int a = 0; a < printerNo; a++){
            if (time == printerTime[a] + printer[a].getProcessTime()){
                printer[a].complete();
                printerTime[a] = 0;
            }
            if (printer[a].getId() == 0){
                h->remove(r);
                printer[a] = r;
                printerTime[a] = time;
                totalWaitTime = totalWaitTime + time - r.getRequestTime();
            }
        }
        time++;
    }

    ave = (double) totalWaitTime;
    ave = ave / requestNo;
    delete h;
    h = NULL;
}
