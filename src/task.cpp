#include"../inc/include.h"
#include<iostream>
#include<cctype>

#define SIZE 1

using namespace std ;

extern unsigned int global_count ; // at the first time ---> 0
bool information_added = true;

void Check_User_Name(string & input_string , user *& customer_class)
{
    string default_command[] = {"create"};

    unsigned short int count_default_string ;

    if(Is_Command_Entred(input_string ,count_default_string) == false)
    {
        Re_Enter_String(input_string ,customer_class);
    }


    string save_username; // add username to this variable .
    string save_ip; // add user`s ip to this variable .
    unsigned int len_default_string; // calculate length of known command like "create" command .
    unsigned short int count_dot = 0; // calculate dots in the ip .
    unsigned short int count_part_digit = 0; // calculate part of digits because we must have 4 part number .
    /* valid ip have 4 part of number like --->  123.25.147.59 */

    switch (count_default_string) // Each command has its own text
    {
        case 0 : // mean user entered "create" command .
        
        if (information_added == true) 
        { /* count_deafult_string = 0 --> "create entered" --- information_added mean befor account used and we can crate new one */

            customer_class = Increase_Class(customer_class); // add one by one to acounts and copy before accounts .
            
        } // end of outer if

        len_default_string = default_command[count_default_string].size(); // calculate length of "create" command .

        // if (input_string[len_default_string] != ' ') // after known command must be space . create username:ip  ...
        // {
        //     Print_Eror("There should be a space after the command" , "Invalid Entrance String");
        //     system("pause");
        //     information_added = false; // maen pre account was not use ..
        //     Re_Enter_String(input_string , customer_class); // user must enter string agian ..s
        // } // end of if 
        
        len_default_string++; // go to next word index ..

        // if ( isdigit( input_string[len_default_string] ) ) // We cannot put a number at the beginning of the name
        // {
        //     Print_Eror("Invalid User Name . User Name Can not Begin With Number");
        //     system("pause");
        //     information_added = false; // mean pre account was not use ...
        //     Re_Enter_String(input_string , customer_class); // enter string again .
        // } // end of if
        

        while (input_string[len_default_string] != ':' && input_string[len_default_string] != '\0') // read string until reaches to : 
        {
            save_username += input_string[len_default_string]; // Isolation of usernames
            len_default_string++; // go to next word .
        }
        
        // if (input_string[len_default_string] == '\0') // if after username we reach to end .. like --> create mamad 
        // {
        //     Print_Eror("We Can Not Detect IP" , "IP Not Entered");
        //     system("pause");
        //     information_added = false; // pre account was not use .
        //     Re_Enter_String(input_string , customer_class); // enter string again .
        // } // end of if
        
        len_default_string++; // go to next word .

        // if (input_string[len_default_string] == '\0') // like ---> create mamad:    we have not ip 
        // {
        //     Print_Eror("We Can Not Detect IP" , "IP Not Entered");
        //     system("pause");
        //     information_added = false; // pre account was not use .
        //     Re_Enter_String(input_string , customer_class); // enter string again .
        // } // end of if 
        
        // if (input_string[len_default_string] == '.') // like ---> create mamad:.   without ip numbers .
        // {
        //     Print_Eror("IP Not Entered . Just Dot Entered" , "Invalid IP Entered");
        //     system("pause");
        //     information_added = false; // pre account was not use .
        //     Re_Enter_String(input_string ,customer_class); // enter steirg again .
        // } // end of if
        
        
        while (input_string[len_default_string] != '\0') // read ip until reaches to end .
        {
            int convert_number = stoi(&input_string[len_default_string]); // convert stirng to int for check valid ip .
            count_part_digit++;

            // if (convert_number >= 256) // ip validation
            // {
            //     Print_Eror("IP should be between 0 and 255" , "Invalid IP Entered");
            //     system("pause");
            //     information_added = false; // pre account was not use .
            //     Re_Enter_String(input_string ,customer_class); // string must be enter again .
            // } // end of if 
            

            while (input_string[len_default_string] != '.' && input_string[len_default_string] != '\0') 
            { /* adding valid ip to another string (ip isolation) */
                save_ip += input_string[len_default_string]; 
                len_default_string++; // go to next word .
            }
            
            // if (input_string[len_default_string] == '\0' && count_part_digit != 4) // like ---> create mamad:123
            // {
            //     Print_Eror("Invalid IP Entered");
            //     system("pause");
            //     information_added = false; // pr acoount was not use .
            //     Re_Enter_String(input_string , customer_class); // enter string again .
            // } // end of if
            
            if (input_string[len_default_string] == '.') // dot counter . dot should be 3 .
            {
                count_dot++; // added one by one .
                
                // if (count_dot >= 4)
                // {
                //     Print_Eror("IP Should Be 3 Dots" , "Invalid IP Entered");
                //     system("pause");
                //     information_added = false; // pre account was not use .
                //     Re_Enter_String(input_string , customer_class); // enter string again.
                // } // end of inner if

                    // if (input_string[len_default_string + 1] == '.')
                    // {
                    //     Print_Eror("We Detect Extra Dots In IP" , "Invalid IP Entered");
                    //     system("pause");
                    //     information_added = false; // pre account was not use .
                    //     Re_Enter_String(input_string , customer_class); // enter string again.
                    // }
                    
                save_ip += input_string[len_default_string]; // adding dot to ip_string .
                len_default_string++; // go to next word .
            } // end outer of if
        } // rnd og while 

        // if (count_dot <= 2 || count_dot >= 4 ) // valid ip should be have 3 dots . ---> create mamad:123.45.104.36
        // {
        //     Print_Eror("Invalid IP Entered");
        //     system("pause");
        //     information_added = false; // pre account was not use .
        //     Re_Enter_String(input_string ,customer_class); // enter string again .
        // }

        // if ( count_part_digit <= 3 )
        // {
        //     Print_Eror("A valid IP has 4 sections of numbers");
        //     system("pause");
        //     information_added = false;
        //     Re_Enter_String(input_string ,customer_class);
        // }

        customer_class[global_count - 1 ].set_user_name(save_username); // global_count Indicates how many classes are made .
        customer_class[global_count - 1].set_ip(save_ip); // when we have 2 class . we must add information to class[1]
        // customer_class->set_user_name(save_username);
        // customer_class->set_ip(save_ip);
        // cout << "global count " << global_count << endl;
        // cout << "address " << customer_class << endl;
        // cout << customer_class[global_count - 1].get_user_name() << endl;
        // cout << customer_class[global_count - 1].get_ip() << endl;
        // system("pause");
        /* because it`s begin from 0  */
        information_added = true; // that`s mean we used the created account .and now we can add account for next user .
        cout << "address of class\t" << customer_class <<  endl;
        break; // break of switch case 
    
    }

}




void Re_Enter_String(string & input_string , user *& customer_class) // In this section, we check that the string is not empty
{ // if entrance string equal to exit command we close the program .
    system("cls");
    unsigned short int chance = 3; // we give the user`s 3 chance to enter correct string . 

    while (true) // The output check command is implemented in this function
    {
        cout << endl << "Enter Command Under This Line ...." << endl;
        fflush(stdin); // clear buffer .
        getline(cin , input_string);

        while (input_string.empty()) // The input string should not be empty
        {
            system("cls");

            if (chance == 0) // that mean user tried all of 3 chance and we have to closs the program.
            {
                system("cls");
                Print_Eror("You Have  #  3  #  Invalid Attempts And We Have To Closs The Program" , "empty");
                exit(EXIT_FAILURE); // exit 
            }
            
            cout << "!!!   You Have  ~  " << chance << "  ~  Chance To Enter Valid Command   !!!" << endl;
            cout << "Order Can not Be Empty . Please Enter Command Under This Line ..." << endl;
            fflush(stdin); // clear buffer .
            getline(cin ,input_string);
            chance--; // decrease chance one by one 
        }
        
        if (input_string == "Exit" || input_string == "exit" || input_string == "EXIT" || input_string == "0")
        { // When the exit order was entered we close the program .
            system("cls");
            cout << "!!   You Entered Exit Command In The First Of Program   !!" << endl;
            cout << "\t!!   End Of Program   !!" << endl;
            exit(EXIT_SUCCESS); // exit .
        }
        
        Check_User_Name(input_string ,customer_class); // at the end of this function we put input string validation .
        
        if (customer_class == nullptr)
        {
            cout << "address after check function ------->\t" << customer_class << endl;
        }
        

        break;
    }
}



user * Increase_Class(user *& old_class ) // add one class to pre classes and copy pre classes to new class that increased .
{
    static bool first_entrance = false; // in the first entrance we enter to first condition .

    if (first_entrance == false) // mean we enter this function at the first time .
    {
        first_entrance = true;
        user * new_class = new user; // create one class .
        delete old_class;
        global_count++; // adding to global count . global_coumt was 0 and in this section we will add one to it .
        /* global count here equal to 1 because we create 1 class */
        return new_class;
    }
        else // mean we should be create array of class
        {
            user * new_class = new user[global_count + 1]; // Shows how many classes have been created so far
            /* and we must create global + 1 because we need add one class to pre classes  */

            for (size_t i = 0; i < global_count ; i++) // copy information of pre classes to new classes (size increased)
            {
                new_class[i] = old_class[i];
            }
            
            delete [] old_class;
            global_count++; // we added one class to pre classes and we plus it .
            return new_class;
        }
}


void user:: set_user_name(string username) // this function set entrance user_name with class variable .
{
    user_name = username;
}


string user::get_user_name() // return username of customer account .
{
    return this->user_name;
}


void user::set_ip (string ip_string) // set ip that entered in the create time .
{
    ip_of_account = ip_string;
}


string user::get_ip() // return ip of cutomer account .
{
    return this->ip_of_account;
}

void Print_Eror(string first_string ,string second_string )
{
    for (size_t i = 0; i < first_string.size() / 2 ; i++)
    {
        if (i == 0 || i == (first_string.size() / 2 ) - 1 )
        {
            cout << "+  ";
            continue;
        }

        cout << "-  " ;
    }
    cout << endl;
    cout << endl << "      " << first_string << endl;
    if (second_string != "empty")
    {
        cout << "            " << second_string << endl;
    }
    
    cout << endl;
    for (size_t i = 0; i < first_string.size() / 2 ; i++)
    {
        if (i == 0 || i == (first_string.size() / 2 ) - 1 )
        {
            cout << "+  ";
            continue;
        }

        cout << "-  " ;
    }
}

bool Is_Command_Entred(string & input_string , unsigned short int & count_default_string)
{
    string default_command[] = {"create"};
    bool find_command = false;
    int find_out_put;
    
        for (count_default_string = 0; count_default_string < SIZE ; count_default_string++)
    {
        find_out_put = input_string.find(default_command[count_default_string]);

        if (find_out_put >= 0)
        {
            find_command = true;
            break;
        }
    }
    
    if (input_string.size() == default_command[count_default_string].size()) 
    { // mean entrance string not complete and just entered known commands .

        Print_Eror("You Just Entered Known Command without Information" , "Command Not Complete");
        system("pause");
        return false;
    }

    if (find_command == false) // When the command is entered does not match the commands ..
    {
        Print_Eror("Command Not Found" , "empty");
        system("pause");
        return false;
    }
    
    if (find_command == true) // mean command find in the entrance string ...
    {
        if (find_out_put != 0) //that mean command was not entered at the first of string ..
        {
            Print_Eror("Command Must Be In The First Of String" , "empty");
            system("pause");
            return false;
        }
    }

    return true;
}