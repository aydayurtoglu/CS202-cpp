/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : header file of HashTable
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class HashTable
{
    public:
        HashTable(int thisSize);
        ~HashTable();
        int hash (const string &key, int tableSize);
        void insert(const string word, int no);
        int getIndex(const string word);
        void displayTable();
        void displaySlot (int slotNumber);
        Node* findLastNode(int slotNumber);
        Node* findNode(const int id);
        string findWord(const int id);
        void setAllUnvisited();

    private:
        int size;
        Node** table;
};

#endif // HASHTABLE_H
