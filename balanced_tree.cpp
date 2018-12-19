//Filename: balanced_tree.cpp

//Name:     Meera Murali
//Email:    mmurali@pdx.edu
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "balanced_tree.h"



//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
meeting_node::meeting_node(): next(NULL) {}



//Constructor with arguments
//INPUT: 1 argument: a contact object to copy
//OUTPUT: no return value
meeting_node::meeting_node(const meeting & to_copy): meeting(to_copy), next(NULL) {}



//Copy constructor
//INPUT: 1 argument: a meeting_node object to copy
//OUTPUT: no return value
meeting_node::meeting_node(const meeting_node & to_copy): meeting(to_copy), next(NULL) {}



//Returns the node's next pointer by reference
//INPUT: no arguments
//OUTPUT: node's next pointer by reference
meeting_node *& meeting_node::go_next(void)
{
    return next;
}



//Sets next pointer to point to same node as argument
//INPUT: 1 argument: location to set next pointer to 
//OUTPUT: no return value
void meeting_node::connect_next(meeting_node * connection)
{
    next = connection;   
    return;  
}
