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



//Displays keyword and all meetings in list
//INPUT: no arguments
//OUTPUT: int return type (number of meetings in list)
int rb_node::display(void) const
{
    int num_meetings = 0;   //value to return 

    //Display node color
    if (color == RED)
        cout << "(R) ";
    else
        cout << "(B) ";

    //Display keyword
    cout << "KEYWORD: " << key;

    //Display all meetings in list
    num_meetings = display_all(head);

    if (!num_meetings)
        cout << "\tNo meetings to display" << endl;

    else
        cout << "*** " << num_meetings << " meetings found ***" << endl;

    return num_meetings;
}


    
//Displays all meeting nodes recursively
//INPUT: head pointer to list of meetings
//OUTPUT: int return type: number of meetings
int rb_node::display_all(meeting_node * head) const
{
    int displayed = 0;

    //base case
    if (!head)
        return 0;

    //display current node
    cout << "\t";
    if (head->display())
        ++displayed;
 
    //recursive call
    displayed += display_all(head->go_next());

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
    root->display();
    cout << endl;
    ++displayed;

    //traverse right subtree
    displayed += display_inorder(root->go_right());
    
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
int rb_tree::display_levels(void) const
{
    int levels = 0;
    int ht = height(root);

    //Repeat for each level in tree
    for (int i = 1; i <= ht; ++i)
    {
        cout << "\n*** Level " << i << ": ***" << endl;
        if (display_lvl(root, i))
        {
            cout << endl;
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
        root->display();
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
