///likedList.cpp
///By: Ibrahim Sardar

#include <iostream>
#include <string>
#include <algorithm>

#include "linkedList.h"

using namespace std;

// caps function prototype
string caps(string);

//class linkedList functions
linkedList::linkedList(){
    //constructor
    linkedList::head = NULL;

}//end constructor

void linkedList::printList(){
    // prints all nodes in organized fashion

    if (linkedList::head != NULL){
        // temporary node pointer
        // will use this like a current node
        node* tmp = linkedList::head;

        // while tmp's next is not null,
        // print tmp's word
        cout << tmp->word << endl;     // prints head node
        while (tmp->next != NULL) {
            tmp = tmp->next;
            cout << tmp->word << endl; // prints the rest of the nodes
        }//end loop
    }//end if

}//end printList

void linkedList::appendNode(string data){
    // Adds a node to the end of the linkedList
    // So the current last node should point to this node, and this node should point to NULL

    // if the word/data is not already in the linked list
    // we don't want duplicates
    if (linkedList::searchData(data) == -1) {

        // node pointer, store data in newNode
        node* newNode = new node;
        newNode->word = data;

        // if there is no head node, then make n the head node
        if (linkedList::head == NULL){
            linkedList::head = newNode; // make head point to newNode
            linkedList::head->next = NULL; // make the next node point to nothing
        }
        // if there is a head node,
        // then make the last node point to newNode,
        // and the newNode's next point to NULL
        else{

            // temporary node pointer
            // will use this like a current node
            node* tmp = new node;
            tmp = linkedList::head;

            // while tmp's next is not null,
            // set tmp to it's next.
            // This will get us to the end of the linkedList
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }//end

            // now we add our newNode to the end of the linkedList
            tmp->next     = newNode;
            newNode->next = NULL;

        }//end if
    }//end if

}//end appendNode

void linkedList::ejectNode(string data){
    // removes node from linked list

    // index of our data
    int index = linkedList::searchData(data);

    // if we want to "pop" the current head
    if (index == 0)
        linkedList::head = linkedList::head->next;
    // if we want to "pop" a node other than the current head
    else if (index > 0) {

        // declarations
        node* cur = linkedList::head; // just using 'cur' instead of 'tmp' here!

        // traverse through linked list to get
        // to the node behind the one we want to "pop"
        for (int x = 0;x < index-1;x++){
            cur = cur->next;
        }//end loop

        // saving the next node pointer as a pointer called nodeToDelete
        node* nodeToDelete = cur->next;

        //  ILLUSTRATION:
        //
        /// before: N0  ->  N1  ->  N2  ->  N3
        //
        /// after:  N0  ->  N1  ->  N3  <-  N2
        //
        //  N2 is basically lost forever because
        //  we cannot access what is pointing to N3
        //  and nothing is pointing to N2.
        //
        //  *the same situation is for N0, but we
        //   have saved that node as the "head"
        //
        cur->next = cur->next->next;

        // just cleaning up the ejected pointer
        delete nodeToDelete;       // deletes whatever nodeToDelete is pointing to
        nodeToDelete->next = NULL; // not really necessary
        nodeToDelete->word = "";   // not really necessary

    }else{
        cout << "no data found..." << endl;
    }//end if

} // end ejectNode

void linkedList::clearList(){
    // frees up all nodes via looping thru linked list

    // mark head for deletion
    node* del = linkedList::head;

    // while there is some node to delete
    while( del != NULL ){

        // traverse list
        linkedList::head = linkedList::head->next;
        // deletes whatever del is pointing at
        delete del;
        // mark new head for deletion
        del = linkedList::head;

    }//end loop

} // end clearList

int linkedList::searchData(string data){
    // returns index of where the input string is in the linkedList. not found returns -1
    bool kg = true;
    int counter = 0; // assume not found
    node* tmp = linkedList::head;

    // search for a result
    while (kg){
        // if not found
        if (tmp == NULL){
            kg = false;
            counter = -1;
        // if found
        }else if (tmp->word == data) {
            kg = false;
        }else{
            // increment counter and get next node
            counter = counter + 1;
            tmp = tmp->next;
        }//end if
    }//end loop

    return counter;

} // end searchData

bool linkedList::searchSimilarData(string data){
    // searches for nodes that have words that start with the input string and prints them
    // similar to our "searchData" function
    bool found = false;
    bool kg = true;
    int counter = 0;
    node* tmp = linkedList::head;

    cout<<"---------Ordinary Search Results:\n"<<endl;
    // search/print results
    while (kg){


        /* KEEP IN MIND:                      \\
        \\   string1.find(string2) returns    //
        //   the index of string2's starting  \\
        \\   position in string1.             */

        if (tmp == NULL){

            // to exit the loop
            kg = false;

        // If data is at the start of tmp's word (both strings are capitalized)
        }else if (caps(tmp->word).find(caps(data)) == 0) {

            // check if the search is exactly found
            if (caps(tmp->word) == caps(data))
                found = true;
            // print current node's word
            cout << tmp->word << endl;
            // increment counter
            counter = counter + 1;
            // traverse to next node
            tmp = tmp->next;

        }else{

            // traverse to next node
            tmp = tmp->next;

        }//end if


    }//end loop
    cout <<"\nSTATS: "<< counter << " results found." << endl;
    if (found)
        cout<<"STATS: \""<< data <<"\" was found."<<endl;
    else
        cout<<"STATS: \""<< data <<"\" was not found."<<endl;
    return found;

} // end searchSimilarData

bool linkedList::searchGeneralData(string data){
    // searches for words with 1st 2 letters of: word
    bool found = false;
    bool kg = true;
    int counter = 0;
    node* tmp = linkedList::head;

    cout<<"---------General Search Results:\n"<<endl;
    // search/print results
    while (kg){

        if (tmp == NULL){

            // to exit the loop
            kg = false;

        // If data is at the start of tmp's word (both strings are capitalized)
        }else if ( caps(tmp->word).substr(0,2)  ==  caps(data).substr(0,2) ){

            // check if the search is exactly found
            if (caps(tmp->word) == caps(data))
                found = true;
            // print current node's word
            cout << tmp->word << endl;
            // increment counter
            counter = counter + 1;
            // traverse to next node
            tmp = tmp->next;

        }else{

            // traverse to next node
            tmp = tmp->next;

        }//end if


    }//end loop
    cout <<"\nSTATS: "<< counter << " results found." << endl;
    if (found)
        cout<<"STATS: \""<< data <<"\" was found."<<endl;
    else
        cout<<"STATS: \""<< data <<"\" was not found."<<endl;
    return found;

}//end searchGeneralData

string caps(string word){
    // returns the capitalized version of the string
    transform(word.begin(), word.end(), word.begin(), ::toupper);

    return word;
}//end caps








/*
// testing harness
int main(){


    cout << "starting..." << endl;

    string foo = "fOooP";
    cout << caps(foo) << endl;

    linkedList chain;
    cout << "created linkList: chain" << endl;

    chain.appendNode("copper");
    chain.appendNode("iron");
    chain.appendNode("ironsteel");
    chain.appendNode("steelatron");
    chain.appendNode("Strong Metal");
    chain.appendNode("steel");
    chain.appendNode("steel");
    chain.appendNode("copper");
    cout << "finished appending to: chain" << endl;

    chain.printList();
    cout << "\nsteel index: " << chain.searchData("steel") << endl;

    cout << "\ndeleted copper:" << endl;
    chain.ejectNode("copper");
    chain.printList();

    cout << "\n\n\npart 2\n\n\n" << endl;

    chain.clearList();

    chain.printList();

    chain.appendNode("aaa");
    chain.appendNode("aab");
    chain.appendNode("aac");
    chain.appendNode("abb");
    chain.appendNode("abc");
    chain.appendNode("bbb");
    chain.appendNode("bbc");
    chain.appendNode("bcc");
    chain.appendNode("ccc");
    chain.appendNode("cca");
    chain.appendNode("cab");
    chain.appendNode("caa");

    chain.printList();

    cout << "\nsearch \"abcd\": " << endl;

    chain.searchSimilarData("abcd"); // 0 results

    cout << "\nsearch \"bc\": " << endl;

    chain.searchSimilarData("bc"); // 1 result

    cout << "\nsearch \"ab\": " << endl;

    chain.searchSimilarData("ab"); // 2 results

    cout << "\nsearch \"b\": " << endl;

    chain.searchSimilarData("b"); // 3 results

    cout << "\nsearch \"c\": " << endl;

    chain.searchSimilarData("c"); // 4 results

    cout << "\nsearch \"abc\": " << endl;

    chain.searchSimilarData("abc"); // 1 results

    cout << "program done." << endl;
    chain.clearList();

    return 0;
} // end main
*/

// Reference:---------------------------------------------------------------------
/*                    POINTERS WITH OBJECTS/STRUCTS CHART:
   /=====================================================================\
   | Expression  |What is evaluated	                        |Equivalent  |
   | - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |
   | a.b	     |Member b of object                        |a	         |
   | a->b	     |Member b of object pointed to by a	    |(*a).b      |
   | *a.b	     |Value pointed to by member b of object a  |*(a.b)      |
   \=====================================================================/
*/
// End Reference------------------------------------------------------------------

