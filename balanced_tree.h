//Filename: balanced_tree.h

//Name:     Meera Murali
//Email:    mmurali@pdx.edu
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "meeting_response.h"



//Constants
const int RED = 1;
const int BLACK = 2;



//Class interfaces
class meeting_node: public meeting
{
    public:
        meeting_node();
        meeting_node(const meeting & to_copy);
        meeting_node(const meeting_node & to_copy);

        meeting_node *& go_next(void);
        void connect_next(meeting_node * connection);

    private:
        meeting_node * next;
};



class rb_node
{
    public:
        rb_node();
        rb_node(char * a_key);
        rb_node(const meeting & to_add);
        ~rb_node();

        rb_node *& go_left(void);
        rb_node *& go_right(void);
        rb_node *& go_parent(void);
        void connect_left(rb_node * connection);
        void connect_right(rb_node * connection);
        void connect_parent(rb_node * connection);

        bool is_red(void) const;
        bool is_lesser(const meeting & to_compare) const;
        bool is_equal(const meeting & to_compare) const;
        int display(void) const;
        int set_color(int new_color);
        int get_color(void) const;
        int add_meeting(const meeting & to_add);
        
    private:
        char * key;
        meeting_node * head;
        int color;
        rb_node * left;
        rb_node * right;
        rb_node * parent;

        int display_all(meeting_node * head) const;
        int add_meeting(meeting_node *& head, const meeting & to_add);
        int remove_all(meeting_node *& head);
};



class rb_tree
{
    public:
        rb_tree();
        ~rb_tree();

        int height(rb_node * root) const;
        int insert(const meeting & to_add);
        int display_inorder(void) const;
        int display_levels(void) const;
//        int display_by_keyword(char * a_key) const;

    private:
        rb_node * root;
       
        int remove_all(rb_node *& root);
        int BST_insert(rb_node *& root, const meeting_node & to_add, rb_node *& node_added, int & timer);
        int convert_rb_tree(rb_node *& root, rb_node *& a_node);
        void left_rotate(rb_node *& root, rb_node *& a_node);
        void right_rotate(rb_node *& root, rb_node *& a_node);
        int swap_color(rb_node *& node1, rb_node *& node2);
        int display_inorder(rb_node * root) const;
        int display_lvl(rb_node * root, int lvl) const;
};
