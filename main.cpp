/* ************************************************************************
Name: Michael Quintana
Assignment: Bonus 01 - Linked Stack
Purpose: Implementation - main
Notes: This is the main implementation file for the program
************************************************************************ */

#include "main.h"
int main() {
    srand (time(NULL)); //seeds the random function
    cout << boolalpha; //Sets boolean flags to print True/False
    /*
     * Variable Declaration
     */
    int id; // Holds id values
    string data[] = {"Pancakes", "Sausage", "Waffles", "Bacon", "Omelette", "Eggs Benedict", "French Toast",
                     "Crepes", "Hash", "Scrambled Eggs", "Hash Browns", "Corned beef Hash"}; //Data values. I coded this while waiting for breakfast
    StackedList stack; //Holds the new stack
    Node container; //creates a container node for use later

    //Ensures stack count is 0
    cout << "Current count: " << stack.count() << endl << endl;
    //Tests for adding nodes in best cases.
    cout << "Adding all nine stacks" << endl << "==================" << endl;
    for (int counter = 0; counter < 9; counter++){ //loop for adding
        id = randomInt();
        cout<< "ID : " << id << ", " << data[counter] //Tries to add a first header
            << " | Sucessfully added? " << stack.push(id, data[counter]) << " | Count: " << stack.count() << endl;
        container = stack.peek();
        cout << "Top of Stack -  " << container.id << ", " << container.data << endl;
    }
    //Adding to a full stack
    cout << endl << "Adding to a full stack"<< endl << "==================" << endl;
    try {
        id = randomInt();
        cout<< "ID : " << id << ", " << data[10] << endl;
        stack.push(id, data[10]);
        container = stack.peek();
        cout << "Top of Stack -  " << container.id << ", " << container.data << endl<< " | Count: " << stack.count() << endl << endl;;
    } catch (int error){
        cout << "Unable to add to stack. Error Code: " << error << endl;
    }

    //Popping all nine items from a stack
    cout << endl << "Popping items"<< endl << "==================" << endl;
    for (int counter = 1; counter < 10; counter++){ //loop for adding
        container = stack.peek();
        cout << "Loop " << counter << " | Top of Stack -  " << container.id << ", " << container.data
             << " | Count: " << stack.count() << endl;
        cout << "Popping the top of the stack..." << endl;
        container = stack.pop();
        cout << "Top of Stack -  " << container.id << ", " << container.data
                << " | Count: " << stack.count() << endl << endl;
    }

    //Popping from an empty stack
    cout << endl << "Popping from an empty stack"<< endl << "==================" << endl;
    try {
        container = stack.pop();
        cout << "Top of Stack -  " << container.id << ", " << container.data << endl;
    } catch (int error){
        cout << "Unable to remove due to an empty stack. Error Code: " << error << endl;
    }

    cout << "Now exiting..." << endl;
    return 0;
}