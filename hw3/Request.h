/*
* Title: Heaps
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 3
* Description: header of Request class
*/

#include <iostream>
using namespace std;

#ifndef REQUEST_H
#define REQUEST_H


class Request
{
    public:
        Request();
        Request(const int thisId, const int thisPriority, const int thisRequestTime, const int thisProcessTime);
        int getId();
        int getPriority();
        int getRequestTime();
        int getProcessTime();
        int getIsCompleted();
        void complete();

        Request& operator=(const Request& right);

    private:
        int id;
        int priority;
        int requestTime;
        int processTime;
        int isCompleted;
};

#endif // REQUEST_H
