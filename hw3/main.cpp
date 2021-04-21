/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: main
*/

#include <iostream>
#include "simulator.h"
#include "Heap.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    //const string file1 = "RequestFile.txt";
    //const double maxWaitTime1 = 5;

    double avg = atof(argv[2]);
    simulator s(argv[1], avg);

    //simulator s(file1, maxWaitTime1);


    cout << "Minimum number of printers required: " << s.getMinPrinterCount() << endl;

    cout << endl;
    s.displaySimulation(s.getMinPrinterCount());
    cout << endl;

    cout << "Average waiting time: " << s.getAverageTime() << endl;

    return 0;
}
