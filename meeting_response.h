//Filename: meeting_response.h

//Name:     Meera Murali
//Email:    mmurali@pdx.edu
//Class:    202
//Program:  3
//Date:     08/07/2017

//This program manages



#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>

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
        virtual bool operator == (char * id_to_match) const;
        virtual bool operator != (const contact& to_compare) const;
//        friend ostream& operator << (ostream&, const contact&);
//        int read_contact(void);
        int write_file_append(const char filename[]) const;

    protected:
        char * name;
        char * email;
};

class participant: public contact
{
    public:
        participant();
        participant(const contact & to_copy);
        participant(const contact & to_copy, int an_intent, char * a_comment);
        participant(const participant & to_copy);
        ~participant();    

        int set_response(int an_intent, char * a_comment);
        int display(void) const;
        bool check_intent(int an_intent) const;
        int copy_participant(const participant & to_copy);
        participant& operator = (const participant& to_copy);
        int write_file_append(const char filename[]) const;

    protected:
        int intent;     //0:No, 1:Maybe, 2:Yes, -1:default
        char * comment;
};

class participant_node: public participant
{
    public:
        participant_node();
        participant_node(const participant & to_copy);
        participant_node(const participant_node & to_copy);

        participant_node *& go_next(void);
        void connect_next(participant_node * connection);

    private:
        participant_node * next;
};

class grp_part
{
    public:
        grp_part();
        grp_part(const grp_part & to_copy);
        virtual ~grp_part();

        int add(const participant & to_add);
        int add_response(char * id_to_match, int an_intent, char * a_comment);
        int copy_group(const grp_part & to_copy);
        bool find(const participant & to_find) const;
        virtual int display(void) const;
//        int concatenate(const grp_part & a_grp);
        virtual grp_part& operator = (const grp_part & to_copy);
        grp_part& operator += (const participant & to_add);
        friend grp_part operator + (const grp_part & a_grp, const participant & to_add);
        friend grp_part operator + (const participant & to_add, const grp_part & a_grp);
//        grp_part operator + (const grp_part & grp1, const grp_part & grp2);
        int write_file_append(const char filename[]) const;

    protected:
        participant_node * head;

        int remove_all(participant_node * & head);
        int display(participant_node * head) const;
        int copy_group(participant_node * & dest, participant_node * src);
        bool find(participant_node * head, const participant & to_find) const;
        int add_response(participant_node * & head, char * id_to_match, int an_intent, char * a_comment);
//        int concatenate(participant_node * & head, participant_node * & to_attach);
};

class meeting: public grp_part
{
    public:
        meeting();
        meeting(char * a_meeting_name, char * a_location, char * a_day_time, char * a_keyword);
        meeting(char * a_meeting_name, char * a_location, char * a_day_time, char * a_keyword, const grp_part & a_grp);
        meeting(const meeting & to_copy);
        ~meeting();

        int display(void) const;
        int copy_meeting(const meeting & to_copy);
        int check_key(char * a_key) const;
        int get_key(char *& a_key) const;
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
        int write_file_append(const char filename[]) const;

    protected:
        char * meeting_name;
        char * location;
        char * day_time;
        char * keyword;
};












