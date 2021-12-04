#ifndef INCLUDE_G
#define INCLUDE_G

#include<iostream>

using namespace std;

class user
{
    public : /* <--------------- public */

    user(); // consttructore just set date of account like opening and expiration .

    /* ------------------->  SET Class Functions   <---------------------- */

    void set_user_name(string); // set username of account .

    void set_ip(string); // set ip of account .

    void set_card_number(unsigned int); // set card number of account .

    void set_extra_ip(user*& ,unsigned short int ,string); // set extra ip of account .

    void set_personal_report(string);
    

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

    long long int get_balance();

    unsigned int get_personal_count();

    string get_personal_report(unsigned int);



    /* ------------------->  OTHER Class Functions   <---------------------- */

    void Increase_Extra_Ip_Length(unsigned short int , user *& customer_class); // increase string length.

    void decrease_money(long long int);

    void increase_money(long long int);

    void renew_date_account();

    void increase_personal_report();

    private : /*<------------------ private*/

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

    long long int balance = 0; // stored balance of account .

    string * personal_report_list = nullptr;

    unsigned int personal_report_counter = 0;

}; // END OF CLASS (User)



class bank_transaction
{
    public :

    void set_bank_report(string);

    void Increase_Report_length();

    string get_bank_report(unsigned short int);

    private :

    string * report_list_ptr = nullptr ;
};


/* ------------------------------------------------>    OTHER Functions   <------------------------------------------------------ */

void Re_Enter_String(string & ,user *&); // if entreance information was wrong we call this function again .

void Recognize_Commands(string & ,user *&); // username and ip validation .

user * Increase_Class(user *&); // increase size of class array and copy pre class`s information in new class array that increased .

void Print_Eror(string ,string); // recive two string and print them in format of eror .

void Check_Exit_Command(string &); // if exit command entered we execute it .

void Create_And_Check_Card_Number(user *&); // create eandom number and check with previous card numbers .

bool Validation_After_Colon(string &  ,unsigned short int  ,user *& ); // after colon should not be entered '.' or '\0'

void Display_Loading();

void Storing_All_Report(string ,user *& ,unsigned int);



/* ------------------------------------------------>    IS functions   <------------------------------------------------------ */

bool Is_Command_Entred(string &  , unsigned short int & , string *); // if command exist in the entrance string return true else return false .

bool Is_Char_Exist(char , string & ,unsigned short int , bool ); // if character of word exist in index of string we return true .

bool Is_Repetitive_UserName(user *& , string & , bool ,int &); // prevent from same user name .

bool Is_Repetitive_ip(user *& , string & , bool ,int &); // prevent from same ip

bool Is_Valid_UserName(string &); // user name validation .

bool Is_Valid_IP(string &); // ip validation .

bool Is_Renewal_Date_Arrived(user *& customer_class ,unsigned short int); // check renewal date .

bool Is_Enough_Money(user *& ,long long int ,unsigned short int);



/* ------------------------------------------------>   READ functions   <------------------------------------------------------ */

void Read_User_Name(string &  , unsigned short int &  , string & ); // read user name from input .

void Read_IP(string &  , unsigned short int & , string & ); // read ip from input .



/* ------------------------------------------------>   COMMANDS functions   <------------------------------------------------------ */

void Create_Account(user *& ,string & ,string & ,unsigned short int &); // execute "create" command 

void Add_Extra_IP(user *& , unsigned short int & ,string &); // execute "add_ip" command  .

void Re_New_Account_Date(user *& ,string &  ,unsigned short int & , int);

void Deposit(unsigned short int & ,string & ,user *& ,int);



/* ------------------------------------------------>   CHECKER functions   <------------------------------------------------------ */

bool IP_Checker(string &  ,string &  ,user *& ,bool ,int &); // The IP checking set is stored in this function

bool UserName_Checker(string &  , string &  ,user *&  , bool ,int &);

bool Money_Checker(long long int &  ,string &  ,user *&  ,unsigned short int & );


#endif