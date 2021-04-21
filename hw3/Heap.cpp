/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: source code of heap
*/

#include "Heap.h"
#include <iostream>

using namespace std;
Heap::Heap(){
    size = 0;
    max = 0;
}
Heap::Heap(const int maxNo){
    max = maxNo;
    size = 0;
    items = new Request[maxNo];
}

Heap::~Heap(){
    delete []items;
}

bool Heap::heapIsEmpty() const{
    return (size == 0);
}

void Heap::insert(const Request newItem){
    if (size < max){
        items[size] = newItem;

        int place = size;
        int parent = (place - 1) / 2;

        while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority()) ) {
            Request temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
/*
        if ( (items[place].getPriority() == items[parent].getPriority()) && (items[place].getRequestTime() < items[parent].getRequestTime())) {
            Request temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
*/
        size++;
    }
}

int Heap::getSize(){
    return size;
}

Request Heap::getItem(int index){
    return items[index];
}

void Heap::remove(Request &r){
    if (!heapIsEmpty()){
        r = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root){
    int child = 2 * root + 1;
    if ( child < size ) {
        int rightChild = child + 1;

        if ( (rightChild < size) &&(items[rightChild].getPriority() > items[child].getPriority()) )
            child = rightChild;

        if ( items[root].getPriority() < items[child].getPriority() || ( items[root].getPriority() == items[child].getPriority() && items[root].getRequestTime() > items[child].getRequestTime())) {
            Request temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}

