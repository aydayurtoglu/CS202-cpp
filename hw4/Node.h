/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : header file of Node
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
        Node();
        Node(const string str, const int id);
        ~Node();

        void setData(const string str);
        void setIndex(const int id);
        void setNext(Node *nextPtr);
        void setVisited(bool v);
        string getData();
        int getIndex();
        bool getVisited();
        Node* getNext();
        Node& operator=(const Node& right);
        void setAllUnvisited();

    private:
        string data;
        int index;
        Node *next;
        bool visited;
};

#endif // NODE_H
