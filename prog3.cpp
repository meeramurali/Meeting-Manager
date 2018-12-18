//Filename: prog3.cpp

//Name:     Meera Murali
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "meeting_response.h"



//main function
int main()
{
    char name[] = "Meera Murali";
    char name2[] = "Dinesh Ganta";
    char name3[] = "Mahesh Iyer";
    char name4[] = "Shreyas Chander";
    char email[] = "meera@email.com";
    char email2[] = "dganta@gmail.com";
    char email3[] = "mahesh@email.com";
    char email4[] = "shreyas@email.com";
    contact A(name, email);
    contact B(name2, email2);
    contact C(name3, email3);
    contact D(name4, email4);
    group_contacts grp;
    group_contacts grp2;

    if (!A.display())
        cout << "Unable to display" << endl;

    if (!B.display())
        cout << "Unable to display" << endl;
/*    
    B = A;
    
    if (!B.display())
        cout << "Unable to display" << endl;
*/
    grp.add_contact(A);
    grp.add_contact(B);
    grp2.add_contact(C);
    grp2.add_contact(D);
    
    cout << "Group 1: " << endl;
    grp.display();
    cout << "Group 2: " << endl;
    grp2.display();

    group_contacts grp3(grp2);
    grp3 = grp3 + A;
    grp3 = grp3 + B;
    cout << "Group 3: " << endl;
    grp3.display();

    char meet[] = "Summer party";
    char loc[] = "My place";
    char d_t[] = "2017/08/01, 5:00 pm";
    char key[] = "parTY";
    char key2[] = "Party";
    meeting my_meet(meet, loc, d_t, key, grp3);
    meeting a_meet(meet, loc, d_t, key);
    
    cout << "New meeting: " << endl;
    my_meet.display();
    cout << "\nNew meeting: " << endl;
    a_meet.display();
    a_meet.add_contact(A);
    a_meet.add_contact(B);
    cout << "\nNew meeting: " << endl;
    a_meet.display();
    meeting meet3(my_meet);
    cout << endl << "Meet 3: " << endl;
    meet3.display();
    meet3 = a_meet;
    cout << "After assignment: " << endl;
    meet3.display();

    if (key2 < meet3)
        cout << "lesser than" << endl;

    if (key2 <= meet3)
        cout << "lesser than equal to" << endl;
    

/*
    B.set_contact(name, email2);

    if (A == B)
        cout << "A and B are equal" << endl;
    
    if (A != B)
        cout << "A and B are not equal" << endl;
    if (!B.display())
        cout << "Unable to display" << endl;

    contact_node N1(A);
    contact_node N2(B);
    
    if (N1 == N2)
        cout << "nodes equal" << endl;
    else
        cout << "nodes not equal" << endl;

    if (!N1.display())
        cout << "Unable to display" << endl;
*/    
    return 0;
}
