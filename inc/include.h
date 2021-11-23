#ifndef INCLUDE_G
#define INCLUDE_G

#include<iostream>

using namespace std;

class user
{
    public :
    user(); // consttructore just set date of account like opening and expiration .
    void set_user_name(string); // set username of account .
    string get_user_name(); // return username of account .
    void set_ip(string); // set ip of account .
    string get_ip(); // return ip of account .
    unsigned short int get_opening_year(); // return opening year of account .
    unsigned short int  get_opening_month(); // return opening month of account .
    unsigned short int get_opening_day(); // return opening day of account .
    unsigned short int get_expiration_year(); // return expiratoin of account .
    void set_card_number(unsigned int);
    unsigned int get_card_number();

    private :
    string user_name = "empty" ; // The username is stored in this variable .
    unsigned int card_number; // The card number is stored in this variable .
    string ip_of_account = "no_ip"; // stored ip of account .
    unsigned short int opening_account_year; // stored opening yeaar of account .
    unsigned short int opening_account_month; // stored opening month of account .
    unsigned short int opening_account_day; // stored opening day of account .
    unsigned short int expiration_account_year; // stored opening expiration of account .
    unsigned long long int balance = 0; // stored balance of account .
    string * record_ptr = nullptr; // stored all of records .
    string * ip_lists_ptr = nullptr; // stored extra ip`s .
};


void Re_Enter_String(string & ,user *&); // if entreance information was wrong we call this function again .
void Check_User_Name(string & ,user *&); // username and ip validation .
user * Increase_Class(user *&); // increase size of class array and copy pre class`s information in new class array that increased .
void Print_Eror(string ,string); // recive two string and print them in format of eror .
bool Is_Command_Entred(string &  , unsigned short int & ); // if command exist in the entrance string return true else return false .
bool Is_Char_Exist(char , string & ,unsigned short int , bool ); // if character of word exist in index of string we return true .
bool Create_And_Check_Card_Number(user *&);

#endif