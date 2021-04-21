/*
* Title: Binary Search Trees
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 2
* Description: header file of binary node class
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>

using namespace std;


class BinaryNode
{
    public:
        BinaryNode();
        BinaryNode(int rootItem, BinaryNode* leftPtr, BinaryNode* rightPtr);
        ~BinaryNode();

        void setItem(const int& thisItem);
        int getItem() const;
        bool isLeaf() const;

        BinaryNode* getLeftChildPtr() const;
        BinaryNode* getRightChildPtr() const;

        void setLeftChildPtr(BinaryNode* leftPtr);
        void setRightChildPtr(BinaryNode* rightPtr);

        friend class BinarySearchTree;

    private:
        int item;
        BinaryNode *leftChildPtr;
        BinaryNode *rightChildPtr;
};

#endif // BINARYNODE_H
