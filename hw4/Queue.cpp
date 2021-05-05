/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : source code of Queue class
*/

#include <iostream>
#include <string>
#include "Queue.h"
#include "Node.h"

using namespace std;

Queue::Queue(){
    backPtr = NULL;
    frontPtr = NULL;
}

Queue::~Queue(){
    while(!isEmpty())
        dequeue();
}
bool Queue::isEmpty() const{
    return backPtr == NULL;
}
bool Queue::enqueue(int data){
    QueueNode *newPtr = new QueueNode;

    newPtr->item = data;
    newPtr-> next = NULL;

    if (isEmpty())
        frontPtr = newPtr;
    else
        backPtr->next = newPtr;

    backPtr = newPtr;
    return true;
}
bool Queue::dequeue(){
    if (isEmpty())
        return false;
    else{
        QueueNode *tempPtr = frontPtr;

        if (frontPtr == backPtr){
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next;

        tempPtr->next = NULL;
        delete tempPtr;
        return true;
    }
}
bool Queue::dequeue(int &data){
    if (isEmpty())
        return false;
    else{
        data = frontPtr->item;
        dequeue();
        return true;
    }
}
bool Queue::getFront(int &data) const{
    if (isEmpty())
        return false;
    else {
        data = frontPtr->item;
        return true;
    }
}
