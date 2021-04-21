/*
* Title: Binary Search Trees
* Author: Ayda Yurtoglu
* ID: 21903153
* Section: 1
* Assignment: 2
* Description: source code of binary search tree class
*/

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}

bool BinarySearchTree::isEmpty(){
    if (root == NULL)
        return true;

    return false;
}
int BinarySearchTree::getHeight(){
    return getHeightHelper(root);
}
int BinarySearchTree::getNumberOfNodes(){
    return getNumberOfNodesHelper(root);
}

bool BinarySearchTree::add(const int newEntry){
    return insertItem(root, newEntry);
}
bool BinarySearchTree::remove(const int anEntry){
    return deleteItem(root, anEntry);
}
bool BinarySearchTree::contains(const int anEntry){
    return containsItem(root, anEntry);
}

void BinarySearchTree::preorderTraverse(){
    preorder(root);
}
void BinarySearchTree::inorderTraverse(){
    inorder(root);
}
void BinarySearchTree::postorderTraverse(){
    postorder(root);
}
void BinarySearchTree::levelorderTraverse(){
    levelorder(root);
}

int BinarySearchTree::span(const int a, const int b){
    int count = 0;
    span2(a, b, root, count);
    return count;
}
void BinarySearchTree::mirror(){
    mirror2(root);
}

// protected helper methods
bool BinarySearchTree::containsItem(BinaryNode *treePtr, int searchKey){
    if (treePtr == NULL){
        cout << "Tree doesn't contain " << searchKey << endl;
        return false;
    }
    else if (searchKey == treePtr->item){
        return true;
    }
    else if (searchKey < treePtr->item){
        containsItem(treePtr->leftChildPtr, searchKey);
    }
    else
        containsItem(treePtr->rightChildPtr, searchKey);
}
bool BinarySearchTree::insertItem(BinaryNode *&treePtr,const int& item){
    // if root is null, add it to root
    if (treePtr == NULL){
        treePtr = new BinaryNode(item, NULL, NULL);
        return true;
    }

    // if item is smaller than the root, add it to the left
    else if (item < treePtr->item){
        insertItem(treePtr->leftChildPtr, item);
        return true;
    }

    // if item is greater than the root add it to the right
    else if (item > treePtr->item){
        insertItem(treePtr->rightChildPtr, item);
        return true;
    }
    // if item exists in the tree, it is not inserted
    else
        cout << item << " is not inserted." << endl;
        return false;
}
bool BinarySearchTree::deleteItem(BinaryNode *&treePtr, int searchKey){
    if (treePtr == NULL){
        cout << searchKey << " is not deleted" << endl;
        return false;
    }
    else if (searchKey == treePtr->item){
        deleteNodeItem(treePtr);
        return true;
    }
    else if (searchKey < treePtr->item)
        deleteItem(treePtr->leftChildPtr, searchKey);
    else
        deleteItem(treePtr->rightChildPtr, searchKey);
}
void BinarySearchTree::deleteNodeItem(BinaryNode *&nodePtr){
    BinaryNode *delPtr;
    int replacementItem;

    // no left and right children
    if ((nodePtr->leftChildPtr == NULL)&&(nodePtr->rightChildPtr == NULL)){
        delete nodePtr;
        nodePtr = NULL;
    }
    // there exists only right child
    else if (nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr -> rightChildPtr;
        delPtr -> rightChildPtr = NULL;
        delete delPtr;
    }
    // there exists only left child
    else if (nodePtr->rightChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr -> leftChildPtr;
        delPtr -> leftChildPtr = NULL;
        delete delPtr;
    }
    // both children exist
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}
void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int& item){
    if (nodePtr->leftChildPtr == NULL){
        item = nodePtr->item;
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr -> rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, item);
}
int BinarySearchTree::getHeightHelper(BinaryNode *subTreePtr) const{
    if (subTreePtr == NULL)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}
int BinarySearchTree::getNumberOfNodesHelper(BinaryNode *subTreePtr) const{
    if (subTreePtr == NULL)
        return 0;
    else
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}
void BinarySearchTree::destroyTree(BinaryNode *&treePtr){
    if (treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}
void BinarySearchTree::preorder(BinaryNode *&treePtr){
    if (treePtr != NULL){
        cout << treePtr->getItem() << " ";
        preorder(treePtr->leftChildPtr);
        preorder(treePtr->rightChildPtr);
    }
}
void BinarySearchTree::postorder(BinaryNode *&treePtr){
    if (treePtr != NULL){
        postorder(treePtr->leftChildPtr);
        postorder(treePtr->rightChildPtr);
        cout << treePtr->getItem() << " ";
    }
}
void BinarySearchTree::inorder(BinaryNode *&treePtr){
    if (treePtr != NULL){
        inorder(treePtr->leftChildPtr);
        cout << treePtr->getItem() << " ";
        inorder(treePtr->rightChildPtr);
    }
}
void BinarySearchTree::levelorder(BinaryNode *&treePtr){
    if (treePtr == NULL)
        return;

    for (int i = 1; i <= getHeight(); i++){
        levelorder2(treePtr, i);
    }
}
void BinarySearchTree::levelorder2(BinaryNode *&treePtr, int level){
    if (treePtr == NULL)
        return;

    if (level == 1)
        cout << treePtr->getItem() << " ";

    else if (level > 1){
        levelorder2(treePtr->leftChildPtr, level-1);
        levelorder2(treePtr->rightChildPtr, level-1);
    }
}
void BinarySearchTree::span2(const int a, const int b, BinaryNode *&treePtr, int& count){

    if (treePtr == NULL)
        return;

    if (treePtr->getItem() >= a && treePtr->getItem() <= b){
        count++;
        span2(a, b, treePtr->rightChildPtr, count);
        span2(a, b, treePtr->leftChildPtr, count);
    }

    else if (treePtr->getItem() < a)
        span2(a, b, treePtr->rightChildPtr, count);

    else if (treePtr->getItem() > b)
        span2(a, b, treePtr->leftChildPtr, count);

}
void BinarySearchTree::mirror2(BinaryNode *&treePtr){

    if (treePtr != NULL){
        mirror2(treePtr->leftChildPtr);
        mirror2(treePtr->rightChildPtr);

        //swap nodes
        BinaryNode *temp = treePtr->getLeftChildPtr();
        treePtr->leftChildPtr = treePtr->getRightChildPtr();
        treePtr->rightChildPtr = temp;
    }
}
