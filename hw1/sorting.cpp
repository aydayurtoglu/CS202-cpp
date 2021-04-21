/*
* Title: Sorting and Algorithm Efficiency
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 1
* Description: Sorting source code
*/

#include "sorting.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

sorting::sorting()
{
    //ctor
}
void sorting::selectionSort(int *arr, const int size, int &compCount, int &moveCount){

    int comp = 0;
    int move = 0;

    for (int last = size-1; last >= 1; --last) {

        int indexSoFar = last+1;
        int indexOfmax = 0;

        // finding maximum
        for (int i = 1; i < indexSoFar; ++i){
            if (arr[i] > arr[indexOfmax]){
                indexOfmax = i;
            }
            comp++;
        }

        // swap operation
        int temp = arr[indexOfmax];
        arr[indexOfmax] = arr[last];
        arr[last] = temp;
        move+=3; // swap operation has 3 data moves
    }

    compCount = comp;
    moveCount = move;
}

void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    int comp = 0;
    int move = 0;

    mergeSort2(arr, 0, size-1, comp, move);

    compCount = comp;
    moveCount = move;
}
void sorting::mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount){

    if (first < last) {
        int mid = (first + last)/2;

        mergeSort2(arr, first, mid, compCount, moveCount);
        mergeSort2(arr, mid+1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);
    }

}
void sorting::merge( int *arr, int first, int mid, int last, int &compCount, int &moveCount) {

    int tempArray[last+1];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
        }
        else {
            tempArray[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index){
        tempArray[index] = arr[first1];
        moveCount++;
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index){
        tempArray[index] = arr[first2];
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index){
        arr[index] = tempArray[index];
        moveCount++;
    }

}

void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount){
    int comp = 0;
    int move = 0;

    quickSort2(arr, 0, size-1, comp, move);

    compCount = comp;
    moveCount = move;
}
void sorting::quickSort2(int *arr, int first, int last, int &compCount, int &moveCount){

    int pivotIndex;

    if (first < last) {

        partition(arr, first, last, pivotIndex,compCount, moveCount);

        quickSort2(arr, first, pivotIndex-1, compCount, moveCount);
        quickSort2(arr, pivotIndex+1, last, compCount, moveCount);

    }
}
void sorting::partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = arr[first];
    moveCount++;

    int lastS1 = first;
    int firstUnknown = first + 1;

    for ( ; firstUnknown <= last; ++firstUnknown) {
        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1], moveCount);
        }
        compCount++;
    }

    swap(arr[first], arr[lastS1], moveCount);
    pivotIndex = lastS1;

}
void sorting::swap(int &x, int &y, int &moveCount) {
    int temp = x;
    x = y;
    y = temp;
    moveCount+=3;
}

void sorting::radixSort(int *arr, const int size){
    // find the maximum element of the array
    int max = arr[0];
    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    // calculate its digit number
    int digitNo = log10(max)+1;
    radixSort2(arr, size, digitNo);
}
void sorting::radixSort2(int *arr, const int size, int digitNo){
    for (int i = 1; i <= digitNo; i++) {

        // Initialize 10 groups to empty
        int groups[10][size];
        int counter[10];

        // Initialize each counter with 0
        for (int j = 0; j < 10; j++){
            counter[j] = 0;

            for ( int k = 0; k < size; k++){
                groups[j][k] = 0;
            }
        }

        for (int a = 0; a < size; a++){
            int k = 0;

            if (i == 1){
                k = arr[a]%10;
            }
            else{
                k = arr[a]/pow(10,i-1);
                k = k % pow(10,i-1);
            }

            if (k > 9){
                groups[0][counter[0]] = arr[a];
                counter[0] = counter[0] + 1;
            }
            else {
                groups[k][counter[k]] = arr[a];
                counter[k] = counter[k] + 1;
            }
        }

        int index = 0;

        for(int b = 0; b < 10;b++){
            for(int c = 0; c < counter[b]; c++)
            {
                arr[index] = groups[b][c];
                index++;
            }
        }
    }
}
int sorting::pow(int a, int b){ // integer based power
    int result = 1;

    if(b == 0)
        return 1;

    for( int i = 0; i < b; i++){
        result = result * a;
    }
    return result;
}

void sorting::displayArray(const int *arr, const int size){
    cout << "{ ";
    for (int i = 0; i < size-1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[size-1] << " }" << endl;
}

void sorting::createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;

    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++){
        int random = rand() % size;     // in the range 0 to array size
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
        arr4[i] = random;
    }
}
void sorting::createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){

    int *temp = new int[size];

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;

    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++){
        int random = rand() % size;     // in the range 0 to array size
        temp[i] = random;
    }

    int a = 0;
    mergeSort( temp, size, a, a);

    for (int i = 0; i < size; i++){
        arr1[i] = temp[i];
        arr2[i] = temp[i];
        arr3[i] = temp[i];
        arr4[i] = temp[i];
    }

    delete []temp;
}
void sorting::createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int *temp = new int[size];

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;

    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++){
        int random = rand() % size;     // in the range 0 to array size
        temp[i] = random;
    }

    int a = 0;
    mergeSort( temp, size, a, a);

    for (int i = 0; i < size; i++){
        arr1[i] = temp[size-i-1];
        arr2[i] = temp[size-i-1];
        arr3[i] = temp[size-i-1];
        arr4[i] = temp[size-i-1];
    }

    delete []temp;
}

void sorting::performanceAnalysis(){

    int sizes[7] = {6000,10000,14000,18000,22000,26000,30000};
    int size = 0;

    double sortTime1[7], sortTime2[7], sortTime3[7], sortTime4[7];
    int compSelection[7], moveSelection[7], compMerge[7], moveMerge[7], compQuick[7], moveQuick[7];

    cout << endl;
    cout << "RANDOM ARRAYS " << endl;

    for (int i = 0; i < 7; i++){
        size = sizes[i];
        int compCount = 0;
        int moveCount = 0;
        double elapsedTime;

        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];

        createRandomArrays(arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();
        selectionSort(arr1, size, compCount, moveCount);
        elapsedTime =  1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime1[i] = elapsedTime;
        compSelection[i] = compCount;
        moveSelection[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        mergeSort(arr2, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime2[i] = elapsedTime;
        compMerge[i] = compCount;
        moveMerge[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        quickSort(arr3, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime3[i] = elapsedTime;
        compQuick[i] = compCount;
        moveQuick[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        radixSort(arr4, size);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime4[i] = elapsedTime;

        delete []arr1;
        delete []arr2;
        delete []arr3;
        delete []arr4;
    }


    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Selection Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime1[i] << " ms             " << compSelection[i] << "              " << moveSelection[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime2[i] << " ms             " << compMerge[i] << "              " << moveMerge[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime3[i] << " ms             " << compQuick[i] << "              " << moveQuick[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Radix Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " <<  endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime4[i] << " ms"<< endl;
    }

    cout << endl;
    cout << "ASCENDING ARRAYS " << endl;

    for (int i = 0; i < 7; i++){
        size = sizes[i];
        int compCount = 0;
        int moveCount = 0;
        double elapsedTime = 0;

        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];

        createAscendingArrays(arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();
        selectionSort(arr1, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime1[i] = elapsedTime;
        compSelection[i] = compCount;
        moveSelection[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        mergeSort(arr2, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime2[i] = elapsedTime;
        compMerge[i] = compCount;
        moveMerge[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        quickSort(arr3, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime3[i] = elapsedTime;
        compQuick[i] = compCount;
        moveQuick[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        radixSort(arr4, size);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime4[i] = elapsedTime;

        delete []arr1;
        delete []arr2;
        delete []arr3;
        delete []arr4;
    }


    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Selection Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime1[i] << " ms             " << compSelection[i] << "              " << moveSelection[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime2[i] << " ms             " << compMerge[i] << "              " << moveMerge[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime3[i] << " ms             " << compQuick[i] << "              " << moveQuick[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Radix Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " <<  endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime4[i]  << " ms" << endl;
    }

    cout << endl;
    cout << "DESCENDING ARRAYS " << endl;

    for (int i = 0; i < 7; i++){
        size = sizes[i];
        int compCount = 0;
        int moveCount = 0;
        double elapsedTime = 0;

        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];

        createDescendingArrays(arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();
        selectionSort(arr1, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime1[i] = elapsedTime;
        compSelection[i] = compCount;
        moveSelection[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        mergeSort(arr2, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime2[i] = elapsedTime;
        compMerge[i] = compCount;
        moveMerge[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        quickSort(arr3, size, compCount, moveCount);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime3[i] = elapsedTime;
        compQuick[i] = compCount;
        moveQuick[i] = moveCount;

        elapsedTime = 0;
        startTime = clock();
        radixSort(arr4, size);
        elapsedTime = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sortTime4[i] = elapsedTime;

        delete []arr1;
        delete []arr2;
        delete []arr3;
        delete []arr4;
    }


    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Selection Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime1[i] << " ms             " << compSelection[i] << "              " << moveSelection[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime2[i] << " ms             " << compMerge[i] << "              " << moveMerge[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " << "compCount         " << "moveCount         " << endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime3[i] << " ms             " << compQuick[i] << "              " << moveQuick[i] << endl;
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Radix Sort" << endl;
    cout << "Array Size         "  << "Elapsed Time         " <<  endl;
    for (int i = 0; i < 7; i++){
        cout << sizes[i] << "              " << sortTime4[i]  << " ms" << endl;
    }
}
