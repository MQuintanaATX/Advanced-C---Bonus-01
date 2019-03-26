/* ************************************************************************
Name: Michael Quintana
Assignment: Bonus 01 - Linked Stack
Purpose: Header - Linked Stack
Notes: This header file defines functions used by the linked stack class
************************************************************************ */

#ifndef BONUS_01_LINKEDSTACK_H
#define BONUS_01_LINKEDSTACK_H
#include <iostream>
#include <string>
#include <cmath> //needed for the random function

using namespace std;
/*
 * Structure Definition
 */
struct Node {
    int id;
    string data;
    Node *next;
};

/*
* Class Definition
*/
class StackedList {
private:
    //variables
    int nodeCount;// holds the count of the nodes
    Node *firstptr, *topptr; //firstptr holds the location of the first stack, topptr is the last
    //methods
    void addFirst(Node*); //Takes care of adding the first node to a stack
    void addNode(Node*);
public:
    //methods
    StackedList(); //constructor; sets the firstptr & topptr to null and sets nodecount to 0
    bool push( int, string); //Adds a struct with id int and data string to the stack
    Node peek(); //Returns a struct from the top of the stack. DOes not remove it.
    Node pop(); //Returns a struct from the top of the stack. ***DOES*** remove
    int count(); // Returns the tally of nodes
    bool isEmpty(); //Tells if a stack is empty
};
#endif //BONUS_01_LINKEDSTACK_H
