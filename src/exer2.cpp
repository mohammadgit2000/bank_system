#include<iostream>
#include"../inc/include.h"

using namespace std ;

unsigned int global_count = 0;

int main()
{
    user * customer_cls = nullptr; // class user ..
    string input_string = "enter"; // recive string from input ...

    cout << "We Will Continue To Work Until The Exit Command Is Entered" << endl;
    cout << "!!  Write One Of Exit Command To Exit ---> exit - Exit - EXIT - 0  !!" << endl;

    Re_Enter_String(input_string , customer_cls);

    cout << customer_cls[global_count].get_user_name() << endl;
    cout << customer_cls[global_count].get_ip() << endl;
    

    return 0 ;
}