//Filename: meeting_response.h

//Name:     Meera Murali
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;



//Class Interfaces
class contact
{
    public:
        contact();
        contact(char * a_name, char * an_email);
        contact(const contact& to_copy);
        virtual ~contact();

        int copy_contact(const contact& to_copy);
        int set_contact(char * a_name, char * an_email);
        virtual int display(void) const;
        virtual contact& operator = (const contact& to_copy);
        virtual bool operator == (const contact& to_compare) const;
        virtual bool operator != (const contact& to_compare) const;
//        friend ostream& operator << (ostream&, const contact&);
//        int read_contact(void);

    protected:
        char * name;
        char * email;
};

class contact_node: public contact
{
    public:
        contact_node();
        contact_node(const contact & to_copy);
        contact_node(const contact_node & to_copy);
//        ~contact_node();

        contact_node *& go_next(void);
        void connect_next(contact_node * connection);

    private:
        contact_node * next;
};

class group_contacts
{
    public:
        group_contacts();
        group_contacts(const group_contacts & to_copy);
        virtual ~group_contacts();

        int add_contact(const contact & to_add);
        virtual int display(void) const;
        int copy_group(const group_contacts & to_copy);
//        int concatenate(const group_contacts & a_grp);
        virtual group_contacts& operator = (const group_contacts & to_copy);
        friend group_contacts operator + (const group_contacts & a_grp, const contact & to_add);
        friend group_contacts operator + (const contact & to_add, const group_contacts & a_grp);
//        group_contacts operator + (const group_contacts & grp1, const group_contacts & grp2);

    protected:
        contact_node * head;

        int remove_all(contact_node * & head);
        int display(contact_node * head) const;
        int copy_group(contact_node * & dest, contact_node * src);
//        int concatenate(contact_node * & head, contact_node * & to_attach);
};

class meeting: public group_contacts
{
    public:
        meeting();
        meeting(char * a_meeting_name, char * a_location, char * a_day_time, char * a_keyword);
        meeting(char * a_meeting_name, char * a_location, char * a_day_time, char * a_keyword, const group_contacts & a_grp);
        meeting(const meeting & to_copy);
        virtual ~meeting();

        int display(void) const;
        int copy_meeting(const meeting & to_copy);
        int check_key(char * a_key) const;
        meeting& operator = (const meeting & to_copy);
        friend bool operator == (const meeting & a_meet, char * key);
        friend bool operator == (char * key, const meeting & a_meet);
        friend bool operator != (const meeting & a_meet, char * key);
        friend bool operator != (char * key, const meeting & a_meet);
        friend bool operator < (const meeting & a_meet, char * key);
        friend bool operator < (char * key, const meeting & a_meet);
        friend bool operator > (const meeting & a_meet, char * key);
        friend bool operator > (char * key, const meeting & a_meet);
        friend bool operator <= (const meeting & a_meet, char * key);
        friend bool operator <= (char * key, const meeting & a_meet);
        friend bool operator >= (const meeting & a_meet, char * key);
        friend bool operator >= (char * key, const meeting & a_meet);

    protected:
        char * meeting_name;
        char * location;
        char * day_time;
        char * keyword;
};
