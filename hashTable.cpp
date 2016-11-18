///hashTable.cpp
///By: Ibrahim Sardar

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>

#include "hashTable.h"
#include "linkedList.h"

using namespace std;

//class hashTable functions
hashTable::hashTable(){
    //constructor
    hashTable::init_hashTable();

}//end constructor

hashTable::hashTable(string fileName){
    cout << "constructor overload invoked." << endl;
    //overloaded constructor
    hashTable::init_hashTable();
    hashTable::loadFile(fileName);

}//end overloaded constructor

void hashTable::init_hashTable(){
    // general inializations

    // add a linkedList to the vector for each english letter
    for (int i = 0;i < 26;i++)
        hashTable::hTable.push_back( linkedList() );

}//end init_hashTable

int hashTable::getIndex(string word){
    //gets index for hTable

    // Returns ascii integer value of capitalized
    // 1st letter minus ascii value of 'A'.
    return toupper( word[0] ) - 65;

}//end getIndex

int hashTable::getIndex(char letter){
    //gets index for hTable

    // Returns ascii integer value of capitalized
    // letter minus ascii value of 'A'.
    return toupper( letter ) - 65;

}//end overloaded getIndex

char hashTable::getCharFromIndex(int index){
    // gets corresponding letter from index in hTable vector

    // returns ascii char converted from its integer value
    // casting char to int
    // char will be lower case
    return tolower( (char)(index + 65) );

}//end getCharFromIndex

void hashTable::loadFile(string fileName){
    // loads words by line from file: fileName

    // holds number of lines in file
    int lines = 0;

    // our token
    string token;

    // input file stream
    ifstream file;
    file.open( fileName.c_str() );

    // while not at endOfFile; also token gets current line/word
    while ( getline(file, token) ){

        // count a line
        lines = lines + 1;

        // if line is not empty
        if (token != ""){
            cout<<"inserting word: "<< token <<endl;
            // insert word into hashtable
            hashTable::insertWord(token);
        }//end if

    } // end while

    // output number of lines in file
    cout<< lines <<" number of lines in file"<<endl;

}//end loadFile

void hashTable::insertWord(string word){
    // Appends word to a LinkedList of cooresponding
    // hash code position in the hTable (a=0,b=1,...,z=25).

    // get index for LL in hTable
    int hashCode = hashTable::getIndex(word);

    // adding the word to our chosen linkedList
    hashTable::hTable[ hashCode ].appendNode(word);

    /* TAKE NOTE:                               //
    \\      hTable[hashCode] is a specific      \\
    //      linked list from the hTable vector  */

}//end insertWord

void hashTable::printTable(){
    // print hash table's data

    // organize data by catagories: english alphabets
    for (int i = 0;i < 26;i++){
        cout<<"\n---Category "<< hashTable::getCharFromIndex(i) <<"---\n"<<endl;
        // prints all words under this category:
        hashTable::hTable[i].printList();

    }//end vector loop
    cout<<"\n===End of Table."<<"===\n"<<endl;
}//end printTable

void hashTable::printTable(char category){
    // print hash table's data

    cout<<"\n---Category "<< category <<"---\n"<<endl;
    // prints all words under this category:
    hashTable::hTable[ getIndex(category) ].printList();
    cout<<"\n===End of Category "<< category <<"===\n"<<endl;

}//end overloaded printTable

void hashTable::annihilate(){ //*****************************************NEW FUNCTIONS BELOW!!!!!!!!!!!!!!*******************
    // deletes all data in the hTable vector by element
    // this instead of vector.clear() to avoid memory leak
    for(int i = 0;i < 26;i++){
        hTable[i].clearList();
    }//end loop

}//end annihilate

void hashTable::annihilate(char category){
    // deletes all words starting with: category
    hashTable::hTable[ getIndex(category) ].clearList();

}//end overloaded annihilate

void hashTable::annihilate(string word){
    // deletes one word from our hash table

    // get index for LL in hTable
    int hashCode = hashTable::getIndex(word);

    // ejecting the word from our chosen linkedList
    hashTable::hTable[ hashCode ].ejectNode(word);

}//end overloaded(2) annihilate

bool hashTable::searchWord(string word){
    // searches words beginning with the input

    // get index for LL in hTable
    int hashCode = hashTable::getIndex(word);

    // searching the words containing: word, from our chosen linkedList
    return hashTable::hTable[ hashCode ].searchSimilarData(word);

}//end searchWord

bool hashTable::generalSearch(string phrase){
    // Prints all words that have first
    // two letters of what user inputted.

    // get index for LL in hTable
    int hashCode = hashTable::getIndex(phrase);

    // searching the words containing first 2 letters of: phrase, from our chosen linkedList
    return hashTable::hTable[ hashCode ].searchGeneralData(phrase);

}//end generalSearch









/*
// testing harness...
int main(){

    hashTable tbl("words.txt");

    return 0;
}//end main
*/
