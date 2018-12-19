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
    rb_tree calendar;
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

    int num = 0;
    if (calendar.insert(grp))
       num = calendar.display_inorder();
    cout << endl << num << " meetings in calendar" << endl;

/*
    group_contacts grp;
    group_contacts grp2;

    if (!A.display())
        cout << "Unable to display" << endl;

    if (!B.display())
        cout << "Unable to display" << endl;
    B = A;
    
    if (!B.display())
        cout << "Unable to display" << endl;
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
    char comm[] = "Cant wait!!";
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
