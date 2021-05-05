/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : source code of Node class
*/

#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

Node::Node(){
    data = "";
    index = 0;
    next = NULL;
    visited = false;
}

Node::Node(const string str, const int id){
    data = str;
    index = id;
    next = NULL;
    visited = false;
}

Node::~Node(){
    if (next != NULL)
        delete next;
}
void Node::setData(const string str){
    data = str;
}
void Node::setIndex(const int id){
    index = id;
}
void Node::setNext(Node *nextPtr){
    next = nextPtr;
}
void Node::setVisited(bool v){
    visited = v;
}
string Node::getData(){
    return data;
}

int Node::getIndex(){
    return index;
}
bool Node::getVisited(){
    return visited;
}
Node* Node::getNext(){
    return next;
}
Node& Node::operator=( const Node& right ) {

    data = (right.data).c_str();
    index = right.index;
    next = right.next;

    return *this;
}
