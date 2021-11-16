#include<iostream>

using namespace std;

#ifndef INCLUDE_G
#define INCLUDE_G


class user
{
    public :
    void set_name(const string &);
    string get_name();
    void set_ip(string);
    string get_ip();

    private :
    string name = "empty";
    unsigned int card_number;
    unsigned short int opening_account_year;
    unsigned short int opening_account_month;
    unsigned short int opening_account_day;
    unsigned short int expiration_account_year;
    unsigned long long int balance = 0;
    string * record_ptr = nullptr;
    string * ip_lists_ptr = nullptr;
    string ip_of_account = 0 ;
};


void Check_User_Name(string &  , user * );
void Re_Enter_String(string & ,user *);
user * Increase_Class(user * );

#endif