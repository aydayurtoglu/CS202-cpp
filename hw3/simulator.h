/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: header of simulator
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include "Heap.h"
#include "Request.h"

using namespace std;

class simulator
{
    public:
        simulator(const string thisfile, const double maxWaitTime1);
        ~simulator();

        void displaySimulation(const int printerNo);
        double getAverageTime();
        int getMinPrinterCount();

    protected:
        void calculateAveWith(const int printerNo, double& ave);

    private:
        int requestNo;
        double maxWaitTime;
        double actualAverageTime;
        string file;
        Heap *h;
};

#endif // SIMULATOR_H
