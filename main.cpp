/** FILE:   main.cpp
    NAME:   Ibrahim Sardar
    PROJ:   Hashtable Dictionary

**/

#include <iostream>
#include <fstream>
#include <string>

#include "hashTable.h"
//#include "linkedList.h" -DON'T NEED THIS LINE
#include "hashTable.cpp"
#include "linkedList.cpp"

using namespace std;

int main(){

    // 1] hashtable
    //    - create
    //    - sort*optional
    //    - fill up

    // create new hashTable obj and send in "words.txt" file
    // the overloaded constructor of h should process "words.txt":
    //  - create struct and fill it up with the letters a through z cooresponding to the numbers 0 through 25 }}}} replace this with a hashing function (done.)
    //  - loop through all words in file:
    //      > find first letter of word and get cooresponding index (HASHING!)
    //      > insert the specific word to the linked list at the index of the vector

    hashTable h;
    cout << "Hash Table created." << endl;

    /*h.loadFile("words.txt");
    cout << "Hash Table loaded:  words3.txt" << endl;
    cout << "press any key to proceed to hash table testing..." << endl;
    cin.ignore();

    h.printTable();

    h.annihilate('t');
    cout << "Hash Table annihilated:  category t" << endl;

    h.printTable();

    h.annihilate();
    cout << "Hash Table annihilated:  all data" << endl;
    cout << "press any key to proceed to new hash table..." << endl;
    cin.ignore();
    */
    h.loadFile("words2.txt");
    cout << "Hash Table loaded:  words2.txt" << endl;
    cout << "press any key to proceed to hash table testing..." << endl;
    cin.ignore();
    /*
    h.printTable('a');

    h.annihilate("apple");
    cout << "Hash Table annihilated:  apple" << endl;*/

    h.printTable('a');


    // 2] user input*
    //    - test against hashtable
    //    - return True if words found, else False
    //    - print all words that begin with user's input
    h.searchWord("jaguar");
    cout<<"\n";
    h.generalSearch("j");
    cout<<"\n\n\n\n\n\n\n";
    h.annihilate();
    cout << "press any key to proceed to new hash table..." << endl;
    cin.ignore();



    h.loadFile("words3.txt"); cout<<"\n";
    cout << "press any key to proceed to hash table testing..." << endl;
    cin.ignore();

    h.searchWord("all");      cout<<"\n";
    h.generalSearch("all");   cout<<"\n";
    h.printTable('a');        cout<<"\n";



    return 0;
} // end main
