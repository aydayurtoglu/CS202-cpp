/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: header of heap
*/

#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include "Request.h"

using namespace std;

class Heap
{
    public:
        Heap();
        Heap(const int maxNo);
        ~Heap();

        bool heapIsEmpty() const;
        void insert(const Request newItem);
        void remove(Request &r);
        int getSize();
        Request getItem(int index);

    protected:
        void heapRebuild(int root);

    private:
        Request* items;
        int max;
        int size;
};

#endif // HEAP_H
