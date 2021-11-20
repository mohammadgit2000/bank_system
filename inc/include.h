
#ifndef INCLUDE_G
#define INCLUDE_G

#include<iostream>

using namespace std;

class user
{
    public :
    void set_user_name(string);
    string get_user_name();
    void set_ip(string);
    string get_ip();
    user();

    private :
    string user_name = "empty" ;
    unsigned int card_number;
    unsigned short int opening_account_year;
    unsigned short int opening_account_month;
    unsigned short int opening_account_day;
    unsigned short int expiration_account_year;
    unsigned long long int balance = 0;
    string * record_ptr = nullptr;
    string * ip_lists_ptr = nullptr;
    string ip_of_account = "no_ip";
};


void Check_User_Namr(string & ,user *&);
void Re_Enter_String(string & ,user *&);
user * Increase_Class(user *&);
void Print_Eror(string ,string);
bool Is_Command_Entred(string &  , unsigned short int & );

#endif