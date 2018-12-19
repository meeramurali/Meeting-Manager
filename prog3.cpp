//Filename: prog3.cpp

//Name:     Meera Murali
//Email:    mmurali@pdx.edu
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "balanced_tree.h"



//constants
const char FILENAME[] = "calendar.txt";     //Filename to load data from

//main function
int main()
{
    rb_tree calendar;
    int added = calendar.load_file(FILENAME);
    cout << added << " meetings loaded from file" << endl;
   
    return 0;
}
