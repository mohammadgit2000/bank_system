#ifndef INCLUDE_G
#define INCLUDE_G

#include<iostream>

using namespace std;

class user
{
    public :

    user(); // consttructore just set date of account like opening and expiration .

    /* ------------------->  SET Class Functions   <---------------------- */

    void set_user_name(string); // set username of account .
    void set_ip(string); // set ip of account .
    void set_card_number(unsigned int); // set card number of account .
    void set_extra_ip(user*& ,unsigned short int ,string); // set extra ip of account .


    /* ------------------->  GET Class Functions   <---------------------- */

    string get_user_name(); // return username of account .
    string get_ip(); // return ip of account .
    string get_extra_ip(unsigned short int); // get extra ip`s one by one

    unsigned short int get_opening_year(); // return opening year of account .
    unsigned short int get_opening_month(); // return opening month of account .
    unsigned short int get_opening_day(); // return opening day of account .
    unsigned short int get_expiration_year(); // return expiratoin of account .
    unsigned int get_card_number(); // get card number of account .
    unsigned short int get_count_extra_ip();

    /* ------------------->  OTHER Class Functions   <---------------------- */

    void Increase_String_Array(unsigned short int , user *& customer_class); // increase string length.


    private :

    /* ------------------->  DATE Class Variable   <---------------------- */

    unsigned short int opening_account_year; // stored opening yeaar of account .
    unsigned short int opening_account_month; // stored opening month of account .
    unsigned short int opening_account_day; // stored opening day of account .
    unsigned short int expiration_account_year; // stored opening expiration of account .


    /* ------------------->  MAIN Class Variable   <---------------------- */

    string user_name = "empty" ; // The username is stored in this variable .
    string ip_of_account = "no_ip"; // stored ip of account .
    unsigned short int count_record = 0; // record counter .
    string * ip_lists_ptr = nullptr; // stored extra ip`s .
    unsigned short int count_extra_ip = 0; // extra ip counter .


    /* ------------------->  OTHER Class Variable   <---------------------- */

    unsigned int card_number; // The card number is stored in this variable .
    string * record_ptr = nullptr; // stored all of records .
    unsigned long long int balance = 0; // stored balance of account .
};



/* ------------------------------------------------>    OTHER Functions   <------------------------------------------------------ */

void Re_Enter_String(string & ,user *&); // if entreance information was wrong we call this function again .
void Recognize_Commands(string & ,user *&); // username and ip validation .
user * Increase_Class(user *&); // increase size of class array and copy pre class`s information in new class array that increased .
void Print_Eror(string ,string); // recive two string and print them in format of eror .
void Check_Exit_Command(string &); // if exit command entered we execute it .
void Create_And_Check_Card_Number(user *&); // create eandom number and check with previous card numbers .
void Validation_After_Colon(string &  ,unsigned short int  ,user *& ); // after colon should not be entered '.' or '\0'


/* ------------------------------------------------>    IS functions   <------------------------------------------------------ */

bool Is_Command_Entred(string &  , unsigned short int & ); // if command exist in the entrance string return true else return false .
bool Is_Char_Exist(char , string & ,unsigned short int , bool ); // if character of word exist in index of string we return true .
bool Is_Repetitive_UserName(user *& , string & , bool); // prevent from same user name .
bool Is_Repetitive_ip(user *& , string & , bool);       // prevent from same ip
bool Is_Valid_UserName(string &);                       // user name validation .
bool Is_Valid_IP(string &);                             // ip validation .


/* ------------------------------------------------>   READ functions   <------------------------------------------------------ */

void Read_User_Name(string &  , unsigned short int &  , string & ); // read user name from input .
void Read_IP(string &  , unsigned short int & , string & );         // read ip from input .



/* ------------------------------------------------>   COMMANDS functions   <------------------------------------------------------ */

void Create_Account(user *& ,string & ,string & ,unsigned short int &); // execute "create" command 
void Add_Extra_IP(user *& , unsigned short int & ,string &);            // execute "add_ip" command  .



/* ------------------------------------------------>   CHECKER functions   <------------------------------------------------------ */

void IP_Checker(string &  ,string &  ,user *& ); // The IP checking set is stored in this function
void UserName_Checker();

#endif