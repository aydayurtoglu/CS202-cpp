/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: source file of Request class
*/

#include <iostream>
using namespace std;

#include "Request.h"

Request::Request(){
    id = 0;
    priority = 0;
    requestTime = 0;
    processTime = 0;
    isCompleted = 0;
}


Request::Request(const int thisId, const int thisPriority, const int thisRequestTime, const int thisProcessTime){
    id = thisId;
    priority = thisPriority;
    requestTime = thisRequestTime;
    processTime = thisProcessTime;
    isCompleted = 0;
}

int Request::getId(){
    return id;
}
int Request::getPriority(){
    return priority;
}
int Request::getRequestTime(){
    return requestTime;
}
int Request::getProcessTime(){
    return processTime;
}

int Request::getIsCompleted(){
    return isCompleted;
}

void Request::complete(){
    isCompleted = 1;
    id = 0;
}

Request& Request::operator=( const Request& right ) {

    id = right.id;
    priority = right.priority;
    requestTime = right.requestTime;
    processTime = right.processTime;
    isCompleted = right.isCompleted;

    return *this;
}

