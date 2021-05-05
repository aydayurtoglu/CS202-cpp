/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ayda Yurtoglu
* ID: 21903153
* Section : 1
* Assignment : 4
* Description : header file of WordNetwork
*/

#ifndef WORDNETWORK_H
#define WORDNETWORK_H
#include <iostream>
#include "HashTable.h"

using namespace std;

class WordNetwork {
    public :
        WordNetwork (const string vertexFile, const string edgeFile);
        ~WordNetwork () ;
        void listNeighbors (const string word);
        void listNeighbors (const string word, const int distance);
        void listConnectedComponents ();
        void findShortestPath (const string word1, const string word2);

    private :
        // properties for adjacency matrix
        int no; // dimension of the matrix
        int edgeNo;
        int** adj;
        HashTable* t;

        int countLine(const string file);
        int findIndex(string word);
        void listNeighborsHelper(const string word, int distance, int d);
        bool isConnected(const string word);
        bool bfs(const string word1, const string word2, int* path);
};

#endif // WORDNETWORK_H
