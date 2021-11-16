#include"include.h"
#include<iostream>
#include<cctype>

#define SIZE 1

using namespace std ;

extern unsigned int global_count ; // at the first ---> 0

void Check_User_Name(string & input_string , user * customer_cls)
{
    const string default_command[] = {"create"};
    bool find_command = false;
    int find_out_put;
    unsigned int count_default_string ;

    for (count_default_string = 0; count_default_string < SIZE ; count_default_string++)
    {
        find_out_put = input_string.find(default_command[count_default_string]);

        if (find_out_put >= 0)
        {
            find_command = true;
            break;
        }
    }
    
    if (find_command == false)
    {
        cerr << "!!!    Command Not Found    !!!" << endl;
        Re_Enter_String(input_string ,customer_cls);
    }
    
    if (find_command == true)
    {
        if (find_out_put != 0)
        {
            cerr << "#   Command Must Be In The First Of String   #" << endl;
            Re_Enter_String(input_string ,customer_cls);
        }
    }
    
    if (count_default_string == 0 && customer_cls[global_count - 1].get_user_name() != "empty")
    {
        customer_cls = Increase_Class(customer_cls);
    }
    
    string IP;
    string user_name;
    string ip_string;

    switch (count_default_string)
    {
        case 0 :
        
        unsigned int len_default_string = default_command[count_default_string].size();

        if (input_string[len_default_string] != ' ')
        {
            cerr << "!!!   Invalid Entrance String   !!!" << endl;
            Re_Enter_String(input_string , customer_cls);
        }
        
        len_default_string++;

        if ( isdigit( input_string[len_default_string] ) )
        {
            cerr << "!!   Invalid User Name . User Name Can not Begin With Number   !!" << endl;
            Re_Enter_String(input_string , customer_cls);
        }
        

        while (input_string[len_default_string] != ':' && input_string[len_default_string] != '\0')
        {
            user_name += input_string[len_default_string];
            len_default_string++;
        }
        
        if (input_string[len_default_string] == '\0')
        {
            cerr << "!!   We Can Not Detect IP   !!" << endl;
            Re_Enter_String(input_string , customer_cls);
        }
        

        len_default_string++;

        if (input_string[len_default_string] == '\0')
        {
            cerr << "!!   We Can Not Detect IP   !!" << endl;
            Re_Enter_String(input_string , customer_cls);
        }
        
        if (input_string[len_default_string] == '.')
        {
            cerr << "!!!   Invalid IP Entered  !!!" << endl;
            Re_Enter_String(input_string ,customer_cls);
        }
        
        unsigned int save_len = len_default_string;
        unsigned short int count_dot = 0;
        
        while (input_string[len_default_string] != '\0')
        {
            int convert_number = stoi(&input_string[len_default_string]);

            if (convert_number >= 256)
            {
                cerr << "Invalid IP Entered  !!!" << endl;
                Re_Enter_String(input_string ,customer_cls);
            }
            

            while (input_string[len_default_string] != '.' && input_string[len_default_string] != '\0')
            {
                ip_string += input_string[len_default_string];
                len_default_string++;
            }
            
            if (input_string[len_default_string] == '\0')
            {
                cerr << "!!!   Invalid IP Entered    !!!" << endl;
                Re_Enter_String(input_string , customer_cls);
            }
            
            if (input_string[len_default_string] == '.')
            {
                count_dot++;
                
                if (count_dot >= 4)
                {
                    cerr << "!!!   Invalid IP Entered   !!!" << endl;
                    Re_Enter_String(input_string , customer_cls);
                }

                ip_string += input_string[len_default_string];
                len_default_string++;
            }
                else
                {
                    cerr << "!!!   Invalid IP Entered   !!!" << endl;
                    Re_Enter_String(input_string , customer_cls);
                }
        }

        if (count_dot <= 2 || count_dot >= 4 )
        {
            cerr << "!!!   Invalid IP Entered   !!!" << endl;
            Re_Enter_String(input_string ,customer_cls);
        }
        
        customer_cls[global_count - 1 ].set_user_name(user_name);
        customer_cls[global_count - 1].set_ip(ip_string);

        break;
    
        default:
        break;
    }


    

}




void Re_Enter_String(string & input_string , user * customer_cls)
{
    unsigned short int chance = 3;

    cout << endl << "Enter Command Under This Line ...." << endl;
    fflush(stdin);
    getline(cin , input_string);

    while (input_string.empty())
    {
        system("cls");

        if (chance == 0)
        {
            system("cls");
            cerr << "+     -     -     -     -     -     -     -     -     -     -     -     -     +" << endl;
            cerr << "|                                                                             |" << endl;
            cerr << "|    You Have  #  3  #  Invalid Attempts And We Have To Closs The Program     |" << endl;
            cerr << "|                                                                             |" << endl;
            cerr << "+     -     -     -     -     -     -     -     -     -     -     -     -     +" << endl;
            exit(EXIT_FAILURE);
        }
        
        cout << "!!!   You Have  ~  " << chance << "  ~  Chance To Enter Valid Command   !!!" << endl;
        cout << "Order Can not Be Empty . Please Enter Command Under This Line ..." << endl;
        fflush(stdin);
        getline(cin ,input_string);
        chance--;
    }
    
    if (input_string == "Exit" || input_string == "exit" || input_string == "EXIT" || input_string == "0")
    {
        system("cls");
        cout << "!!   You Entered Exit Command In The First Of Program   !!" << endl;
        cout << "\t!!   End Of Program   !!" << endl;
        exit(EXIT_SUCCESS);
    }

        while (input_string != "exit" || input_string != "Exit" || input_string != "0" || input_string != "EXIT")
    {
        Check_User_Name(input_string ,customer_cls);
    }
}



user * Increase_Class(user * old_class )
{
    static bool first_entrance = false;

    if (first_entrance == false)
    {
        first_entrance = true;

        user * new_class = new user ;

        global_count++;

        return new_class;
    }
        else
        {
            user * new_class = new user[global_count + 1];

            for (size_t i = 0; i < global_count ; i++)
            {
                new_class[i] = old_class[i];
            }
            
            delete [] old_class;
            global_count++;
            return new_class;
        }
}



void user:: set_user_name(const string & username)
{
    user_name = username;
}


string user::get_user_name()
{
    return user_name;
}


void user::set_ip (string ip_string)
{
    ip_of_account = ip_string;
}


string user::get_ip()
{
    return ip_of_account;
}