///linkedList.h
///By: Ibrahim Sardar

#ifndef LINKEDLIST_H_EXISTS
#define LINKEDLIST_H_EXISTS

#include <string>

using namespace std;

//class linkedList
class linkedList{
    private:

        // Instead of making a node class,
        // we can just quickly make a struct.
        struct node{
        // storage for a specific word
        string word;
        // The pointer "next" points to a reference of some "node"
        node* next;
        }; // end node

        //  You could do this if you wanted to
        //  type "nodePtr" instead of "node*":
        /// typedef struct node* nodePtr;


        // head is a pointer that points to some node
        node* head;


    public:
        linkedList();
        void printList();
        void appendNode(string);
        //void insertNode(string, int); // inserts node (data, position)
        void ejectNode(string); // deletes the node consisting of this(string) data ---> should be exactly 1 or 0 instances of every word
        void clearList(); // frees up all the nodes
        int searchData(string); // returns index of where the input string is in the linkedList. not found returns -1
        /*FIX*/bool searchSimilarData(string); // searches for nodes that have words that start with the input string
        /*FIX*/bool searchGeneralData(string); //************NEW!!!   // prints all words that have first two letters of what user inputted
}; // end linkedList def

#endif
