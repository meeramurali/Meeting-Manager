//Filename: prog3.cpp

//Name:     Meera Murali
//Email:    mmurali@pdx.edu
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "balanced_tree.h"



//main function
int main()
{
    char name[] = "Meera Murali";
    char name2[] = "Dinesh Ganta";
    char name3[] = "Mahesh Iyer";
    char name4[] = "Shreyas Chander";
    char email[] = "mmurali@pdx.edu";
    char email2[] = "dganta@pdx.edu";
    char email3[] = "mahesh@mit.edu";
    char email4[] = "shreyas@nitt.edu";
    char comm[] = "Cant wait!!";
    char meet[] = "Summer party";
    char loc[] = "My place";
    char d_t[] = "2017/08/01, 5:00 pm";
    char key[] = "parTY";
    char key2[] = "Party";
    char * nocomm = NULL;
    
    contact A(name, email);
    contact B(name2, email2);
    contact C(name3, email3);
    contact D(name4, email4);

    participant p1(A);
    participant p2(B, 2, comm);
    participant p3(C, 1, nocomm); 
    participant p4(D, 0, nocomm); 
//    p1 = p3;

    meeting grp(meet, loc, d_t, key);

    grp += p1;
    grp += p2;
    grp += p3;
    grp += p4;


    if (!p1.display())
        cout << "unable to display p1" << endl;
    cout << endl << endl;
    if (!p2.display())
        cout << "unable to display p2" << endl;
    cout << endl << endl;
    if (!p3.display())
        cout << "unable to display p3" << endl;

    cout << endl << endl;

    if (grp.add_response(email, 1, nocomm))
    {
        cout << "Group created: " << endl;
        if (!grp.display())
            cout << "unable to display grp" << endl;
    }

    return 0;
}
