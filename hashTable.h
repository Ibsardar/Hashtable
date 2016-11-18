///hashTable.h
///By: Ibrahim Sardar

#ifndef HASHTABLE_H_EXISTS
#define HASHTABLE_H_EXISTS

#include <string>
#include <vector>

#include "linkedList.h"

using namespace std;

//class hashTable
class hashTable{
    private:
        vector < linkedList > hTable; //our hashTable "storage system" ---> vector of linkedList objects
    public:
        // init funcs:
        hashTable();
        hashTable(string);
        void init_hashTable();
        // hashing funcs:
        int  getIndex(string);
        int  getIndex(char);
        char getCharFromIndex(int);
        // load funcs:
        void loadFile(string);
        void insertWord(string); // insert word into: vec< LList(word) >
        // print funcs:
        void printTable();
        void printTable(char);
        // delete funcs:    //**************NEW***************\/UNDER HERE\/******!!!
        void annihilate();
        void annihilate(char);
        void annihilate(string);
        // search funcs:
        bool searchWord(string); // prints words beginning with the input
        bool generalSearch(string); // prints all words that have first two letters of what user inputted
};//end hashTable def

#endif
