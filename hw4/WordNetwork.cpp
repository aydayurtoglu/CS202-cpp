/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : source code of WordNetwork
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Queue.h"
#include "WordNetwork.h"
#include "HashTable.h"
#include "Node.h"

using namespace std;

WordNetwork::WordNetwork(const string vertexFile, const string edgeFile){
    ifstream vFile(vertexFile.c_str());
    ifstream eFile(edgeFile.c_str());

    // initialize graph
    no = countLine(vertexFile);
    edgeNo = 0;
    adj = new int*[no];

    for( int i = 0; i < no; i++) {
        adj[i] = new int[no];
        for( int j = 0; j < no; j++) {
            adj[i][j] = 0;
        }
    }

    // initialize hash table
    t = new HashTable(73);
    string word;
    for (int i = 0; getline(vFile, word); i++)
        t->insert(word, i);

    // add edges according to the edgeFile
    string word1;
    string word2;
    string line;
    for( int i = 0; getline(eFile,line); i++){
        stringstream   linestream(line);
        string         text;

        for( int j = 0; getline(linestream, text, ','); j++){
            switch(j) {
                case 0: word1 = text;
                case 1: word2 = text;
                default: cout << "";
            }

        }

        // find the indexes of the words
        int index1 = findIndex(word1);
        int index2 = findIndex(word2);

        if (index1 >= 0 && index2 >= 0){
            adj[index1][index2] = 1;
            adj[index2][index1] = 1;
            edgeNo++;
        }
    }
}

WordNetwork::~WordNetwork(){
    for ( int i = 0; i < no; i++)
        delete []adj[i];

    if ( adj != NULL)
        delete []adj;

    if (t != NULL)
        delete t;
}

void WordNetwork::listNeighbors (const string word ){
    int index = findIndex(word);
    if (index < 0){
        cout << "Warning: " << word << " does not exist" << endl;
        return;
    }
    else {
        cout << "Neighbors of " << word << ":" << endl;

        for (int i = 0; i < no; i++){
            if (adj[index][i] == 1){
                string neighbor = t->findWord(i);
                cout << neighbor << endl;
            }
        }
    }
}

void WordNetwork::listNeighbors (const string word, const int distance){
    int index = findIndex(word);
    if (index < 0){
        cout << "Warning: " << word << " does not exist" << endl;
        return;
    }
    else {
        (t->findNode(index))->setVisited(true);

        cout << "Neighbors of " << word << ":" << endl;
        listNeighborsHelper(word, distance, 1);
    }
    t->setAllUnvisited();
}

void WordNetwork::listConnectedComponents (){
    int count = 1;

    for (int i = 0; i < no; i++){
        Node* n = t->findNode(i);
        int count2 = 0;
        if (n != NULL){
            if (!(n->getVisited())) {
                n->setVisited(true);
                if ( isConnected(n->getData())){
                    cout << "Connected Component " << count << ":" << endl;
                    cout << n->getData() << endl;
                    listNeighborsHelper(n->getData(), no, 1);
                    count++;
                }
            }
        }
    }
}

void WordNetwork::findShortestPath (const string word1, const string word2){
    int index1 = findIndex(word2);

    int* path = new int[no];
    for (int i = 0; i < no; i++)
        path[i] = -1;

    if (!bfs(word1, word2, path)){
        cout <<  "No connection exists" << endl;
        return;
    }

    cout << "Shortest path from " << word1 << " to " << word2 << ":" << endl;

    string words[no];
    int count = 0;
    for (int i = 0; path[index1] != -1; i++){
        words[i] = t->findWord(path[index1]);
        index1 = path[index1];
        count++;
    }

    int temp;
    for(int i = count-1; i >= 0; i--)
        cout << words[i] << endl;

    cout << word2 << endl;
    delete []path;
}

int WordNetwork::countLine(const string file){
    ifstream file1(file.c_str());
    int count = 0;
    string line1;
    while(getline(file1, line1)){
        count++;
    }

    return count;
}

int WordNetwork::findIndex(string word){
    return t->getIndex(word);
}

void WordNetwork::listNeighborsHelper(const string word, int distance, int d){
    int index = findIndex(word);
    string neighbor = "";
    if (d <= distance){
        for (int i = 0; i < no; i++){
            if (adj[index][i] == 1 && (!(t->findNode(i))->getVisited())){
                neighbor = t->findWord(i);
                (t->findNode(i))->setVisited(true);
                cout << neighbor << endl;
                listNeighborsHelper(neighbor, distance, d+1);
            }
        }
    }
}
bool WordNetwork::isConnected(const string word){
    int index = findIndex(word);

    for (int i = 0; i < no; i++){
        if (adj[index][i] == 1 && (!(t->findNode(i))->getVisited())){
            return true;
        }
    }
    return false;
}
bool WordNetwork::bfs(const string word1, const string word2, int *path){
    // use breadth first search algorithm to find shortest path
    int index1 = findIndex(word1);
    int index2 = findIndex(word2);
    // initialize queue
    Queue q;
    // enqueue the source word
    q.enqueue(index1);

    t->setAllUnvisited();
    (t->findNode(index1))->setVisited(true);

    while (!q.isEmpty()){
        int temp;
        q.dequeue(temp);

        for (int i = 0; i < no; i++){
            if (adj[temp][i] == 1 && (!(t->findNode(i))->getVisited())){
                // a neighbor is found
                q.enqueue(i);
                path[i] = temp;
                (t->findNode(i))->setVisited(true);
                if (index2 == i)
                    return true;
            }
        }
    }
    return false;
}
