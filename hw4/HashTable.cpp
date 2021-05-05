/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : source code of HashTable
*/
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int thisSize){
    size = thisSize;
    table = new Node*[size];

    for (int i = 0; i < size; i++)
        table[i] = NULL;
}

HashTable::~HashTable(){
    for ( int i = 0; i < size; i++) {
        delete table[i];
    }

    if ( table != NULL) {
        delete[] table;
    }
}
int HashTable::hash(const string &key, int tableSize){
    int hashVal = 0;

    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

    hashVal %= tableSize;

    if (hashVal < 0)
        hashVal += tableSize;

    return hashVal;
};

void HashTable::insert(const string word, int no){
    int hashVal = hash(word, size);
    Node *newNode = new Node(word, no);

    if (table[hashVal] == NULL)
        table[hashVal] = newNode;
    else if ( table[hashVal]->getNext() == NULL)
        table[hashVal]->setNext(newNode);
    else{
        Node* prev = findLastNode(hashVal);
        prev->setNext(newNode);
    }
}

int HashTable::getIndex(const string word){
    for (int i = 0; i < size; i++){
        Node* n;
        for( n = table[i]; n != NULL; n = n->getNext() ){
            int comparison = word.compare(n->getData());
            if (comparison == 0)
                return n->getIndex();
        }
    }
    return -1;
}

void HashTable::displayTable(){
    for (int i = 0; i < size; i++){
        displaySlot(i);
    }
}

void HashTable::displaySlot(int slotNumber){
    Node *n;
    cout << "slot: " << slotNumber;
    for( n = table[slotNumber]; n != NULL; n = n->getNext() ){
        if (hash(n->getData(), size) == slotNumber){
            cout << " " << n->getData() << ", ";
        }
    }
    cout << endl;
}

Node* HashTable::findLastNode(int slotNumber){
    Node* cur = table[slotNumber];
    while (cur->getNext() != NULL)
        cur = cur->getNext();
    return cur;
}

string HashTable::findWord(const int id){
    for (int i = 0; i < size; i++){
        Node* n;
        for( n = table[i]; n != NULL; n = n->getNext() ){
            if(id == n->getIndex())
                return n->getData();
        }
    }
    return "";
}

Node* HashTable::findNode(const int id){
    for (int i = 0; i < size; i++){
        Node* n;
        for( n = table[i]; n != NULL; n = n->getNext() ){
            if(id == n->getIndex())
                return n;
        }
    }
    return NULL;
}

void HashTable::setAllUnvisited(){
    for (int i = 0; i < size; i++){
        Node* n;
        for( n = table[i]; n != NULL; n = n->getNext() ){
            n->setVisited(false);
        }
    }
}
