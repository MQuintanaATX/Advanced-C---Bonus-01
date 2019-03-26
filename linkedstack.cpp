/* ************************************************************************
Name: Michael Quintana
Assignment: Bonus 01 - Linked Stack
Purpose: Header - main
Notes: This  file contains the implementation for Linked Stack
************************************************************************ */
#include "linkedstack.h"
/*
 * Class Implementation
 */
StackedList::StackedList() { //Constructor
    //Set node count to 0, and sets both pointers to null
    nodeCount = 0;
    firstptr = nullptr;
    topptr = nullptr;
}

bool StackedList::push(const int id, const string data){
    //Checks to see if the Stack is full
    if (nodeCount >= 9){throw 9;}
    //Create a new temp node and load it with the data, and a finder
    Node *temp = new Node;
    temp->id = id;
    temp->data = data;
    temp->next = nullptr;
    //Checks to see if the list is empty by checking first ptr, and adds the first node
    if (firstptr == nullptr){addFirst(temp);return true;}
    //Adds a node to the list, if there already is a first one
    else {addNode(temp); return true;}
}

void StackedList::addFirst(Node *temp) { //Handles the first step of adding a node
    //Change the first and top pointers to temp's address
    firstptr = temp;
    topptr = temp;
    //Increment node count
    nodeCount++;
    return;
}

void StackedList::addNode(Node *temp) {
    //Makes this node's next pointer equal to top
    temp->next = topptr;
    //sets the top ptr to this container
    topptr = temp;
    //increments NodeCount
    nodeCount++;
    return;
}

Node StackedList::pop(){
    //Checks if it's empty
    if (nodeCount==0) {throw 0;}
    //Creates a container
    Node *temp = new Node;
    //Takes care of the cases where there's only one node
    if (nodeCount == 1) {
        temp = firstptr;
        topptr = nullptr;
        firstptr = nullptr;
        nodeCount--;
        return *temp;
    }
    //Sets the topptr to it's next value
    topptr = topptr->next;
    //Sets temp to the same address as the top
    temp = topptr;

    //Decrement node count
    nodeCount--;
    return *temp;
}

Node StackedList::peek(){
    //Checks if it's empty
    //if (nodeCount==0) {throw 0;}
    //Creates a container
    Node *temp = new Node;
    //Sets temp to the same address as the top
    temp = topptr;

    //Return the container at the top of the stack
    return *temp;
}

int StackedList::count() {
    return nodeCount;
}