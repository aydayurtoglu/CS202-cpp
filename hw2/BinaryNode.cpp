/*
* Title: Binary Search Trees
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 2
* Description: source code of binary node class
*/

#include "BinaryNode.h"
#include <iostream>

using namespace std;

BinaryNode::BinaryNode()
{
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
BinaryNode::BinaryNode(int rootItem, BinaryNode* leftPtr, BinaryNode* rightPtr){
    item = rootItem;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}

BinaryNode::~BinaryNode()
{
    if (leftChildPtr == NULL)
        delete leftChildPtr;

    if (rightChildPtr == NULL)
        delete rightChildPtr;
}

void BinaryNode::setItem(const int& thisItem){
    item = thisItem;
}
int BinaryNode::getItem() const{
    return item;
}
bool BinaryNode::isLeaf() const{

}
BinaryNode* BinaryNode::getLeftChildPtr() const{
    return leftChildPtr;
}
BinaryNode* BinaryNode::getRightChildPtr() const{
    return rightChildPtr;
}

void BinaryNode::setLeftChildPtr(BinaryNode* leftPtr){
    leftChildPtr = leftPtr;
}
void BinaryNode::setRightChildPtr(BinaryNode* rightPtr){
    rightChildPtr = rightPtr;
}
