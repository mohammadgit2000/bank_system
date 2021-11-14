#include<iostream>
#include"include.h"

using namespace std ;

unsigned int global_count = 0;

int main()
{
    user * customer = nullptr;
    unsigned short int chance = 3;
    string input_string;
    cout << "We Will Continue To Work Until The Exit Command Is Entered" << endl;
    cout << "!!  Write One Of Exit Command To Exit ---> exit - Exit - EXIT - 0  !!" << endl;
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
    
    chance = 3;

    if (input_string == "Exit" || input_string == "exit" || input_string == "EXIT" || input_string == "0")
    {

        system("cls");
        cout << "!!   You Entered Exit Command In The First Of Program   !!" << endl;
        cout << "\t!!   End Of Program   !!" << endl;
        exit(EXIT_SUCCESS);
    }
    

    while (input_string != "exit" || input_string != "Exit" || input_string != "0" || input_string != "EXIT")
    {
        
    }
    

    return 0 ;
}