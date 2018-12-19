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



//prototypes
void display_menu(char & choice);   //Displays textbased menu and reads user choice
void get_data(char * & dest);       //Gets data from the user and sizes
                                    //the argument array just right



//main function
int main()
{
    char menu_choice = 'a';  //user choice for menu operation
    rb_tree calendar;
    char * key_to_find = NULL;
    char * a_name = NULL;
    char * a_email = NULL;
    char * a_meeting_name = NULL;
    char * a_meeting_loc = NULL;
    char * a_meeting_datetime = NULL;
    char * a_meeting_key = NULL;
    contact * a_contact = NULL;
    participant * a_ppant = NULL;
    grp_part * a_grp = NULL;
    meeting * a_meeting = NULL;
    rb_node * match = NULL;
    meeting_node * to_respond = NULL;
    char * id_to_match = NULL;
    int an_intent = -1;
    char * a_comment = NULL;
    int sn_torespond = 1;
    char response = 'y';
    int meetings_loaded = 0;
    int result = 0;

    //Load meetings from external file
    meetings_loaded = calendar.load_file(FILENAME);
    cout << meetings_loaded << " meetings loaded from file" << endl;
  
 
    //Repeat until user wants to quit, i.e. menu choice is 'f' 
    do 
    {  
        //Display menu and get user choice 
        display_menu(menu_choice);
        
        //If choice is 'a', display all meetings
        //Prompt user accordingly based on result
        if (menu_choice == 'a')
        {
            result = calendar.display_inorder();
            cout << result << " keywords displayed" << endl;
        }
        
        //If choice is 'b', display all keywords
        //Prompt user accordingly based on result
        else if (menu_choice == 'b')
        {
            result = calendar.display_key_bylevels();
            cout << "\n\n" << result << " levels total" << endl;
        }
 
        //If choice is 'c', display meetings by keyword
        //Prompt user accordingly based on result
        else if (menu_choice == 'c')
        {
            cout << "Enter keyword to search for: ";
            get_data(key_to_find);
        
            result = calendar.display_by_keyword(key_to_find);
            cout << result << " matches found" << endl;

            delete [] key_to_find;
            key_to_find = NULL;   
        } 
        
        //If choice is 'd', post a new meeting
        //Prompt user accordingly based on result
        else if (menu_choice == 'd')
        {
            cout << "Enter meeting name: ";
            get_data(a_meeting_name);
            cout << "\nEnter meeting location: ";
            get_data(a_meeting_loc);
            cout << "\nEnter meeting date and time (e.g. Sept 20, 2017, 5:00 pm): ";
            get_data(a_meeting_datetime);
            cout << "\nEnter keyword for meeting (e.g. Eclipse): ";
            get_data(a_meeting_key);
            
            //Create a new group of participants to invite
            a_grp = new grp_part;

            do
            {
                cout << "\nEnter details for a person to invite: " << endl;
                cout << "Enter name: ";
                get_data(a_name);
                cout << "\nEnter email id: ";
                get_data(a_email);

                //Create new contact with read in info
                a_contact = new contact(a_name, a_email);

                //Create new participant
                a_ppant = new participant(*a_contact);

                //Add to group of participants
                *a_grp += (*a_ppant);

                //Reset temporary to read in next participant
                delete a_name;
                a_name = NULL;
                delete a_email;
                a_email = NULL;
                delete a_contact;
                a_contact = NULL;
                delete a_ppant;
                a_ppant = NULL;

                //Another participant?
                cout << "\nAdd another participant? Y/N: ";
                cin >> response;
                cin.ignore (100, '\n');
            }
            while (tolower(response) == 'y');

            //Create new meeting
            a_meeting = new meeting(a_meeting_name, a_meeting_loc, a_meeting_datetime, a_meeting_key, *a_grp);

            //Display meeting
            cout << "Meeting created: " << endl;
            if (!a_meeting->display())
                cout << "Unable to display meeting" << endl;

            //Insert meeting into tree
            if (calendar.insert(*a_meeting))
                cout << "\nMeeting posted!" << endl;

            //Delete temporary
            delete [] a_meeting_name;
            a_meeting_name = NULL;
            delete [] a_meeting_loc;
            a_meeting_loc = NULL;
            delete [] a_meeting_datetime;
            a_meeting_datetime = NULL;
            delete [] a_meeting_key;
            a_meeting_key = NULL;
            delete a_grp;
            a_grp = NULL;
            delete a_meeting;
            a_meeting = NULL;
        }

        //If choice is 'e', respond to a meeting
        //Prompt user accordingly based on result
        else if (menu_choice == 'e')
        {
            cout << "Finding meeting to respond to..." << endl;
            result = calendar.display_key_inorder();
            cout << "Enter keyword to search for: ";
            get_data(key_to_find);
        
            if (calendar.find_by_keyword(match, key_to_find))
            {
                //Display all matches for keyword
                result = match->display();
                cout << result << " matches found for keyword" << endl;

                //Read serial number of meeting to respond to
                cout << "\nEnter S/N of meeting to respond to (e.g. 1): ";
                cin >> sn_torespond;
                cin.ignore(100, '\n');

                if (match->find_meeting_by_position(to_respond, sn_torespond))
                {
                    //Read email id of person responding
                    cout << "\nEnter email id of person responding to meeting (e.g. joe@pdx.edu): ";
                    get_data(id_to_match);

                    //Read response
                    cout << "\nEnter intent (0 (No), 1 (Maybe), or 2 (Yes)): ";
                    cin >> an_intent;
                    cin.ignore(100, '\n');
                    cout << "\nEnter comments: ";
                    get_data(a_comment);

                    //Respond to meeting
                    result = to_respond->add_response(id_to_match, an_intent, a_comment);
                    if (result == 2)
                        cout << "*** Response added ***" << endl;
                    
                    else if (!result)
                        cout << "*** Cannot add response! Email id provided does not match any participant for this meeting ***" << endl;

                    else
                        cout << "*** Cannot add response! Invalid intent code (Must be 0 (No), 1 (Maybe) or 2(Yes)) ***" << endl;
                }

                else
                    cout << "*** Invalid S/N ***" << endl;
            }

            //Reset temporary 
            to_respond = NULL;           
            match = NULL;
            an_intent = -1;
            sn_torespond = 0;
             
            if (key_to_find)
            {
                delete [] key_to_find;
                key_to_find = NULL;   
            }
            
            if (a_comment)
            {
                delete [] a_comment;
                a_comment = NULL;   
            }

            if (id_to_match)
            {
                delete [] id_to_match;
                id_to_match = NULL;   
            }

        }
    }
    while (menu_choice != 'f'); 

    return 0;
}



//Display menu and get user choice
//INPUT: 1 argument: user choice (char array passed by reference)
//OUTPUT: Argument userchoice modified
void display_menu(char & choice)
{
    //Repeat until user chooses a valid menu option
    do
    {
        //Display menu of operations to user
        cout << "\n\nSelect operation:" << endl;
        cout << "a. Display all meetings" << endl
             << "b. Display all keywords" << endl
             << "c. Display meetings for a keyword" << endl
             << "d. Post a new meeting" << endl
             << "e. Respond to a meeting" << endl
             << "f. Quit" << endl
             << "Enter a letter from 'a' to 'f': ";

        //Read in user response
        cin >> choice;
        cin.ignore(100, '\n');

        //Convert to lowercase
        choice = tolower(choice);
        
        //If choice is invalid, prompt user
        if (!(choice >= 'a' && choice <= 'f'))
            cout << "\n\n***Invalid entry! Try again...***" << endl;
    }
    while (!(choice >= 'a' && choice <= 'f'));

    return;
}



//Gets data from the user and sizes the argument array just right
//INPUT: 1 argument: a char pointer passed by reference
//OUTPUT: modified argument array, return nothing
void get_data(char * & dest)
{
    char temp [100];    //Temporary array to read in data and size
                        //argument array just right

    //Read in data from user into temp
    cin.get(temp, 100, '\n');
    cin.ignore(100, '\n');

    //Allocate memory sized just right, based on contents of temp
    dest = new char [strlen(temp) + 1];

    //Copy data from temp
    strcpy(dest, temp);

    return;
}
