//Filename: balanced_tree.h

//Name:     Meera Murali
//Email:    mmurali@pdx.edu
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include "meeting_response.h"



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


