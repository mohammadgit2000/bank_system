#include"../inc/include.h"
#include<iostream>
#include<cctype>
#include<ctime>

#define SIZE 1

using namespace std ;

extern unsigned int global_count ; // at the first time ---> 0
bool information_added = true;

void Check_User_Name(string & input_string , user *& customer_class)
{
    string default_command[] = {"create"};

    unsigned short int number_of_known_command ;

    if(Is_Command_Entred(input_string ,number_of_known_command) == false)
    {
        Re_Enter_String(input_string ,customer_class);
    }


    string save_username; // add username to this variable .
    string save_ip; // add user`s ip to this variable .
    unsigned int len_default_string; // calculate length of known command like "create" command .
    unsigned short int count_dot = 0; // calculate dots in the ip .
    unsigned short int count_part_digit = 0; // calculate part of digits because we must have 4 part number .
    /* valid ip have 4 part of number like --->  123.25.147.59 */

    switch (number_of_known_command) // Each command has its own text
    {
        case 0 : // mean user entered "create" command .
        
        if (information_added == true) 
        { /* count_deafult_string = 0 --> "create entered" --- information_added mean befor account used and we can crate new one */

            customer_class = Increase_Class(customer_class); // add one by one to acounts and copy before accounts .
            
        } // end of outer if

        len_default_string = default_command[number_of_known_command].size(); // calculate length of "create" command .

        if( Is_Char_Exist(' ' ,input_string , len_default_string , false) == false )
        {
            Print_Eror("Invalid Entrance Command" , "empty");
            system("pause");
            information_added = false; // maen pre account was not use ..
            Re_Enter_String(input_string ,customer_class);
        }
        
        len_default_string++; // go to next word index ..
        
        if ( Is_Char_Exist(' ' , input_string ,len_default_string ,true) == true )
        {
            Print_Eror("Invalid User Name . User Name Can not Begin With Number" , "empty");
            information_added = false; // mean pre account was not use ...
            system("pause");
            Re_Enter_String(input_string ,customer_class);
        }
        

        while ( input_string[len_default_string] != ':' && input_string[len_default_string] != '\0' ) // read string until reaches to : 
        {
            save_username += input_string[len_default_string]; // Isolation of usernames
            len_default_string++; // go to next word .
        }
    
        
        if ( Is_Char_Exist('\0' ,input_string ,len_default_string ,false) == true )
        {
            Print_Eror("We Can Not Detect IP" , "IP Not Entered");
            system("pause");
            information_added = false; // pre account was not use .
            Re_Enter_String(input_string , customer_class); // enter string again .
        }
        

        len_default_string++; // go to next word .


        if ( Is_Char_Exist('\0' , input_string ,len_default_string ,false) == true )
        {
            Print_Eror("We Can Not Detect IP" , "IP Not Entered");
            system("pause");
            information_added = false; // pre account was not use .
            Re_Enter_String(input_string , customer_class); // enter string again .
        }
        

        if ( Is_Char_Exist('.' , input_string ,len_default_string ,false) == true )
        {
            Print_Eror("IP Not Entered . Just Dot Entered" , "Invalid IP Entered");
            system("pause");
            information_added = false; // pre account was not use .
            Re_Enter_String(input_string ,customer_class); // enter steirg again .
        }
        
        
        
        while (input_string[len_default_string] != '\0') // read ip until reaches to end .
        {
            int convert_number = stoi(&input_string[len_default_string]); // convert stirng to int for check valid ip .
            count_part_digit++;

            if ( Is_First_Bigger_Number(convert_number , 256) == true )
            {
                Print_Eror("IP should be between 0 and 255" , "Invalid IP Entered");
                system("pause");
                information_added = false; // pre account was not use .
                Re_Enter_String(input_string ,customer_class); // string must be enter again .
            }

            while (input_string[len_default_string] != '.' && input_string[len_default_string] != '\0') 
            { /* adding valid ip to another string (ip isolation) */

                save_ip += input_string[len_default_string]; 
                len_default_string++; // go to next word .
            }
            

            if ( ( Is_Char_Exist('\0' ,input_string ,len_default_string ,false) == true ) && count_part_digit != 4 )
            {
                Print_Eror("Invalid IP Entered" , "empty");
                system("pause");
                information_added = false; // pr acoount was not use .
                Re_Enter_String(input_string , customer_class); // enter string again .
            }
            

            if (input_string[len_default_string] == '.') // dot counter . dot should be 3 .
            {
                count_dot++; // added one by one .
                
                if ( Is_First_Bigger_Number(count_dot , 4) == true )
                {
                    Print_Eror("IP Should Be 3 Dots" , "Invalid IP Entered");
                    system("pause");
                    information_added = false; // pre account was not use .
                    Re_Enter_String(input_string , customer_class); // enter string again.
                }

                    
                if ( Is_Char_Exist('.' , input_string ,len_default_string + 1 ,false) == true )
                {
                    Print_Eror("We Detect Extra Dots In IP" , "Invalid IP Entered");
                    system("pause");
                    information_added = false; // pre account was not use .
                    Re_Enter_String(input_string , customer_class); // enter string again.
                }

                save_ip += input_string[len_default_string]; // adding dot to ip_string .
                len_default_string++; // go to next word .

            } // end outer of if

        } // end of while 


        if ( ( Is_First_Bigger_Number(count_dot , 4) == true ) || ( Is_First_Bigger_Number(2 , count_dot) == true ) )
        {
            Print_Eror("Invalid IP Entered" , "empty");
            system("pause");
            information_added = false; // pre account was not use .
            Re_Enter_String(input_string ,customer_class); // enter string again .
        }
        
        if ( Is_First_Bigger_Number(3 , count_part_digit) == true )
        {
            Print_Eror("A valid IP has 4 sections of numbers" , "empty");
            system("pause");
            information_added = false;
            Re_Enter_String(input_string ,customer_class);
        }
        

        customer_class[global_count - 1 ].set_user_name(save_username); // global_count Indicates how many classes are made .
        customer_class[global_count - 1].set_ip(save_ip); // when we have 2 class . we must add information to class[1]

        information_added = true; // that`s mean we used the created account .and now we can add account for next user .

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
        first_entrance = true; // true mean that we enter this section at the first time .
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
                new_class[i] = old_class[i]; // copy elements of pre class to new class .
            }
            
            delete [] old_class;
            global_count++; // we added one class to pre classes and we plus it .
            return new_class;
        }
}


void user :: set_user_name(string username) // this function set entrance user_name with class variable .
{
    user_name = username; // store entrance username in the class variable .
}


string user :: get_user_name() // return username of customer account .
{
    return this->user_name; // return username of account from class variable .
}


void user :: set_ip (string ip_string) // set ip that entered in the create time .
{
    ip_of_account = ip_string; // store entrance of ip in the ip variable of class.
}


string user :: get_ip() // return ip of cutomer account .
{
    return this->ip_of_account; // return ip of account from class variable .
}


void Print_Eror(string first_string ,string second_string ) // we make the format from first string .
{ /* take two string and print them in the eror format  */
    cout << endl;

    for (size_t i = 0; i < first_string.size() / 2 ; i++) // to be breif of format we do this ---> /2
    {
        if (i == 0 || i == (first_string.size() / 2 ) - 1 ) // in the fisrt and last of format we put '+' .
        {
            cout << "+  ";
            continue;
        }

        cout << "-  " ; // we make format with this character ' - '  
    }

    cout << endl;
    cout << endl << "      " << first_string << endl; // first eror text writed here .

    if (second_string != "empty") // if we two eror we write here second eror .
    {
        cout << "            " << second_string << endl;
    }
    
    cout << endl;

    for (size_t i = 0; i < first_string.size() / 2 ; i++) // to be breif format we do this --> /2
    {
        if (i == 0 || i == (first_string.size() / 2 ) - 1 ) // in the first and last of foramt we put ' + ' character .
        {
            cout << "+  ";
            continue;
        }

        cout << "-  " ; // we make format with this character ' - ' 
    }

    cout << endl << endl;
}


bool Is_Command_Entred(string & input_string , unsigned short int & count_default_string) // if we find command return true else false .
{ /* if command exist in the string return true else return false */

    string default_command[] = {"create"}; // all of command that we can recognize in this program .
    bool find_command = false; // false means that we can not find default command in the entracne string .
    int find_out_put; // we store out put of find function in this variable .
    
        for (count_default_string = 0; count_default_string < SIZE ; count_default_string++)
    {
        find_out_put = input_string.find(default_command[count_default_string]);

        if (find_out_put >= 0) // means that we find command in the string .
        {
            find_command = true; // means that we find command .
            break;
        }
    }
    
    if (input_string.size() == default_command[count_default_string].size()) 
    { // mean entrance string not complete and just entered known commands . like this example ---> create 

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
        { /* maybe like this example ---> abcd create mamad:1.2.3.4 */

            Print_Eror("Command Must Be In The First Of String" , "empty");
            system("pause");
            return false;
        }
    }

    return true;
}


user :: user() // constructore just create opening and expiration date of account ..
{
    time_t now = time(0);

    tm * date = localtime(&now);

    opening_account_year = date->tm_year + 1900; // we recive year from this function and store it .
    opening_account_month = date->tm_mon + 1; // we recive month from this finction and store it .
    opening_account_day = date->tm_mday; // we recive day from this finction and store it .

    expiration_account_year = opening_account_year + 2; // now we can make expiration of account . we add two year to it .
}


unsigned short int user :: get_opening_year() // return opening yeaer of account .
{
    return opening_account_year ; // return opening year of account from class .
}


unsigned short int user :: get_opening_month() // return opening month of account .
{
    return opening_account_month; // return opening month of account from class
}


unsigned short int user :: get_opening_day() // return opening day of account .
{
    return opening_account_day ; // return opening day of account from class .
}


unsigned short int user :: get_expiration_year() // return expiration of account .
{
    return expiration_account_year ; //return expiration of account feom class .
}


bool Is_Char_Exist(char word, string & input_string ,unsigned short int index , bool is_number) // compare entrance word with one of string index
{
    if (is_number) // if is_number is true we enter this section for number checker.
    {
        if ( isdigit( input_string[index] ) ) // We cannot put a number at the beginning of the name
        {
            return true ; // means that there is number in the index of string .
        }

        return false; // means that there is not number in the index of string .
    }
        else // if is_number is false we enter this section for character checker .
        {
            if (input_string[index] == word) 
            {
                return true; // mean that there is given character in the index of string .
            }

            return false; // means that there is not character in the index of string .
        }
}


bool Is_First_Bigger_Number(int first_number ,int second_number ) // if first number bigger than second number we return true .
{
    return first_number >= second_number ; // if fisrt number bigger than second number we return true else return false .
}