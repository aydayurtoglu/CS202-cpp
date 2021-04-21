/*
* Title: Sorting and Algorithm Efficiency
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 1
* Description: Main
*/

#include <iostream>
#include "sorting.h"

using namespace std;

int main()
{
    sorting sorter;

    // initializing array
    int arrSize = 16;
    int compCount;
    int moveCount;

    // initializing arrays
    int *arr = new int [arrSize];
    int temp[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};

    for (int i = 0; i < arrSize; i++){
        arr[i] = temp[i];
    }

    cout << "Selection sort:" << endl;
    sorter.selectionSort(arr, arrSize, compCount , moveCount);
    cout << "Number of comparisons: "<< compCount << endl;
    cout << "Number of data moves: "<< moveCount << endl;
    sorter.displayArray(arr, arrSize);
    cout << endl;


    for (int i = 0; i < arrSize; i++){
        arr[i] = temp[i];
    }

    cout << "Merge sort:" << endl;
    sorter.mergeSort(arr, arrSize, compCount , moveCount);
    cout << "Number of comparisons: "<< compCount << endl;
    cout << "Number of data moves: "<< moveCount << endl;
    sorter.displayArray(arr, arrSize);
    cout << endl;

    for (int i = 0; i < arrSize; i++){
        arr[i] = temp[i];
    }

    cout << "Quick:" << endl;
    sorter.quickSort(arr, arrSize, compCount , moveCount);
    cout << "Number of comparisons: "<< compCount << endl;
    cout << "Number of data moves: "<< moveCount << endl;
    sorter.displayArray(arr, arrSize);
    cout << endl;

    for (int i = 0; i < arrSize; i++){
        arr[i] = temp[i];
    }

    cout << "Radix sort:" << endl;
    sorter.radixSort(arr, arrSize);
    sorter.displayArray(arr, arrSize);
    cout << endl;

    delete []arr;

    return 0;
}
