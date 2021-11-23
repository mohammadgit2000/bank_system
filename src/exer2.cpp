#include<iostream>
#include"../inc/include.h"
#include<windows.h> // for use in Sleep Function

using namespace std ;

unsigned int global_count = 0;

int main()
{
    // user * customer_cls = nullptr; // class user ..
    user * customer_cls = nullptr;
    string input_string = "for first entrance"; // recive string from input ...

    cout << "We Will Continue To Work Until The Exit Command Is Entered" << endl;
    cout << "!!  Write One Of Exit Command To Exit ---> exit - Exit - EXIT - 0  !!" << endl;
    // Sleep(10000);
    system("cls");
    
    Re_Enter_String(input_string , customer_cls);


    

    return 0 ;
}