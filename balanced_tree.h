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
        bool is_lesser(char * to_compare) const;
        bool is_equal(char * to_compare) const;
        int display(void) const;
        int display_key(void) const;
        int set_color(int new_color);
        int get_color(void) const;
        int add_meeting(const meeting & to_add);
        int find_meeting_by_position(meeting_node *& found, int pos) const;
        
    private:
        char * key;
        meeting_node * head;
        int color;
        rb_node * left;
        rb_node * right;
        rb_node * parent;

        int display_all(meeting_node * head, int & count) const;
        int add_meeting(meeting_node *& head, const meeting & to_add);
        int remove_all(meeting_node *& head);
        int find_meeting_by_position(meeting_node * head, meeting_node *& found, int pos, int & timer) const;
};



class rb_tree
{
    public:
        rb_tree();
        ~rb_tree();

        int load_file(const char filename[]);
        int height(rb_node * root) const;
        int insert(const meeting & to_add);
        int display_inorder(void) const;
        int display_key_inorder(void) const;
        int display_key_bylevels(void) const;
        int display_by_keyword(char * a_key) const;
        int find_by_keyword(rb_node *& found, char * a_key) const;
//        rb_node& operator [] (char * a_key);

    private:
        rb_node * root;

        int extract_participants(char * all_participants, grp_part & a_grp);
        int remove_all(rb_node *& root);
        int BST_insert(rb_node *& root, const meeting_node & to_add, rb_node *& node_added, int & timer);
        int convert_rb_tree(rb_node *& root, rb_node *& a_node);
        void left_rotate(rb_node *& root, rb_node *& a_node);
        void right_rotate(rb_node *& root, rb_node *& a_node);
        int swap_color(rb_node *& node1, rb_node *& node2);
        int display_inorder(rb_node * root) const;
        int display_lvl(rb_node * root, int lvl) const;
        int display_by_key(rb_node * root, char * a_key) const;
        int find_by_key(rb_node *& found, rb_node * root, char * a_key) const;
        int display_key_inorder(rb_node * root) const;
};
