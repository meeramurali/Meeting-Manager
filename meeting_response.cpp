//Filename: meeting_response.cpp

//Name:     Meera Murali
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "meeting_response.h"



//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
contact::contact(): name(NULL), email(NULL) {}



//Constructor with arguments
//INPUT: 2 arguments: a name and email id
//OUTPUT: no return value
contact::contact(char * a_name, char * an_email)
{
    //Copy arguments into corresponding data members
    if (a_name)
    {
        name = new char [strlen(a_name) + 1];
        strcpy(name, a_name);
    }
    else
        name = NULL;

    if (an_email)
    {
        email = new char [strlen(an_email) + 1];
        strcpy(email, an_email);
    }
    else
        email = NULL;
}



//Copy constructor
//INPUT: 1 argument: a contact object to copy
//OUTPUT: no return value
contact::contact(const contact & to_copy)
{
    //Copy argument object's data members into 
    //corresponding data members
    if (to_copy.name)
    {
        name = new char [strlen(to_copy.name) + 1];
        strcpy(name, to_copy.name);
    }
    else
        name = NULL;

    if (to_copy.email)
    {
        email = new char [strlen(to_copy.email) + 1];
        strcpy(email, to_copy.email);
    }
    else
        email = NULL;
}



//Destructor - releases all dynamic memory
//INPUT: no arguments
//OUTPUT: no return value
contact::~contact()
{
    if (name)
    {
        delete [] name;
        name = NULL;
    }

    if (email)
    {
        delete [] email;
        email = NULL;
    }
}



int contact::copy_contact(const contact & to_copy)
{
    int success = 0;    //number of data members copied

    //Delete any existing data in data members
    if (name)
    {
        delete [] name;
        name = NULL;
    }

    if (email)
    {
        delete [] email;
        email = NULL;
    }

    //Copy argument object's data members into 
    //corresponding data members
    if (to_copy.name)
    {
        name = new char [strlen(to_copy.name) + 1];
        strcpy(name, to_copy.name);
        ++success;
    }
    
    if (to_copy.email)
    {
        email = new char [strlen(to_copy.email) + 1];
        strcpy(email, to_copy.email);
        ++success;
    }

    return success;
}



//Displays contact details
int contact::display(void) const
{
    //Null data members
    if (!name || !email)
        return 0;

    //Display name and email id
    cout << "\t" << name << " | " << email << endl;
   
    return 1; 
}



//Copies argument values into data members
//INPUT: 2 arguments: a name and an email to copy
//OUTPUT: return type: int (0: failure - null arguments, 
//1: success)
int contact::set_contact(char * a_name, char * an_email)
{
    //Null arguments
    if (!a_name || !an_email)
        return 0;

    //Delete any existing data in data members
    if (name)
    {
        delete [] name;
        name = NULL;
    }
    if (email)
    {
        delete [] email;
        email = NULL;
    }

    //Copy arguments into corresponding data members
    name = new char [strlen(a_name) + 1];
    strcpy(name, a_name);
    email = new char [strlen(an_email) + 1];
    strcpy(email, an_email);

    return 1;
}



//Assignment operator overloading
contact& contact::operator = (const contact & to_copy)
{
    //If argument is not the same as the current object
    if (this != &to_copy)
    {
        //Copy argument data members
        if (!copy_contact(to_copy))
            name = email = NULL;
    }
    
    return *this;
}



//Equality (==) operator overloading
bool contact::operator == (const contact & to_compare) const
{
    bool name_equal = false;        //Flag if names are equal
    bool email_equal = false;       //Flag if email ids are equal
   
    //If name data members are not null... 
    if (name && to_compare.name)
    {
        //If same, set flag to true
        if (strcmp(name, to_compare.name) == 0)
            name_equal = true;
    }
   
    //Otherwise if both name data members are null,
    //set flag to true 
    else if (!name && !to_compare.name)
        name_equal = true;
    
    //If email data members are not null... 
    if (email && to_compare.email)
    {
        //If same, set flag to true
        if (strcmp(email, to_compare.email) == 0)
            email_equal = true;
    }
    
    //Otherwise if both email data members are null,
    //set flag to true 
    else if (!email && !to_compare.email)
        email_equal = true;

    //If all data members are equal, return true
    if (name_equal && email_equal)
        return true;

    //Otherwise, return false
    else
        return false;
}



//Equality (!=) operator overloading
bool contact::operator != (const contact & to_compare) const
{
    //If all data members are equal, return false
    if (operator == (to_compare))
        return false;

    //Otherwise, return true
    else
        return true;
}


/*
//Insertion (<<) operator overloading
ostream& operator << (ostream& ouput, const contact& object)
{
    output << object.display();
    return output; 
}
*/



//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
contact_node::contact_node(): next(NULL) {}



//Constructor with arguments
//INPUT: 1 argument: a contact object to copy
//OUTPUT: no return value
contact_node::contact_node(const contact & to_copy): contact(to_copy), next(NULL) {}



//Copy constructor
//INPUT: 1 argument: a contact_node object to copy
//OUTPUT: no return value
contact_node::contact_node(const contact_node & to_copy): contact(to_copy), next(NULL) {}




//Returns the node's next pointer by reference
//INPUT: no arguments
//OUTPUT: node's next pointer by reference
contact_node *& contact_node::go_next(void)
{
    return next;
}



//Sets next pointer to point to same node as argument
//INPUT: 1 argument: location to set next pointer to 
//OUTPUT: no return value
void contact_node::connect_next(contact_node * connection)
{
    next = connection;   
    return;  
}



//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
group_contacts::group_contacts(): head(NULL) {}



//Copy constructor
//INPUT: 1 argument: an object to copy
//OUTPUT: no return value
group_contacts::group_contacts(const group_contacts & to_copy)
{
    head = NULL;

    //Copy argument object
    if (!copy_group(to_copy))
        head = NULL;
}



//Destructor - releases all dynamic memory
//INPUT: no arguments
//OUTPUT: no return value
group_contacts::~group_contacts()
{
    if (remove_all(head))
        head = NULL;
}



//Removes all nodes in LLL recursively
//INPUT: 1 argument: head pointer to LLL passed by reference
//OUTPUT: return type: int (no of nodes removed)
int group_contacts::remove_all(contact_node * & head)
{
    int removed = 0;    //Number of nodes removed

    //base case
    if (!head)
        return 0;
    
    //recursive call
    removed+= remove_all(head->go_next());

    //delete node post recursion
    delete head;
    
    return ++removed;
}



//Wrapper - Copies a group of contacts
//INPUT: 1 argument: a group_contacts object to copy
//OUTPUT: return type: int (number of nodes copied)
int group_contacts::copy_group(const group_contacts & to_copy)
{
    //Delete any existing data
    if (head)
    {
        if (remove_all(head))
            head = NULL;
    }

    return copy_group(head, to_copy.head);
}



//Copies a group of contacts recursively
//INPUT: 2 arguments: destination list head pointer, source head pointer
//OUTPUT: return type: int (number of nodes copied)
int group_contacts::copy_group(contact_node * & dest, contact_node * src)
{
    int copied = 0;     //number of nodes copied

    //base case
    if (!src)
    {
        dest = NULL;
        return 0;
    }

    //copy current node
    dest = new contact_node(*src);
    ++copied;

    //recursive call
    copied += copy_group(dest->go_next(), src->go_next());

    return copied; 
}



//Adds a new node to beginning of list
//INPUT: 1 argument: a contact object to add
//OUTPUT: return type: int (0/1 - failure/success)
int group_contacts::add_contact(const contact & to_add)
{
    contact_node * temp = NULL; //temporary pointer to 
                                //create new node
    int success = 0;

    //Create new node
    temp = new contact_node(to_add);

    //base case - empty list
    if (!head)
    {
        head = temp;
        return ++success;
    }

    //otherwise, insert at beginning of list
    temp->connect_next(head);
    head = temp;
    return ++success; 
}



//Wrapper - Displays all contacts in list
//INPUT: no arguments
//OUTPUT: return type: int (no. of nodes displayed)
int group_contacts::display(void) const
{
    return display(head);
}



//Displays all contacts in list recursively
//INPUT: 1 argument: head pointer 
//OUTPUT: return type: int (no. of nodes displayed)
int group_contacts::display(contact_node * head) const
{
    int displayed = 0;  //number of nodes displayed

    //base case
    if (!head)
        return 0;

    //display current node
    if (head->display())
        ++displayed;

    //recursive call to display next node
    displayed += display(head->go_next());

    return displayed;
}


/*
//Appends a copy of argument list to current list
int group_contacts::concatenate(const group_contacts & a_grp)
{
    
    return concatenate(head, a_grp.head);
}



int group_contacts::concatenate(contact_node * & head, contact_node * & to_attach)
{
    //base case
    
}
*/


group_contacts& group_contacts::operator = (const group_contacts & to_copy)
{
    //If argument is not the same as the current object
    if (this != &to_copy)
    {
        //Copy argument into current object
        if (!copy_group(to_copy));
    }
    
    return *this;
}



group_contacts operator + (const group_contacts & a_grp, const contact & to_add)
{
    group_contacts temp(a_grp);

    temp.add_contact(to_add);
        return temp; 
}



group_contacts operator + (const contact & to_add, const group_contacts & a_grp)
{
    group_contacts temp(a_grp);

    if (temp.add_contact(to_add));

    return temp; 
}



//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
meeting::meeting(): meeting_name(NULL), location(NULL), day_time(NULL), keyword(NULL) {}



//Constructor with arguments
//OUTPUT: no return value
meeting::meeting(char * a_meeting_name, char * a_location, char * a_day_time, char * a_keyword)
{
    int a_key_len = 0;  //argument key length
    char default_key[] = "unassigned";  //default keyword if argument key is NULL

    //Set meeting name
    if (a_meeting_name)
    {
        meeting_name = new char [strlen(a_meeting_name) + 1];
        strcpy(meeting_name, a_meeting_name);
    }
    else
        meeting_name = NULL;

    //Set location
    if (a_location)
    {
        location = new char [strlen(a_location) + 1];
        strcpy(location, a_location);
    }
    else
        location = NULL;

    //Set day and time
    if (a_day_time)
    {
        day_time = new char [strlen(a_day_time) + 1];
        strcpy(day_time, a_day_time);
    }
    else
        day_time = NULL;

    //Set keyword
    if (a_keyword)
    {
        //Convert to lower case and copy into data member
        a_key_len = strlen(a_keyword);
        keyword = new char [a_key_len + 1];
        for (int i = 0; i < a_key_len; ++i)
            keyword[i] = tolower(a_keyword[i]);
        keyword[a_key_len] = '\0';
    }
    else
    {
        keyword = new char [strlen(default_key) + 1];
        strcpy(keyword, default_key);
    }
}



//Constructor with arguments
//OUTPUT: no return value
meeting::meeting(char * a_meeting_name, char * a_location, char * a_day_time, char * a_keyword, const group_contacts & a_grp): group_contacts(a_grp)
{
    int a_key_len = 0;  //argument key length
    char default_key[] = "unassigned";  //default keyword if argument key is NULL

    //Set meeting name
    if (a_meeting_name)
    {
        meeting_name = new char [strlen(a_meeting_name) + 1];
        strcpy(meeting_name, a_meeting_name);
    }
    else
        meeting_name = NULL;

    //Set location
    if (a_location)
    {
        location = new char [strlen(a_location) + 1];
        strcpy(location, a_location);
    }
    else
        location = NULL;

    //Set day and time
    if (a_day_time)
    {
        day_time = new char [strlen(a_day_time) + 1];
        strcpy(day_time, a_day_time);
    }
    else
        day_time = NULL;

    //Set keyword
    if (a_keyword)
    {
        //Convert to lower case and copy into data member
        a_key_len = strlen(a_keyword);
        keyword = new char [a_key_len + 1];
        for (int i = 0; i < a_key_len; ++i)
            keyword[i] = tolower(a_keyword[i]);
        keyword[a_key_len] = '\0';
    }
    else
    {
        keyword = new char [strlen(default_key) + 1];
        strcpy(keyword, default_key);
    }
}



//Copy constructor
meeting::meeting(const meeting & to_copy): group_contacts(to_copy)
{
    int a_key_len = 0;  //argument key length
    char default_key[] = "unassigned";  //default keyword if argument key is NULL

    //Copy meeting name
    if (to_copy.meeting_name)
    {
        meeting_name = new char [strlen(to_copy.meeting_name) + 1];
        strcpy(meeting_name, to_copy.meeting_name);
    }
    else
        meeting_name = NULL;

    //Copy location
    if (to_copy.location)
    {
        location = new char [strlen(to_copy.location) + 1];
        strcpy(location, to_copy.location);
    }
    else
        location = NULL;

    //Copy day and time
    if (to_copy.day_time)
    {
        day_time = new char [strlen(to_copy.day_time) + 1];
        strcpy(day_time, to_copy.day_time);
    }
    else
        day_time = NULL;

    //Copy keyword
    if (to_copy.keyword)
    {
        //Convert to lower case and copy into data member
        a_key_len = strlen(to_copy.keyword);
        keyword = new char [a_key_len + 1];
        for (int i = 0; i < a_key_len; ++i)
            keyword[i] = tolower(to_copy.keyword[i]);
        keyword[a_key_len] = '\0';
    }
    else
    {
        keyword = new char [strlen(default_key) + 1];
        strcpy(keyword, default_key);
    }
}



//Destructor - releases all dynamic memory
//INPUT: no arguments
//OUTPUT: no return value
meeting::~meeting()
{
    if (meeting_name)
    {
        delete [] meeting_name;
        meeting_name = NULL;
    }
    
    if (location)
    {
        delete [] location;
        location = NULL;
    }

    if (day_time)
    {
        delete [] day_time;
        day_time = NULL;
    }

    if (keyword)
    {
        delete [] keyword;
        keyword = NULL;
    }
}



//Displays meeting information
//INPUT: no arguments
//OUTPUT: return type: int (number of participants)
int meeting::display(void) const
{
    int num_part = 0;   //number of participants

    cout << "Name: " << meeting_name << endl;
    cout << "Location: " << location << endl;
    cout << "Day, time: " << day_time << endl;
    cout << "Keyword: " << keyword << endl;
    cout << "Participants: " << endl;
    num_part = group_contacts::display();
    if (!num_part)
        cout << "\tNone" << endl;

    return num_part;
}



//Copies meeting information
int meeting::copy_meeting(const meeting & to_copy)
{
    //Delete any existing data
    if (meeting_name)
    {
        delete [] meeting_name;
        meeting_name = NULL;
    }
    
    if (location)
    {
        delete [] location;
        location = NULL;
    }

    if (day_time)
    {
        delete [] day_time;
        day_time = NULL;
    }

    if (keyword)
    {
        delete [] keyword;
        keyword = NULL;
    }

    //Copy data members of argument object...
    //Copy meeting name
    if (to_copy.meeting_name)
    {
        meeting_name = new char [strlen(to_copy.meeting_name) + 1];
        strcpy(meeting_name, to_copy.meeting_name);
    }

    //Copy location
    if (to_copy.location)
    {
        location = new char [strlen(to_copy.location) + 1];
        strcpy(location, to_copy.location);
    }

    //Copy day and time
    if (to_copy.day_time)
    {
        day_time = new char [strlen(to_copy.day_time) + 1];
        strcpy(day_time, to_copy.day_time);
    }

    //Copy keyword
    if (to_copy.keyword)
    {
        keyword = new char [strlen(to_copy.keyword) + 1];
        strcpy(keyword, to_copy.keyword);
    }
    
    //Copy group of contacts
    return copy_group(to_copy);
}



//Compares keyword with argument
int meeting::check_key(char * a_key) const
{
    int result = 0;     //value to return
    int a_key_len = 0;  //argument key length
    char * a_key_lower = NULL;  //to convert to lower case

    if (!a_key)
        return 0;
   
    //Convert to lower case
    a_key_len = strlen(a_key);
    a_key_lower = new char [a_key_len + 1];
    for (int i = 0; i < a_key_len; ++i)
        a_key_lower[i] = tolower(a_key[i]);
    a_key_lower[a_key_len] = '\0';
 
    result = strcmp(a_key_lower, keyword);

    //Delete temporary memory
    if (a_key_lower)
    {
        delete [] a_key_lower;
        a_key_lower = NULL;
    }

    if (!result)
        return 1;

    else if (result < 0)
        return 2;

    else
        return 3;
}



//Assignment operator overloading
meeting& meeting::operator = (const meeting & to_copy)
{
    //If argument is not the same as the current object
    if (this != &to_copy)
    {
        //Copy argument into current object
        if (!copy_meeting(to_copy))
            head = NULL;
    }
    
    return *this;
}



//Equality (==) operator overloading
bool operator == (const meeting & a_meet, char * key)
{
    if (a_meet.check_key(key) == 1)
        return true;

    else
        return false;
}



//Equality (==) operator overloading
bool operator == (char * key, const meeting & a_meet)
{
    if (a_meet.check_key(key) == 1)
        return true;

    else
        return false;
}




//Equality (!=) operator overloading
bool operator != (const meeting & a_meet, char * key)
{
    if (a_meet.check_key(key) != 1)
        return true;

    else
        return false;
}



//Equality (!=) operator overloading
bool operator != (char * key, const meeting & a_meet)
{
    if (a_meet.check_key(key) != 1)
        return true;

    else
        return false;
}



//Relational operator (<) overloading
bool operator < (const meeting & a_meet, char * key)
{
    if (a_meet.check_key(key) == 2)
        return true;

    else
        return false;
}



//Relational operator (<) overloading
bool operator < (char * key, const meeting & a_meet)
{
    if (a_meet.check_key(key) == 2)
        return true;

    else
        return false;
}



//Relational operator (>) overloading
bool operator > (const meeting & a_meet, char * key)
{
    if (a_meet.check_key(key) == 3)
        return true;

    else
        return false;
}



//Relational operator (>) overloading
bool operator > (char * key, const meeting & a_meet)
{
    if (a_meet.check_key(key) == 3)
        return true;

    else
        return false;
}



//Relational operator (<=) overloading
bool operator <= (const meeting & a_meet, char * key)
{
    int compare = 0;

    compare = a_meet.check_key(key);
    
    if (compare == 1 || compare == 2)
        return true;
    
    else 
        return false;
}



//Relational operator (<=) overloading
bool operator <= (char * key, const meeting & a_meet)
{
    int compare = 0;

    compare = a_meet.check_key(key);
    
    if (compare == 1 || compare == 2)
        return true;
    
    else 
        return false;
}



//Relational operator (>=) overloading
bool operator >= (const meeting & a_meet, char * key)
{
    int compare = 0;

    compare = a_meet.check_key(key);
    
    if (compare == 1 || compare == 3)
        return true;
    
    else 
        return false;
}



//Relational operator (>=) overloading
bool operator >= (char * key, const meeting & a_meet)
{
    int compare = 0;

    compare = a_meet.check_key(key);
    
    if (compare == 1 || compare == 3)
        return true;
    
    else 
        return false;
}

