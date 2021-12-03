#include"../inc/include.h"
#include<iostream>
#include<cctype>
#include<ctime>
#include<string>
#include<windows.h>

#define SIZE 4

using namespace std ;

extern unsigned int global_count ; // at the first time ---> 0
bool end_account_range = false; // We can't add a new account when all the card numbers are gone .
unsigned short int chance_for_end_range = 3; // We give only 3 chances to the user not to enter the create section anymore .



user :: user() // constructore just create opening and expiration date of account ..
{
    time_t now = time(0);

    tm * date = localtime(&now);

    opening_account_year = date->tm_year + 1900; // we recive year from this function and store it .
    opening_account_month = date->tm_mon + 1; // we recive month from this finction and store it .
    opening_account_day = date->tm_mday; // we recive day from this finction and store it .

    expiration_account_year = opening_account_year + 2; // now we can make expiration of account . we add two year to it .
}


/* ------------------------------------------------>    SET Class Functions   <------------------------------------------------------ */

void user :: set_user_name(string username) // this function set entrance user_name with class variable .
{
    user_name = username; // store entrance username in the class variable .
}



void user :: set_ip (string ip_string) // set ip that entered in the create time .
{
    ip_of_account = ip_string; // store entrance of ip in the ip variable of class.
}



void user:: set_card_number(unsigned int ranmdom_number) // set card number of class variable with parameter .
{
    card_number = ranmdom_number ;
}



void user :: set_extra_ip(user *& customer_class ,unsigned short int target_account , string ip_string)
{ /* set extra ip`s in ip list of accounts  */

    Increase_String_Array(target_account ,customer_class); // increase size of array
    count_extra_ip++; // added one by one to extra ip variable .

    ip_lists_ptr[count_extra_ip - 1] = ip_string; // put ip string in variable 
}




/* ------------------------------------------------>    GET Class Functions   <------------------------------------------------------ */

string user :: get_user_name() // return username of customer account .
{
    return this->user_name; // return username of account from class variable .
}



string user :: get_ip() // return ip of cutomer account .
{
    return this->ip_of_account; // return ip of account from class variable .
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



unsigned int user :: get_card_number() // return card number of account.
{
    return card_number;
}



string user :: get_extra_ip(unsigned short int len) // indicate extra ip`s
{
    return ip_lists_ptr[len];
}



unsigned short int user :: get_count_extra_ip() // indicate how many ip`s we have .
{
    return count_extra_ip;
}



long long int user :: get_balance()
{
    return balance;
}


/* ------------------------------------------------>    OTHER Class Functions   <------------------------------------------------------ */

void user :: Increase_Extra_Ip_List(unsigned short int target_account , user *& customer_class)
{
    if (count_extra_ip == 0)
    {
        ip_lists_ptr = new string;
        return;
    }
        else
        {
            string * new_string = new string [count_extra_ip + 1];

            for (size_t i = 0; i < count_extra_ip ; i++)
            {
                new_string[i] = customer_class[target_account - 1].get_extra_ip(i);
            }

            if (count_extra_ip == 1)
            {
                delete ip_lists_ptr ;
                ip_lists_ptr = new_string;
            }

                else
                {
                    delete [] ip_lists_ptr;
                    ip_lists_ptr = new_string;
                }

             return;   
        } // end of else if (count_extra_ip >= 1)
}



void user :: decrease_money(long long int input_money)
{
    balance -= input_money;
}



void user :: increase_money(long long int input_money)
{
    balance += input_money;
}



void user :: renew_date_account()
{
    expiration_account_year += 2;
}




/* **************************************  border between class function and another ********************************************** */


/* ------------------------------------------------>    OTHER Functions   <------------------------------------------------------ */

void Re_Enter_String(string & input_string , user *& customer_class) // In this section, we check that the string is not empty
{ // if entrance string equal to exit command we close the program .

    system("cls");

    if (global_count == 9999)
    {
        Print_Eror("You Can Not Register A New Bank Account" , "Out Of Range") ;
        end_account_range = true;
    }
    

    unsigned short int chance = 3; // we give the users 3 chance to enter correct string . 

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
        } // end of while (true)


        Check_Exit_Command(input_string); // if user enter exit command this function can recognize and exit .

        Recognize_Commands(input_string ,customer_class); // at the end of this function we put input string validation .
        
        if (global_count == 3)
        {
            for (size_t i = 0; i < global_count ; i++)
            {
                cout << endl << "--------------------------------------------" << endl;
                cout << "user name \t" << customer_class[i].get_user_name() << endl;
                cout << "ip \t" << customer_class[i].get_ip() << endl;
                cout << "yeaer month day \t" << customer_class[i].get_opening_year()
                << " " << customer_class[i].get_opening_month() << " " << customer_class[i].get_opening_day() << endl;
                cout <<"expiration of account " << customer_class[i].get_expiration_year() << endl;
                cout << "Card NUmbver\t" << customer_class[i].get_card_number() << endl;
                
                if (customer_class[i].get_count_extra_ip() != 0)
                {
                    for (size_t j = 0; j < customer_class[i].get_count_extra_ip() ; j++)
                    {
                        cout << "extra ip\t" << customer_class[i].get_extra_ip(j) << endl;
                    }
                }
                cout << "balance\t" << customer_class[i].get_balance() << endl;
            }
            exit(EXIT_SUCCESS);
        }   
    } // end of loop (while)
} // end of function (re_enter_string)



void Recognize_Commands(string & input_string , user *& customer_class) // recognize command and execute relavent command .
{
    string default_command[] = {"create" , "add_ip" ,"renewal" ,"deposit"}; // contain all of known commands in the app .

    unsigned short int number_of_known_command ; // show us which command to execute .

    if(Is_Command_Entred(input_string ,number_of_known_command ,default_command) == false) // check that entrance command exist or not .
    {
        return;
    }


    unsigned short int len_default_string; // store length of known command like "create" command .
    string save_username; // add username to this variable .


        len_default_string = default_command[number_of_known_command].size(); // calculate length of "create" command .


        if( Is_Char_Exist(' ' ,input_string , len_default_string , false) == false )
        {  // like this createmamad .. we should be put space between command and useranme .

            Print_Eror("Invalid Entrance Command" , "empty");
            system("pause");
            return;
        }

        
        len_default_string++; // go to next word index ..


        Read_User_Name(input_string ,len_default_string ,save_username); // read user name from entrance string .
        int user_target ;

        if (number_of_known_command == 0)
        {
            if( UserName_Checker(save_username ,input_string ,customer_class ,false ,user_target) == false )
            {
                return ;
            }
        }
            else
            {
                if( UserName_Checker(save_username ,input_string ,customer_class ,true ,user_target) == false )
                {
                    return ;
                }
            }
            


        if ( Is_Char_Exist('\0' ,input_string ,len_default_string ,false) == true ) // like this create mamad
        {
            Print_Eror("We Can Not Detect IP" , "IP Not Entered");
            system("pause");
            return;
        }

    
    switch (number_of_known_command) // Each command has its own text
    {
        case 0 : // mean user entered "create" command .

        Create_Account(customer_class ,save_username ,input_string ,len_default_string); // create account with entrance information.
        
        break; // break of switch case 

        case 1 : // mean user entered "Add_ip" command .

        Add_Extra_IP(customer_class ,len_default_string ,input_string);

        break;

        case 2 :

        Re_New_Account_Date(customer_class ,input_string ,len_default_string ,user_target);

        break;

        case 3 :

        Deposit(len_default_string ,input_string ,customer_class ,user_target);

        break;
    } // end if switch (number_of_known_command)

} // end of function (recognize_command) .



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
            
            if (global_count == 1)
            {
                delete old_class;
            }
                else
                {
                    delete [] old_class;
                }
                
            global_count++; // we added one class to pre classes and we plus it .
            return new_class;
        } // end of else 
} // end of function (increase array)



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
} // end of fuction (print eror)



void Create_And_Check_Card_Number(user *& customer_class) // create random card number between 1 and 9999 . 
{
    srand(time(nullptr));
    static bool first_entrance = false; // at the first time we can not compare with previous card numbers .
    unsigned int random_card_number = rand() % 9999 + 1 ; // create random number .

    if (first_entrance == false) // at the first time .
    {
        first_entrance = true;
        customer_class[global_count - 1].set_card_number(random_card_number);
        return;
    }

    bool repetitive_number_exist = false; // false mean : we was not same card number .
    
    while (true)
    {
        for (size_t i = 0; i < global_count - 1 ; i++) // check all of card numbers .
        {
            if (customer_class[i].get_card_number() == random_card_number)
            {
                repetitive_number_exist = true ; // mean we found same card number .
                break;
            }
        }

        if (repetitive_number_exist == true) // that`s mean we have repetitve card number and we must create another one .
        {
            random_card_number = rand() % 9999 + 1 ; // create again .
        }
            else // that`s mean the constructed number is not repetitive .
            {
                customer_class[global_count - 1].set_card_number(random_card_number); 
                return ;
            }
    } // end of loop (for)
} // end of function (create and check card number)



void Check_Exit_Command(string & input_string) // check if entrance string had an exit command . execute exit .
{
    if (input_string == "0") // one of exit command 
    {
        system("cls");
        
        cout << "+      =       =        =        =        =        =        =        =      +" << endl;
        cout << "|                                                                           |" << endl;
        cout << "     !#!   You Entered Exit Command And We Have To Close The Program   !#!" << endl;
        cout << "\t\t\t!#!   End Of Program   !#!" << endl;
        cout << "|                                                                           |" << endl;
        cout << "+      =       =        =        =        =        =        =        =      +" << endl;
        exit(EXIT_SUCCESS); // exit .
    }

    for (size_t i = 0; i < input_string.size() ; i++) // cast all of string to lower case .
    {
        input_string[i] = tolower(input_string[i]);
    }
    
    
    if (input_string == "exit")
    { // When the exit order was entered we close the program .
        system("cls");
        cout << "+      =       =        =        =        =        =        =        =      +" << endl;
        cout << "|                                                                           |" << endl;
        cout << "     !#!   You Entered Exit Command And We Have To Close The Program   !#!" << endl;
        cout << "\t\t\t!#!   End Of Program   !#!" << endl;
        cout << "|                                                                           |" << endl;
        cout << "+      =       =        =        =        =        =        =        =      +" << endl;
        exit(EXIT_SUCCESS); // exit .
    }
} // end of function (check exit command )



bool Validation_After_Colon(string & input_string ,unsigned short int len_default_string ,user *& customer_class)
{ 
    if ( Is_Char_Exist('\0' , input_string ,len_default_string ,false) == true ) // like this --> create mamad:
    {
        Print_Eror("We Can Not Detect IP" , "IP Not Entered");
        system("pause");
        return false;
    }
    

    if ( Is_Char_Exist('.' , input_string ,len_default_string ,false) == true ) // like this --> create mamad:.
    {
        Print_Eror("IP Not Entered . Just Dot Entered" , "Invalid IP Entered");
        system("pause");
        return false ;
    }

    return true ;
}



void Display_Loading() // displlay Loading . . . . . . .
{
    unsigned int number = 0;

    while (number < 2)
    {
        system("cls");
        cout << "Loading" ;

        for (size_t i = 0; i < 10; i++)
        {
            Sleep(50);
            cout << " ." ;
        }
        number++;
    }
}




/* ------------------------------------------------>    is Functions   <------------------------------------------------------ */

bool Is_Repetitive_UserName(user *& customer_class , string & username , bool valid_user_bl ,int & target_account) // Prevents the same name from being added to the bank account
{
    if (valid_user_bl == false) // if entrance string invalid we force the user to enter user name again .
    {
        target_account = -404;
        return true; // Because we wanted to manage this with a one function . we also consider this repititve .
    } // To force the user to enter another username
    
    for (size_t i = 0; i < global_count ; i++) // check all previous user name .
    {
        if (username == customer_class[i].get_user_name())
        {
            target_account = i;
            return true; // mean we found repititve username .
        }
    }
    target_account = 404;
    return false; // mean entrance username was not amoung the previous usernames .
} // end of function (is_repetitve_username)



bool Is_Repetitive_ip(user *& customer_class , string & ip_string , bool valid_ip_bl ,int & target_account) // prevant the same ip and check it .
{
    if (valid_ip_bl == false) // mean ip is invalid .
    {
        target_account = -404;
        return true; // because we want to manage this . we also consider invalid ip repetitve .
    }
    

    for (size_t i = 0; i < global_count; i++) // check previous ip .
    {
        if (ip_string == customer_class[i].get_ip())
        {
            target_account = i;
            return true; // mean that we found repetitve ip .
        }
            if (customer_class[i].get_count_extra_ip() != 0)
            {
                for (size_t j = 0; j < customer_class[i].get_count_extra_ip() ; j++)
                {
                    if (ip_string == customer_class[i].get_extra_ip(j))
                    {
                        target_account = i;
                        return true;
                    }
                }
            }
    }
    target_account = 404;
    return false; // ip was not amoung previus accounts ip .
} // end of function (is repetitve ip)



bool Is_Command_Entred(string & input_string , unsigned short int & count_default_string ,string * default_command) // if we find command return true else false .
{ /* if command exist in the string return true else return false */

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
} // end of functoin (is command entered)



bool Is_Char_Exist(char word, string & input_string ,unsigned short int index , bool is_digit) // compare entrance word with one of string index
{
    if (is_digit) // if is_number is true we enter this section for number checker.
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
} // end of fuction (is char exist)



bool Is_Valid_UserName(string & username ) // user name validation 
{
        if ( isdigit( username[0] ) ) 
        {// first character of username can not begin with number like this --> create 1mamad

            return false ; // mean that entrance username is not valid .
        }

        for (size_t i = 0; i < username.size() ; i++)
        {
            if (ispunct(username[i]))
            {
                return false; // mean that etrance userame is not valid 
            }
        }

        return true;
} // end of function (is valid username)



bool Is_Valid_IP(string & ip_string) // ip validation 
{
    unsigned short int count_ip_dot = 0; // calculate dots in the ip .
    unsigned short int count_part_digit = 0; // calculate part of digits because we must have 4 part number .
    /* valid ip have 4 part of number like --->  123.25.147.59 */

    for (size_t i = 0; i < ip_string.size() ;   )
    {
        int convert_number = stoi(&ip_string[i]); // convert string to number .
        count_part_digit++; 

        if (convert_number >= 256) // mean entrance ip is not valid .
        {
            return false;
        }


        while (ip_string[i] != '.' && ip_string[i] != '\0') // we dont want convert dot . so that we cross it .
        {
            i++; // go to next word .
        }


        if ( ( Is_Char_Exist('\0' ,ip_string ,i ,false) == true ) && count_part_digit != 4 )
        { // like this ---> create mamad:1.2
            return false;
        }


        if (ip_string[i] == '.') // dot counter . dot should be 3 .
        {
            count_ip_dot++; // added one by one .
                
            if (count_ip_dot >= 4) // valid ip have 3 dot ---> 1.2.3.4
            {
                return false;
            }

                
            if ( Is_Char_Exist('.' , ip_string ,i + 1 ,false) == true ) // if we have extra dot in ip
            { // like this ---> create mamad:..  ---- create mamad:1.2...
                return false;
            }

            i++; // go to next word .

        } // end outer of if

    } // end of loop (for)

        if ( count_ip_dot >= 4 || count_ip_dot <= 2 ) // if dots invalid we enter this section . like ---> 1.2 or 1.2.3.4.5.6
        {
            return false;
        }

        
        if ( count_part_digit >= 5 || count_part_digit <= 3 ) // if we have invalid ip like ---> 1.2.3.4.5.6
        {
            return false;
        }

    return true;
} // end of function (is valid ip)



bool Is_Enough_Money(user *& customer_class ,long long int money , unsigned short int target_account)
{
    if (customer_class[target_account].get_balance() - money < 0)
    {
        return false;
    }
    return true;
}



bool Is_Renewal_Date_Arrived(user *& customer_class ,unsigned short int target_account) // check renewal date .
{
    time_t now = time(0);

    tm * date = localtime(&now);

    unsigned int this_year = date->tm_year + 1900; // we recive year from this function and store it .
    unsigned int this_month = date->tm_mon + 1; // we recive month from this finction and store it .
    unsigned int this_day = date->tm_mday; // we recive day from this finction and store it .

    if (customer_class[target_account].get_expiration_year() == this_year)
    {
        if (customer_class[target_account].get_opening_month() == this_month)
        {
            if (customer_class[target_account].get_opening_day() == this_day)
            {
                return true;
            }
        }
    }
    return false;
}




/* ------------------------------------------------>    READ Functions   <------------------------------------------------------ */

void Read_User_Name(string & input_string , unsigned short int & begin_len , string & save_username)
{ /* read user name from input string  */

    save_username.clear();

    while ( input_string[begin_len] != ':' && input_string[begin_len] != '\0' ) // read string until reaches to : 
    {
        save_username += input_string[begin_len]; // Isolation of usernames
        begin_len++; // go to next word .
    }
} // end of read user name .



void Read_IP(string & input_string , unsigned short int & begin_len , string & save_ip)
{ /* read ip from input string  */
    save_ip.clear();
    while (input_string[begin_len] != '\0' && input_string[begin_len] != ':') 
    { /* adding valid ip to another string (ip isolation) */

        save_ip += input_string[begin_len]; // added ip to save_ip variable .
        begin_len++; // go to next word .
    }

} // end of function (read ip)




/* ------------------------------------------------>    COMMANDS Functions   <------------------------------------------------------ */

void Create_Account(user *& customer_class ,string & save_username ,string & input_string ,unsigned short int & len_default_string)
{ /* create account with entrance inforamtion and validation of information. */
        string save_ip; // add user`s ip to this variable .

        if (end_account_range == true) // We have restrictions for creating an account
        {
            if (chance_for_end_range == 0)
            {
                Print_Eror("You Tried 3 Times To Enter This Section" , "Invalid Activity");
                cout << "End Of Program" << endl;
                exit(EXIT_FAILURE);
            }
            
            Print_Eror("You Can Not Register A New Bank Account" , "Out Of Range") ;
            return ;
        }
        

        len_default_string++; // go to next word .


        if( Validation_After_Colon(input_string ,len_default_string ,customer_class) == false)
        {
            return;
        }

        Read_IP(input_string ,len_default_string ,save_ip); // read ip from input string .

        int target_account ;

        if( IP_Checker(save_ip ,input_string ,customer_class ,false ,target_account) == false )
        {
            return ;
        }
        
        customer_class = Increase_Class(customer_class); // add one by one to acounts and copy before accounts .

        customer_class[global_count - 1].set_user_name(save_username); // global_count Indicates how many classes are made .
        customer_class[global_count - 1].set_ip(save_ip); // when we have 2 class . we must add information to class[1]

        Create_And_Check_Card_Number(customer_class); // create random card number (unique).

} // end of function (create accout)



void Add_Extra_IP(user *& customer_class ,unsigned short int & len_default_string ,string & input_string)
{ /* adding extra ip to account . */

    len_default_string++; // go to next word of ':' .

    if ( Validation_After_Colon(input_string ,len_default_string ,customer_class) == false )
    {
        return ;
    }

    string save_ip; // define variable .

    while (true) // multyiple IP`s maybe be entered .
    {
        Read_IP(input_string ,len_default_string ,save_ip); // read ip from input string .

        int target_account ;

        if( IP_Checker(save_ip ,input_string ,customer_class ,false ,target_account) == false )
        {
            return ;
        }

        if (input_string[len_default_string] != ':' && input_string[len_default_string] == '\0') // if we reached last ip
        {
            customer_class[global_count - 1].set_extra_ip(customer_class ,global_count ,save_ip); // set ip 
            break;
        }

        customer_class[global_count - 1].set_extra_ip(customer_class ,global_count ,save_ip); /// set ip
        len_default_string++; // go to next word .
    }
}



void Re_New_Account_Date(user *& customer_class,string & input_string ,unsigned short int & len_default_string ,int user_target)
{
    len_default_string++;

    if( Validation_After_Colon(input_string ,len_default_string ,customer_class) == false )
    {
        return ;
    }

    string save_ip;
    int ip_target;

    Read_IP(input_string ,len_default_string ,save_ip);
    

    if( IP_Checker(save_ip ,input_string ,customer_class ,true ,ip_target) == false )
    {
        return ;
    }


    if (user_target == ip_target)
    {
        if( Is_Enough_Money(customer_class ,20000 ,user_target) )
        {
            cout << customer_class[user_target].get_balance() << endl;
            cout << user_target << "\t" << ip_target << endl;

            customer_class[user_target].decrease_money(20000);

            customer_class[user_target].renew_date_account();

            cout << endl << "Renewal Successful" << endl;
            system("pause");
        }
            else
            {
                cout << endl << "Not Enough Money" << endl;
                system("pause");
                return ;
            }
        
    }
        else
        {
            cout << "entrance user and ip does not match" << endl;
            system("pause");
            return ;
        }
}



void Deposit(unsigned short int & len_default_string ,string & input_string , user *& customer_class ,int user_target)
{
    string save_ip = "nothing";

    len_default_string++;

    if( Validation_After_Colon(input_string ,len_default_string ,customer_class) == false )
    {
        return ;
    }
    Read_IP(input_string ,len_default_string ,save_ip);

    if (input_string[len_default_string] == '\0')
    {
        Print_Eror("The Input Command Is Not Complete" , "empty");
        system("pause");
        return;
    }
    

    int ip_target ;

    if( IP_Checker(save_ip ,input_string ,customer_class ,true ,ip_target) == false )
    {
        return ;
    }

    if (user_target == ip_target)
    {
        if ( Is_Renewal_Date_Arrived(customer_class ,user_target) )
        {
            char renew_ch ;

            cout << "Do You Want To Renew Bank Account ?? ( Pay 10/000 T )" << endl;
            cout << " 'y' __ 'Y' __ '1' Mean Renew My Account" << endl;
            cout << " 'n' __ 'N' __ '0' Mean Do Not Renew My Account" << endl;
            cout << "if you want return to command line tap in enter" << endl;
            fflush(stdin);
            cin.get(renew_ch);

            if (renew_ch == '\n')
            {
                return;
            }
            

            if (renew_ch == 'y' || renew_ch == 'Y' || renew_ch == '1')
            {
                if ( Is_Enough_Money(customer_class ,20000 ,user_target) )
                {
                    customer_class[user_target].decrease_money(20000);
                    customer_class[user_target].renew_date_account();
                    cout << "#=#    We Renew Your Account For 2 Years    #=#" << endl;
                }
                    else
                    {
                        cout << endl << "Not Enough Money" << endl;
                        system("pasuse");
                        return ;
                    }
                    
            } // end of if (renew_ch == 'y' || renew_ch == 'Y' || renew_ch == '1')
                else if (renew_ch == 'n' || renew_ch == 'N' || renew_ch == '0')
                {
                    cout << "You did not want your bank account to be renewed" << endl;
                    system("pause");
                    return;
                }
                    else
                    {
                        cout << "!!    You Entered Wrong Character    !!" << endl;
                        system("pause");
                        return;
                    }
        } // end of if (is_renewal_date_arrived)
        
        len_default_string++;

        long long int money_reciver;

        if( Money_Checker(money_reciver ,input_string ,customer_class ,len_default_string) == false )
        {
            return ;
        }
        customer_class[user_target].increase_money(money_reciver);
        cout << "$$   The Deposit Was Successfuly   $$" << endl;
        cout << "Deposit ====>   " << money_reciver << "  Toman" << endl;
        system("pause");
    }
}



/* ------------------------------------------------>   CHECKER functions   <------------------------------------------------------ */

bool IP_Checker(string & save_ip ,string & input_string ,user *& customer_class , bool find_ip ,int & target_user) //The IP checking set is stored in this function
{
    bool valid_ip_bl = true; // true mean : entrance ip is valid .
    static bool first_entrance = true;

    if( Is_Valid_IP(save_ip) == false) // ip validation .
    {
        Print_Eror("Your Entrance IP Is Not Valid" , "empty");
        system("pause");
        return false ;
    }


    if (find_ip && first_entrance == false)
    {
        while ( Is_Repetitive_ip(customer_class , save_ip , valid_ip_bl ,target_user) == false ) // we want find ip to execute commands .
        {
            Print_Eror("This IP Does Not Exist" , save_ip);
            cout << "Now Just Enter IP Without Extra Command OR Words" << endl;
            cout << "Like This Example ---> 1.2.3.4 (if you want return to command line tap on enter)" << endl;
            fflush(stdin);
            getline(cin ,save_ip);

            if (save_ip.empty())
            {
                return false ;
            }
            

            Check_Exit_Command(save_ip); // if exit command entered we execute it .

            if ( Is_Valid_IP(save_ip) == false ) // pi validation .
            {
                Print_Eror("Your Entrance IP Is Not Valid" , "empty");
                system("pause");
                valid_ip_bl = false; // mean that entrance ip not valid .
                continue;
            }

            valid_ip_bl = true; // mean that entrance ip is valid .
        }
    }
    
        else if(find_ip == false && first_entrance == false)
        {
            while ( Is_Repetitive_ip(customer_class , save_ip , valid_ip_bl ,target_user) ) // prevent same ip .
            {
                Print_Eror("Someone Has Already Entered This IP" , save_ip);
                cout << "Now Just Enter IP Without Extra Command OR Words" << endl;
                cout << "Like This Example ---> 1.2.3.4 (if you want return to command line tap on enter)" << endl;
                fflush(stdin);
                getline(cin ,save_ip);

                if (save_ip.empty())
                {
                    return false ;
                }

                Check_Exit_Command(save_ip); // if exit command entered we execute it .

                if ( Is_Valid_IP(save_ip) == false ) // pi validation .
                {
                    Print_Eror("Your Entrance IP Is Not Valid" , "empty");
                    system("pause");
                    valid_ip_bl = false; // mean that entrance ip not valid .
                    continue;
                }

                valid_ip_bl = true; // mean that entrance ip is valid .
            }
        }
        

    if (first_entrance == true)
    {
        first_entrance = false;
    }
    return true ;
}



bool UserName_Checker(string & save_username , string & input_string ,user *& customer_class , bool find_username ,int & target_user)
{
    bool valid_username_bl = true; // true mean : entrance username is valid .
    static bool first_entrance = true;

        if ( Is_Valid_UserName(save_username) == false ) // validation of usernaem
        {
            Print_Eror("Invalid User Name . First Character Of User Name Can Not Be Begin Wih Number" ,
                       "Punctuation Character Should Not Be Used");
            system("pause");
            return false ;
        }


    if (find_username && first_entrance == false)
    {
        while ( Is_Repetitive_UserName(customer_class ,save_username ,valid_username_bl ,target_user) == false) // find user name between accounts.
        {
            Print_Eror("This User Name Not Exist" , save_username);
            cout << "Just Enter User Name Without Any Command Or Words" << endl;
            cout << "Liek This Exaple --->  Alex " << endl;
            cout << "Enter User Name Under This Line (if you want return to command line tap on enter)" << endl;
            fflush(stdin);
            getline(cin ,save_username);

            if (save_username.empty())
            {
                return false ;
            }
            

            Check_Exit_Command(save_username); // if exit command entered we execute it .


            if ( save_username[save_username.size() - 1] == ' ') // end of user name can not be space .
            {
                Print_Eror("Can Not Enter Space At The End Of User name" , "empty");
                valid_username_bl = false; // mean that entrance string not valid .
                continue;
            }


            if ( Is_Valid_UserName(save_username) == false ) // username validatiobn .
            {
                Print_Eror("Your Entrance User Name Not Valid" , "empty");
                system("pause");
                valid_username_bl = false; // mean that entrance string not valid 
                continue;
            }

            valid_username_bl = true; // if entrance username in this section is coorect we set true this variable .

        } // end of loop (while)
    } // end of if (find_username && first_entrance == flase)

        else if (find_username == false && first_entrance == false)
        {
            while ( Is_Repetitive_UserName(customer_class ,save_username ,valid_username_bl ,target_user) ) // prevent same username .
            {
                Print_Eror("Someone Has Already Entered This USER_NAME" , save_username);
                cout << "Just Enter User Name Without Any Command Or Words" << endl;
                cout << "Liek This Exaple --->  Alex " << endl;
                cout << "Enter User Name Under This Line :)" << endl;
                fflush(stdin);
                getline(cin ,save_username);

                Check_Exit_Command(save_username); // if exit command entered we execute it .


                if ( save_username[save_username.size() - 1] == ' ') // end of user name can not be space .
                {
                    Print_Eror("Can Not Enter Space At The End Of User name" , "empty");
                    valid_username_bl = false; // mean that entrance string not valid .
                    continue;
                }


                if ( Is_Valid_UserName(save_username) == false ) // username validatiobn .
                {
                    Print_Eror("Your Entrance User Name Not Valid" , "empty");
                    system("pause");
                    valid_username_bl = false; // mean that entrance string not valid 
                    continue;
                }

                valid_username_bl = true; // if entrance username in this section is coorect we set true this variable .

            } // end of loop (while)
        } // end of else if(find_username == flase && first_entrance == false)
        
    if (first_entrance == true) //at the first time should not compare information with previous .
    {
        first_entrance = false;
    }
    return true ;
} // end of function .



bool Money_Checker(long long int & money_reciver ,string & input_string ,user *& customer_class ,unsigned short int & begin_len)
{
    if (input_string[begin_len] == '\0')
    {
        Print_Eror("Invalid Entrance In Money Section (Deposit)" , "empty");
        system("pause");
        return false ;
    }

    unsigned short int save_len = begin_len ;
    bool valid_money = true;

    while (input_string[save_len] != '\0')
    {
        if ( ispunct( input_string[save_len] ) )
        {
            valid_money = false;
            break;
        }

            if (isalpha(input_string[save_len]))
            {
                valid_money = false;
                break;
            }
            save_len++;
    }
    
    if (valid_money == true)
    {
        money_reciver = stoll(&input_string[begin_len]);
        return true;
    }
    
    save_len = 0 ; // re enter len .
    string save_money ;

    while (valid_money == false)
    {
        valid_money = true;

        cout << "Your Entrance Money Is Invalid" << endl;
        cout << "Just Enter Money Without Extra Command Or Word" << endl;
        cout << "our currency based on Toman Like ====> 10/000 Toman " << endl;
        cout << "Like This ----> 25000  (if you want return to command line tap on enter)" << endl;
        fflush(stdin);
        getline(cin ,save_money);

        if (save_money.empty())
        {
            return false ;
        }
        

        while (save_money[save_len] != '\0')
        {
            if ( ispunct( save_money[save_len] ) )
            {
                valid_money = false;
                break;
            }

                if (isalpha(save_money[save_len]))
                {
                    valid_money = false;
                    break;
                }
                save_len++;
        } // end of while (input_string[save_len] != '\0)
    } // end of while (valid_money == false)
    
    money_reciver = stoll(save_money);
    return true ;
}