/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : header file of Queue class
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

class Queue
{
    public:
        Queue();
        ~Queue();
        bool isEmpty() const;
        bool enqueue(int data);
        bool dequeue();
        bool dequeue(int &data);
        bool getFront(int &data) const;

    private:
        struct QueueNode{
            int item;
            QueueNode* next;
        };
        QueueNode *backPtr;
        QueueNode *frontPtr;
};

#endif // QUEUE_H
