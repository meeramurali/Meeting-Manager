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



//Destructor - releases all dynamic memory
//INPUT: no arguments
//OUTPUT: no return value
rb_node::~rb_node()
{
    if (key)
    {
        delete [] key;
        key = NULL;
    }

    if (head)
    {
        if (remove_all(head))
            head = NULL;
    }
}



//Removes all nodes recursively
//INPUT: head pointer to list
//OUTPUT: number of nodes removed
int rb_node::remove_all(meeting_node *& head)
{
    int removed = 0;    //value to return

    //base case
    if (!head)
        return 0;

    //recursive call
    removed += remove_all(head->go_next());

    //delete current node
    delete head;
    head = NULL;
    ++removed;

    return removed;    
}



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




//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
rb_node::rb_node(): key(NULL), head(NULL), color(RED), left(NULL), right(NULL), parent(NULL) {}



//Constructor with argument
//INPUT: 1 argument: a keyword
//OUTPUT: no return type
rb_node::rb_node(char * a_key): head(NULL), color(RED), left(NULL), right(NULL), parent(NULL) 
{
    int key_len = 0;                    //length of keyword
    char default_key[] = "unassigned";  //default keyword if argument key is NULL

    //If argument is not NULL
    if (a_key)
    {
        //Allocate memory for keyword and copy argument
        key_len = strlen(a_key);        
        key = new char [key_len + 1];
        strcpy(key, a_key);

        //convert to lower case
        for (int i = 0; i < key_len; ++i)
            key[i] = tolower(key[i]);
    }

    //If null, set key as "unassigned"
    else
    {
        key = new char [strlen(default_key) + 1];
        strcpy(key, default_key);
    }
}



//Constructor with argument
//INPUT: 1 argument: a meeting object to add to list
//OUTPUT: no return type
rb_node::rb_node(const meeting & to_add): key(NULL), head(NULL), color(RED), left(NULL), right(NULL), parent(NULL)
{
    //copy keyword
    if (to_add.get_key(key))
    {
        //insert meeting into list
        if (!add_meeting(to_add))
            head = NULL;
    }    
}



//Returns the node's left pointer by reference
//INPUT: no arguments
//OUTPUT: node's left pointer by reference
rb_node *& rb_node::go_left(void)
{
    return left;
}



//Returns the node's right pointer by reference
//INPUT: no arguments
//OUTPUT: node's right pointer by reference
rb_node *& rb_node::go_right(void)
{
    return right;
}



//Returns the node's parent pointer by reference
//INPUT: no arguments
//OUTPUT: node's parent pointer by reference
rb_node *& rb_node::go_parent(void)
{
    return parent;
}



//Sets left pointer to point to same node as argument
//INPUT: 1 argument: location to set left pointer to 
//OUTPUT: no return value
void rb_node::connect_left(rb_node * connection)
{
    left = connection;
}



//Sets right pointer to point to same node as argument
//INPUT: 1 argument: location to set right pointer to 
//OUTPUT: no return value
void rb_node::connect_right(rb_node * connection)
{
    right = connection;
}



//Sets parent pointer to point to same node as argument
//INPUT: 1 argument: location to set parent pointer to 
//OUTPUT: no return value
void rb_node::connect_parent(rb_node * connection)
{
    parent = connection;
}



//Checks if color of node is red
//INPUT: no arguments
//OUTPUT: return type: bool (true if red, false if black)
bool rb_node::is_red(void) const
{
    if (color == RED)
        return true;

    else
        return false;
}



//Checks if key data member is lesser alphabetically 
//than argument's keyword
//INPUT: 1 argument: a meeting object to compare
//OUTPUT: bool return type (true: node key is lesser, false: otherwise)
bool rb_node::is_lesser(const meeting & to_compare) const
{
    if (key < to_compare)
        return true;
    
    else
        return false;
}



//Checks if key data member is equal to argument's keyword
//INPUT: 1 argument: a meeting object to compare
//OUTPUT: bool return type (true: keywords match, false: otherwise)
bool rb_node::is_equal(const meeting & to_compare) const
{
    if (key == to_compare)
        return true;
    
    else
        return false;
}



//Checks if key data member is lesser alphabetically 
//than argument keyword
//INPUT: 1 argument: a meeting object to compare
//OUTPUT: bool return type (true: node key is lesser, false: otherwise)
bool rb_node::is_lesser(char * to_compare) const
{
    bool result = false;            //value to return 

    if(to_compare)
    {
        //compare with key data member
        if(strcmp(key, to_compare) < 0)
            result = true;
    }

    return result;
}



//Checks if key data member is equal to argument keyword
//INPUT: 1 argument: a meeting object to compare
//OUTPUT: bool return type (true: keywords match, false: otherwise)
bool rb_node::is_equal(char * to_compare) const
{
    bool result = false;

    if(to_compare)
    {
        if(strcmp(key, to_compare) == 0)
            result = true;
    }

    return result;
}



//Displays keyword and all meetings in list
//INPUT: no arguments
//OUTPUT: int return type (number of meetings in list)
int rb_node::display(void) const
{
    int num_meetings = 0;   //value to return 
    int count = 0;

    //Display node color
    if (color == RED)
        cout << "(R) ";
    else
        cout << "(B) ";

    //Display keyword
    cout << "KEYWORD: " << key << endl;
    cout << "***********************************************************************************************" << endl;

    //Display all meetings in list
    num_meetings = display_all(head, count);

    if (!num_meetings)
        cout << "\tNo meetings to display" << endl;

    else
        cout << "*** " << num_meetings << " meetings found ***" << endl;

    cout << "***********************************************************************************************" << endl;
    return num_meetings;
}



//Displays keyword for node
//INPUT: no arguments
//OUTPUT: int (0/1 - failure/success)
int rb_node::display_key(void) const
{
    if (!key)
        return 0;
    
    //Display node color
    if (color == RED)
        cout << "(R) ";
    else
        cout << "(B) ";

    cout << "'" << key << "'" << "\t";

    return 1;
}


    
//Displays all meeting nodes recursively
//INPUT: head pointer to list of meetings
//OUTPUT: int return type: number of meetings
int rb_node::display_all(meeting_node * head, int & count) const
{
    int displayed = 0;

    //base case
    if (!head)
        return 0;

    //display current node
    cout << "S/N: " << count + 1 << endl;
    if (head->display())
    {
        cout << endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
        ++displayed;
        ++count;
    }
 
    //recursive call
    displayed += display_all(head->go_next(), count);

    return displayed;
}



//Sets color of node to argument value
//INPUT: new color value
//OUTPUT: int (0 - failure, invalid argument; 1 or 2 - success)
int rb_node::set_color(int new_color)
{
    //If argument value is valid set color to the same
    if (new_color == RED || new_color == BLACK)
    {
        color = new_color;
        return new_color;
    }

    //Otherwise flag failure
    else 
        return 0;
}



//Returns color of node
//INPUT: no arguments
//OUTPUT: int (color of node)
int rb_node::get_color(void) const
{
    return color;
}



//Wrapper - Adds new meeting to list if keywords match
//INPUT: meeting to add
//OUTPUT: int (0/1 - failure/success)
int rb_node::add_meeting(const meeting & to_add)
{
    if (to_add != key)
        return 0;

    return add_meeting(head, to_add);
}



//Adds new meeting to list recursively
//INPUT: head pointer to list, meeting to add
//OUTPUT: int (0/1 - failure/success)
int rb_node::add_meeting(meeting_node *& head, const meeting & to_add)
{
    //base case
    if (!head)
    {
        //create new node with meeting to add
        head = new meeting_node(to_add);
        return 1;
    }

    //recursive call
    return add_meeting(head->go_next(), to_add);
}



int rb_node::find_meeting_by_position(meeting_node *& found, int pos) const
{
    if (found != NULL)
        return 0;

    int timer = 0;

    return find_meeting_by_position(head, found, pos, timer);
}



int rb_node::find_meeting_by_position(meeting_node * head, meeting_node *& found, int pos, int & timer) const
{
    int match_found = 0;

    //base case
    if (!head)
        return 0;

    ++timer;

    if (timer == pos)
    {
        found = head;
        match_found = 1;
    }

    else
        match_found = find_meeting_by_position(head->go_next(), found, pos, timer);
    
    return match_found;
}



//Default constructor
//INPUT: no arguments
//OUTPUT: no return value
rb_tree::rb_tree(): root(NULL) {}



//Destructor - releases all dynamic memory
//INPUT: no arguments
//OUTPUT: no return value
rb_tree::~rb_tree()
{
    if (remove_all(root))
        root = NULL;
}



//Removes all nodes recursively
//INPUT: root pointer to tree
//OUTPUT: int (number of nodes removed)
int rb_tree::remove_all(rb_node *& root)
{
    int removed = 0;    //number of nodes removed

    //base case
    if (!root)
        return 0;

    //traverse left, right
    removed += remove_all(root->go_left());
    removed += remove_all(root->go_right());

    //remove current node
    delete root;
    root = NULL;

    return ++removed;
}



//Inserts a new meeting in tree
//INPUT: a meeting object to add
//OUTPUT: int (0/1 - failure/success)
int rb_tree::insert(const meeting & to_add)
{
    int success = 0;
    int timer = 0;
    rb_node * node_added = NULL;

    //perform a BST insert first
    if (BST_insert(root, to_add, node_added, timer))
    {
        ++success;

        if (node_added)
        {
            //fix violations for red-black tree
            if (convert_rb_tree(root, node_added))
                ++success;
        }
    }
    
    return success;
}



//Performs regular binary search tree insert recursively
int rb_tree::BST_insert(rb_node *& root, const meeting_node & to_add, rb_node *& node_added, int & timer)
{
    int insert_type = 0;    //Value to return: 1(meeting inserted into an existing node)
                            //2(new node created)

    //base case - empty tree or at a leaf
    if (!root)    
    {
        //Create a new node with meeting to add
        root = new rb_node(to_add);

        //Update argument pointer to point to new node
        node_added = root;

        //Increment value to return (2 if new node created)
        insert_type = 2;

        //Increment timer - to set new node's parent pointer upon return
        ++timer;

        return insert_type;
    }

    //If meeting to add matches current node's key, 
    //insert meeting into current node
    if (root->is_equal(to_add))
    {
        if (root->add_meeting(to_add))
            insert_type = 1;
    }

    //If current key is lesser, traverse right subtree
    //to insert
    else if (root->is_lesser(to_add))
    {
        insert_type += BST_insert(root->go_right(), to_add, node_added, timer);
        if (timer)
        {
            //Connect right child's parent pointer
            root->go_right()->connect_parent(root);
            
            //Reset timer
            timer = 0;
        }
    }

    //If current key is greater or equal, traverse left
    //subtree to insert
    else 
    {
        insert_type += BST_insert(root->go_left(), to_add, node_added, timer);
        if (timer)
        {
            //Connect left child's parent pointer
            root->go_left()->connect_parent(root);
            
            //Reset timer
            timer = 0;
        }
    }
   
    return insert_type; 
}



//Checks for and fixes red-black tree violations
int rb_tree::convert_rb_tree(rb_node *& root, rb_node *& a_node)
{
    int success = 0;
    bool violation = true;
    rb_node * uncle = NULL;
    rb_node * grand_parent = NULL;
    rb_node * a_node_parent = NULL;
 
    //If new node is not the root
    //If node is red and its parent is also red...
    while (a_node != root && a_node->is_red() && violation)
    {
        a_node_parent = a_node->go_parent();
        
        if (a_node_parent && a_node_parent->is_red())
        {
            //Find grandparent
            grand_parent = a_node_parent->go_parent();

            if (grand_parent)
            {
                //Parent is left child of grandparent
                if (a_node_parent == grand_parent->go_left())
                {
                    //Uncle is the right child of grandparent
                    uncle = grand_parent->go_right();

                    //If uncle is red
                    if (uncle && uncle->is_red())
                    {
                        if(grand_parent->set_color(RED) 
                           && a_node_parent->set_color(BLACK)
                           && uncle->set_color(BLACK))
                            a_node = grand_parent;
                    }

                    //If uncle is black
                    else
                    {
                        //If node is right child of parent
                        if (a_node == a_node_parent->go_right())
                        {
                            //perform left rotation
                            left_rotate(root, a_node_parent);
                            a_node = a_node_parent;
                            a_node_parent = a_node->go_parent();
                        }

                        right_rotate(root, grand_parent);
                        if (swap_color(a_node_parent, grand_parent))
                            a_node = a_node_parent;
                    }
                }

                //Parent is right child of grandparent
                else
                {
                    //Uncle is the left child of grandparent
                    uncle = grand_parent->go_left();

                    //If uncle is red
                    if (uncle && uncle->is_red())
                    {
                        if(grand_parent->set_color(RED) 
                           && a_node_parent->set_color(BLACK)
                           && uncle->set_color(BLACK))
                            a_node = grand_parent;
                    }

                    //If uncle is black
                    else
                    {
                        //If node is left child of parent
                        if (a_node == a_node_parent->go_left())
                        {
                            //perform left rotation
                            right_rotate(root, a_node_parent);
                            a_node = a_node_parent;
                            a_node_parent = a_node->go_parent();
                        }

                        left_rotate(root, grand_parent);
                        if (swap_color(a_node_parent, grand_parent))
                            a_node = a_node_parent;
                    }
                }
            }
        }

        else
            violation = false;

        if (root->set_color(BLACK))
            ++success;
    }

    return success;
}



int rb_tree::swap_color(rb_node *& node1, rb_node *& node2)
{
    int success = 0;
    int node1_color = node1->get_color();
    int node2_color = node2->get_color();

    if (node1->set_color(node2_color) && node2->set_color(node1_color))
        ++success;

    return success;
}



//Left rotate
void rb_tree::left_rotate(rb_node *& root, rb_node *& a_node)
{
    //Use temporary pointer to hold a_node's current right child
    rb_node * a_node_rt = a_node->go_right();
   
    //Update a_node's right pointer to current right child's left 
    a_node->connect_right(a_node_rt->go_left());

    //If not null, set parent pointer
    if (a_node->go_right())
        a_node->go_right()->connect_parent(a_node);

    //Set current right child's parent to a_node's parent
    a_node_rt->connect_parent(a_node->go_parent());

    //If a_node is the root, update root pointer
    if (!a_node->go_parent())
        root = a_node_rt;

    else if (a_node == (a_node->go_parent())->go_left())
        a_node->go_parent()->connect_left(a_node_rt);

    else
        a_node->go_parent()->connect_right(a_node_rt);

    a_node_rt->connect_left(a_node);
    a_node->connect_parent(a_node_rt);
    
    return;
}



//Right rotate
void rb_tree::right_rotate(rb_node *& root, rb_node *& a_node)
{
    //Use temporary pointer to hold a_node's current left child
    rb_node * a_node_lt = a_node->go_left();
   
    //Update a_node's left pointer to current left child's right 
    a_node->connect_left(a_node_lt->go_right());

    //If not null, set parent pointer
    if (a_node->go_left())
        a_node->go_left()->connect_parent(a_node);

    //Set current left child's parent to a_node's parent
    a_node_lt->connect_parent(a_node->go_parent());

    //If a_node is the root, update root pointer
    if (!a_node->go_parent())
        root = a_node_lt;

    else if (a_node == (a_node->go_parent())->go_left())
        a_node->go_parent()->connect_left(a_node_lt);

    else
        a_node->go_parent()->connect_right(a_node_lt);

    a_node_lt->connect_right(a_node);
    a_node->connect_parent(a_node_lt);

    return;
}



//Displays all nodes in order
int rb_tree::display_inorder(void) const
{
    return display_inorder(root);
}

int rb_tree::display_inorder(rb_node * root) const
{
    int displayed = 0;
    
    //base case
    if (!root)
        return 0;

    //traverse left subtree
    displayed += display_inorder(root->go_left());

    //display current node
    cout << endl;
    root->display();
    cout << endl;
    ++displayed;

    //traverse right subtree
    displayed += display_inorder(root->go_right());
    
    return displayed;
}



//Displays all keywords in order - wrapper function
//INPUT: no arguments
//OUTPUT: int: number of keywords
int rb_tree::display_key_inorder(void) const
{
    return display_key_inorder(root);
}

int rb_tree::display_key_inorder(rb_node * root) const
{
    int displayed = 0;
    
    //base case
    if (!root)
        return 0;

    //traverse left subtree
    displayed += display_key_inorder(root->go_left());

    //display current node
    root->display_key();
    cout << endl;
    ++displayed;

    //traverse right subtree
    displayed += display_key_inorder(root->go_right());
    
    return displayed;
}



//Finds height of tree
int rb_tree::height(rb_node * root) const
{
    //base case
    if (!root)
        return 0;

    return 1 + max(height(root->go_left()), height(root->go_right()));
}



//Displays all nodes each level
int rb_tree::display_key_bylevels(void) const
{
    int levels = 0;
    int ht = height(root);

    //Repeat for each level in tree
    for (int i = 1; i <= ht; ++i)
    {
        cout << "\n*** Level " << i << ": ***" << endl;
        if (display_lvl(root, i))
        {
            ++levels;
        }
    }

    return levels;
}



//Displays all nodes in a specific level
int rb_tree::display_lvl(rb_node * root, int lvl) const
{
    int displayed = 0;

    //base case
    if (!root || lvl < 1)
        return 0;

    //If level is 1, display root
    if (lvl == 1)
    {
        root->display_key();
        cout << endl;
        ++displayed;
    }

    //Otherwise traverse left and right subtrees
    //decrementing level value each time until level
    //is 1
    else
    {
        displayed += display_lvl(root->go_left(), lvl - 1);
        displayed += display_lvl(root->go_right(), lvl - 1);
    }

    return displayed;
}



//Displays all meetings that match argument key
//INPUT: keyword to match
//OUTPUT: number of meetings found for keyword
int rb_tree::display_by_keyword(char * a_key) const
{
    char * a_key_lower = NULL; //to convert to lowercase
    int a_key_len = 0;     //length of argument word
    int displayed = 0;     //number of meetings found

    if (!a_key)
        return 0;

    //convert to lowercase
    a_key_len = strlen(a_key);
    a_key_lower = new char[a_key_len + 1];
    strcpy(a_key_lower, a_key);
    for (int i = 0; i < a_key_len; ++i)
        a_key_lower[i] = tolower(a_key[i]); 

    //display all meetings for the keyword
    displayed = display_by_key(root, a_key_lower);

    //delete temporary variable
    if (a_key_lower)
    {
        delete [] a_key_lower;
        a_key_lower = NULL;
    }

    return displayed;
}



//Displays all meetings that match argument key
//INPUT: keyword to match
//OUTPUT: number of meetings found for keyword
int rb_tree::display_by_key(rb_node * root, char * a_key) const
{
    int displayed = 0;  //Number of meetings found

    //base case
    if(!root)
        return 0; 

    //If current node matches key, display all meetings 
    //in node
    if (root->is_equal(a_key))
        displayed = root->display();

    //If current key is lesser, traverse right subtree
    //to insert
    else if (root->is_lesser(a_key))
        displayed = display_by_key(root->go_right(), a_key);

    //If current key is greater, traverse left subtree
    //to insert
    else
        displayed = display_by_key(root->go_left(), a_key);

    return displayed;
}



//Loads calendar from file
//INPUT: 1 argument: filename to load from
//OUTPUT: return type: int (number of meetings loaded) 
int rb_tree::load_file(const char filename[])
{
    meeting * new_meeting = NULL;  //Temporary pointer to read each meeting in file
    char all_participants[801];    //Temporary variable to read in participants info
    char meeting_name[101];        //Temporary variable to read in meeting name
    char meeting_loc[101];         //Temporary variable to read in meeting location
    char meeting_date_time[101];   //Temporary variable to read in meeting date and time
    char meeting_key[101];         //Temporary variable to read in meeting keyword
    int meetings_added = 0;        //Value to return
    grp_part * meeting_grp = NULL;
    ifstream in_file;              //File variable for input
  
    //Connect to particular file
    in_file.open(filename);

    //If unable to find file
    if (!in_file)
        return 0;

    //If connected...
    else
    {
        //Attempt to read first piece of data
        in_file.get(all_participants, 801, '|');
        in_file.ignore(1000, '|');

        //Repeat until end of file or not connected to file
        while (in_file && !in_file.eof())
        {
            //Read in meeting name...
            in_file.get(meeting_name, 101, '|');
            in_file.ignore(1000, '|');

            in_file.get(meeting_loc, 101, '|');
            in_file.ignore(1000, '|');

            in_file.get(meeting_date_time, 101, '|');
            in_file.ignore(1000, '|');

            in_file.get(meeting_key, 101, '\n');
            in_file.ignore(1000, '\n');

            //Extract individual participants and create a grp_part object
            meeting_grp = new grp_part;
            if (extract_participants (all_participants, *meeting_grp))
            {
                //create new meeting with read in details
                new_meeting = new meeting(meeting_name, meeting_loc, meeting_date_time, meeting_key, *meeting_grp);
                
                //Add meeting into tree
                if (insert(* new_meeting))
                    //Increment number of meetings loaded
                    ++meetings_added;
            }

            //Reset temporary variables
            delete new_meeting;
            new_meeting = NULL;
            delete meeting_grp;
            meeting_grp = NULL;

            //Prime the pump for next read in
            in_file.get(all_participants, 801, '|');
            in_file.ignore(1000, '|');
        }
        
        //Close file and clear file variable
        in_file.close();
        in_file.clear();
    }
    
    return meetings_added;
}



//Extracts participants info and builds a group of participants
//INPUT: 2 arguments: char array to extract participants info from, grp_part pointer
//OUTPUT: return type: int (number of participants extracted) 
int rb_tree::extract_participants(char * all_participants, grp_part & a_grp)
{
    participant * new_participant = NULL;    //Temporary pointer to add each participant 
    contact * new_contact = NULL;
    char participant_name[100];         //Extracted participant name
    char participant_email[100];         //Extracted participant email
    int participant_intent = -1;
    char participant_comment[500];
    char * dest = participant_name;     //to traverse extracted participant name
    int size = 0;           //Length of all_participants array
    int index = 0;          //Loop variable -  array index
    int num_participants = 0;      //Number of participants extracted
    int timer = 0;          //To extract planet type at beginning of each name
  
    //Flag failure if null arguments 
    if (!all_participants)
        return 0;

    //Find length of all participants array
    size = strlen(all_participants);

    //Traverse each character of array 
    while (index <= size)
    {
        //Copy character into participant name if not [ or terminating null
        if (timer == 0 &&
            all_participants[index] != '[')
        {
            * dest = all_participants[index];
            ++dest;
            ++index;
        }

        //If '[' - end of name
        else if (timer == 0 && all_participants[index] == '[')
        {
            //terminate word with null character
            * dest = '\0';

            //Increment index
            ++index;

            //Set timer to 1: to read email id next
            timer = 1;        
            dest = participant_email;
        }
            
        else if (timer == 1 &&
                 all_participants[index] != '^')
        {
            * dest = all_participants[index];
            ++dest;
            ++index;
        }

        //If '^' - end of email
        else if (timer ==1 && all_participants[index] == '^')
        {
            //terminate word with null character
            * dest = '\0';

            //Increment index
            ++index;

            //Set timer to 2: to read intent next
            timer = 2;        

            dest = participant_comment;
        }

        else if (timer == 2 &&
                 all_participants[index] != ';' &&
                 all_participants[index] != '\0')
        {
            if (all_participants[index] == '0')
                participant_intent = 0;

            else if (all_participants[index] == '1')
                participant_intent = 1;

            else if (all_participants[index] == '2')
                participant_intent = 2;

            else
            {
                participant_intent = -1;
                ++index;
            }
            
            ++index;
            timer = 3;
        }

        else if (timer == 3 && 
                 all_participants[index] != ';' &&
                 all_participants[index] != '\0')
        {
            * dest = all_participants[index];
            ++dest;
            ++index;
        }

        else if (all_participants[index] == ';' ||
                 all_participants[index] == '\0')
        {
            //terminate word with null character
            * dest = '\0';
            ++index;
            timer = 4;
        }

        if (timer == 4)
        {
            //Create a new contact 
            new_contact = new contact(participant_name, participant_email);
            cout << endl;
           
            //Create a new participant
            new_participant = new participant(*new_contact, participant_intent, participant_comment);
            cout << endl;

            //Add participant to group
            if (a_grp.add(*new_participant))
                ++num_participants;

            //Reset participant name and timer
            dest = participant_name;
            timer = 0;

            //Reset temporary variables
            delete new_participant;
            new_participant = NULL;
            delete new_contact;
            new_contact = NULL;
        }
    }
    
    return num_participants;
}



int rb_tree::find_by_keyword(rb_node *& found, char * a_key) const
{
    return find_by_key(found, root, a_key);
}



int rb_tree::find_by_key(rb_node *& found, rb_node * root, char * a_key) const
{
    int match_found = 0;

    //base case
    if(!root)
        return 0; 

    //If current node matches key, display all meetings 
    //in node
    if (root->is_equal(a_key))
    {
        found = root;
        match_found = 1;
    }

    //If current key is lesser, traverse right subtree
    else if (root->is_lesser(a_key))
        match_found = find_by_key(found, root->go_right(), a_key);

    //If current key is greater, traverse left subtree
    else
        match_found = find_by_key(found, root->go_left(), a_key);

    return match_found;
}
