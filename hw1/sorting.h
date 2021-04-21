/*
* Title: Sorting and Algorithm Efficiency
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 1
* Description: Sorting header file
*/

#ifndef SORTING_H
#define SORTING_H
#include <iostream>

using namespace std;

class sorting
{
    public:
        sorting();
        void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
        void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
        void quickSort(int *arr, const int size, int &compCount, int &moveCount);
        void radixSort(int *arr, const int size);
        void displayArray(const int *arr, const int size);
        void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
        void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
        void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
        void performanceAnalysis();

    private:
        void mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount);
        void merge(int *arr, int first, int mid, int last,int &compCount, int &moveCount);
        void quickSort2(int *arr, int first, int last, int &compCount, int &moveCount);
        void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
        void swap(int &x, int &y, int &moveCount);
        void radixSort2(int *arr, const int size, int digitNo);
        int pow(int x, int p);
};

#endif // SORTING_H
