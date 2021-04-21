/*
* Title: Binary Search Trees
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 2
* Description: header file of binary search tree class
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include "BinaryNode.h"

using namespace std;

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();
        bool add(const int newEntry);
        bool remove(const int anEntry);
        bool contains(const int anEntry);

        void preorderTraverse();
        void inorderTraverse();
        void postorderTraverse();
        void levelorderTraverse();

        int span(const int a, const int b);
        void mirror();

    protected:
        bool containsItem(BinaryNode *treePtr, int searchKey);
        bool insertItem(BinaryNode *&treePtr,const int& item);
        bool deleteItem(BinaryNode *&treePtr, int searchKey);
        void deleteNodeItem(BinaryNode *&nodePtr);
        void processLeftmost(BinaryNode *&nodePtr, int& item);
        int getHeightHelper(BinaryNode* subTreePtr) const;
        int getNumberOfNodesHelper(BinaryNode *subTreePtr) const;
        void destroyTree(BinaryNode *&treePtr);
        void preorder(BinaryNode *&treePtr);
        void postorder(BinaryNode *&treePtr);
        void inorder(BinaryNode *&treePtr);
        void levelorder(BinaryNode *&treePtr);
        void levelorder2(BinaryNode *&treePtr, int level);
        void span2(const int a, const int b, BinaryNode *&treePtr, int& count);
        void mirror2(BinaryNode *&treePtr);

    private:
        // properties
        BinaryNode *root;
};

#endif // BINARYSEARCHTREE_H
