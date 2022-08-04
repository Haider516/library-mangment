
#include <iostream>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "library.h"
#include "Calculus_lib.h"
#include  "science_lib.h"
#include "member.h"

using namespace std;
void get_PASS_CHECK(char pin[])
{
    for (int i = 0; i < 4; i++)
    {
        pin[i] = _getch();
        cout << "*";
    }
    pin[3] = '\0';
    if (!strcmp(pin, "085"))
        cout << endl << "Your are valid user : " << pin;
    else
        if ((strcmp(pin, "085")) != 0)
        {
           // int i;
            cout << endl << "Your are NOT A valid user : ";

            exit(0);
        }

    _getch();

}

void program_start_display()
{
    cout << "\t\t\t\tLIBRARY\n\t\t\tMUNICIPAL LIBRARY ";
    cout << "\n\t\tADDRESS : MURREE RD, LIAQUAT BAGH\n\t\tRAWALPINDI, PUNJAB 46000" << "\n\t\t\t pin: 085";
}

void  get_login_credential()
{
    string user_name;
    char pass_word[4];
    cout << "\n-------------------------------------------\n";
    cout << " \tFACULTY LOGIN :";
    cin >> user_name;
    cout << "\tFACULTY PASSWORD :";
    //cin >> pass_word;
    get_PASS_CHECK(pass_word);
    cout << "\n--------------------------------------------";

}

void randoM()          //........THIS FUNCTION IS  USED  IN THE FUNCTION  options_for_faculty 
{

    int  op;

    cout << "\nCHOOSE THE OPTION  TO GET IN LIBRARY DOMAIN\n";
    cout << "\n 1.=>PHYSICS BOOK PORTION\n";
    cout << "\n 2.=>CALCULUS BOOK PORTION\n"; cin.ignore(); cout << endl;
    cin >> op;
    switch (op)
    {
    case(1):
    {
        system("CLS");
        cout << "\nPHYSICS BOOKS CORNOR....................... \n";
        Science_lib obj;
        obj.Member_Info_choices();
        obj.get_choice();
        cout << endl;
        break;
    }

    case(2):
    {
        system("CLS");
        cout << "\nCALCULUS BOOKS CORNOR...................... \n";
        Calcu_lib obj;
        obj.Member_Info_choices();
        obj.get_choice();
        cout << endl;
        break;
    }
    default:
    {
        cout << "PRESS ANY  KEY TO  EXIT..";
        break;
    }

    }
}

//OPTION FOR   SCIENCE LIBRARY______________
void OPTION_FOR_VISITING_MEM()
{

start:
    int  op;
    Science_lib obj;
    cout << "=> PRESS 1 TO  CHECK  LIBRARY \n => PRESS 2 TO SEARCH AND RECIEVE BOOK FROM LIBRARY \n YOUR CHOICE IS : ";
    cin >> op;
    if (op == 1)
    {
        obj.Show_Science_lib_Data();
    }
    else if (op == 2)
    {
        obj.search_Science_lib();
    }
    else
    {
        cout << "WRONG OUTPUT!";
        system("CLS");
        goto start;
    }
}


//_______OPTION FOR  CALCULUSLIBRARY_______
void OPTION_FOR_VISITING_MEM_1()
{
start:
    int  op;
    Calcu_lib obj;
    cout << "=> PRESS 1 TO  CHECK  LIBRARY \n => PRESS 2 TO SEARCH AND RECIEVE BOOK FROM LIBRARY \n YOUR CHOICE IS : ";
    cin >> op;
    if (op == 1)
    {
        obj.Show_Calcu_lib_Data();
    }
    else if (op == 2)
    {
        obj.search_Calcu_lib();
    }
    else
    {
        cout << "WRONG OUTPUT!";
        system("CLS");
        goto start;
    }

}

void options_for_faculty()
{

    cout << "\n => PRESS 1 TO GET ACCESS TO LIBRARIES SET-UP\n";
    cout << "\n => PRESS 2 TO GET ACCESS TO LIBRARY MEMBER SET-UP\n";
    int option;
    cout << "ENTER THE  OPTION  :";
    cin >> option;
    if (option == 1)
    {
        randoM();
    }
    else if (option == 2)
    {
        cout << "\nMEMBER CORNOR................................ \n";
        Member obj;
        obj.Member_Info_choices();
        obj.get_choice();
        cout << endl;
    }

}


void choose_option(int a)
{
    if (a == 1)
    {
        label:
        int  op;
        cout << "\nCHOOSE THE OPTION  TO GET IN LIBRARY DOMAIN\n";
        cout << "\n 1.=>PHYSICS BOOK PROTION\n";
        cout << "\n 2.=>CALCULUS BOOK PROTION\n";
        cin >> op;
        cout << "ENTER THE OPTION :";
        cin >> op;
        switch (op)
        {
        case(1):
        {
            OPTION_FOR_VISITING_MEM();
            break;
        }
        case(2):
        {
            OPTION_FOR_VISITING_MEM_1();
            break;
        }
        default:
        {
            cout << "INVALID CHOICE";
            system("CLS");
            exit(1);
        }
        }

        char op1;
        cout << "=>PRESS ANY KEY TO PROCEED : \n =>PRESS E TO TO EXIT :";
        cin >> op1;
        if (op1 == 'a' || op1 == 'A')
        {
            goto label;
        }

    }

    if (a == 2)
    {

        options_for_faculty();
    }

    else
    {
        cout << "ERROR!........WRONG  INPUT..";
        exit(1);
    }
}

void selection()
{
    program_start_display();
    int my_op;
    cout << "\n\n_________________________________________________________________________\n";
    cout << "CHOOSE YOUR OPTION:\n\n 1.=> VISITING MEMBER. \n\n 2.=> FACULTY MEMBER.\n";
    cout << "ENTER YOUUR OPTION: ";
label:
    cin >> my_op;

    while (true)
    {

        if (my_op == 1)
        {
            break;
        }
        else  if (my_op == 2)
        {
            get_login_credential();
            break;
        }
        else
        {
            int i = 0;
            while (i < 2)
            {
                i++;
                cout << "ENTER OPTION  AGAIN ";
                goto label;
            }
            false;
            break;
        }
    }

  choose_option(my_op);
    
}



int main()
{
    selection();
    return 0;

}






