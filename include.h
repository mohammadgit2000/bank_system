#ifndef INCLUDE_G
#define INCLUDE_G


class user
{
    public :
    void set_name(string name);
    string get_name();

    private :
    string name;
    unsigned int card_number;
    unsigned short int opening_account_year;
    unsigned short int opening_account_month;
    unsigned short int opening_account_day;
    unsigned short int expiration_account_year;
    unsigned long long int balance = 0;
    string * record_ptr = nullptr;
    string * ip_lists_ptr = nullptr;
};



#endif