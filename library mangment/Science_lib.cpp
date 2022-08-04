#pragma once
#include "library.h"
#include "science_lib.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;


//______________VIRTUAL__FUNCTION_____________________________

                // TO  GET DATA
void Science_lib::Get_library_Details()
{
    Library::get_lib_Details();
}
            // TO  SHOW  DATA

void Science_lib::Show_library_Details()
{
Library:show_lib_Details();
}
//______________DELETE RECORD  IN SCIENCE LIBRARY _____________________________

void Science_lib::DEL_Science_lib_REcord()
{
    Science_lib info;
    int check = 0;
    char op;
    while (true)
    {
        string DEl_name;

        ifstream MEM;
        while (true)
        {
            MEM.open("Science_li.txt", ios::in);
            ofstream N_MEM("library_New.txt");
            if (!MEM)
            {
                cout << "ERROR IN OPENING THE FILE" << endl;
                exit(1);
            }
            system("cls");
            cin.ignore();
            cout << "\n\nENTER THE BOOK NAME TO DELETE : ";
            getline(cin, DEl_name);
            while (MEM.read((char*)&info, sizeof(info)));
            {

                int res = DEl_name.compare(info.BOOK_NAME);

                if (res == 0)
                {
                    cout << "\n_____________________________________________________________________________________________________________" << endl;
                    cout << left << "ID_NUMBER|\t" << setw(15) << "BOOK_NAME |" << setw(15) << "BOOK_PUBLISHING_DATE |"
                        << setw(15) << "BOOK_AUTHOR_NAME |" << setw(15) << "BOOK_QANTITY |" << endl;

                    cout << "  " << info.ID_NUMBER << " \t  " << setw(15) << info.BOOK_NAME << " \t " << info.PUBLISHING_DATE << setw(15)
                        << info.AUTHOR_NAME << setw(15) << info.QUANTITY << setw(15) << endl;
                    cout << " _______________________________________________________________________________________________________________" << endl;
                    check = 1;
                }
                if (res != 0)
                {
                    N_MEM.write((char*)&info, sizeof(info));
                }

            }  // while loop end here
            int return_check = 0;
            if (check == 0)
            {
                cout << "RECORD NOT FOUND!";
            }
            if (check == 1)
            {
                MEM.close();
                N_MEM.close();
                remove("Science_li.txt");
                return_check = rename("library_New.txt", "Science_lib.txt");
                if (return_check != 0)
                {
                    cout << "\nUNABLE TO  RENAME THE FILE !\nRECORD CORRUPTION'\n",
                        return_check;
                }
                else
                {
                    cout << "RECORD DELETED SUCCESSFULLY!" << endl;
                }
            }
        }
        cin.ignore();

        char  op;
        cout << "ENTER RECORED FOR MORE MEMBERS? [y/n] : ";
        cin >> op;
        if (op == 'n' || op == 'N')
        {
            false;
            break;
        }
       
    }
}
//______________UPDATE RECORD  IN SCIENCE LIBRARY ______________________________

void Science_lib::Update_Science_lib_Record() {
    Science_lib info_update;
    string  NEW_Name;
    int Match = 0;
    while (true)
    {
        int  New_Age;
        long int move_next = 0;	//This will be incremented if stinng doesn't match i.e will help to set postion of seekg pointer

        fstream myfile;
        //READING THE FILE AND THEN  WRITNG ON THE SAME FILE TO MODIFY RECORD
        myfile.open("Science_l.txt", ios::in | ios::out);
        if (!myfile)
        {
            cout << "ERROR!COULD NOT OPEN YOUR FILE " << endl;
            exit(1);
        }
        //system("cls");
        cout << "\n\nEnter name of the product to modify : ";
        cin.ignore();
        //EXISTING BOOK NAME
        getline(cin, NEW_Name);
       
        while (myfile.read((char*)&info_update, sizeof(info_update)))
        {
            //COMPARING THE EXISTING MEMBER  NAME WITH  THE MEMBER ALREADY PRESENT.
            int res = NEW_Name.compare(info_update.BOOK_NAME);

            if (res == 0)
            {
                  cout << "\n_____________________________________________________________________________________________________________" << endl;
                cout << left << "ID_NUMBER|\t" << setw(15) << "BOOK_NAME |" << setw(15) << "BOOK_PUBLISHING_DATE |"
                    << setw(15) << "BOOK_AUTHOR_NAME |" << setw(15) << "BOOK_QANTITY |" << endl;

                cout << "  " << info_update.ID_NUMBER << " \t  " << setw(15) << info_update.BOOK_NAME << " \t " << info_update.PUBLISHING_DATE << setw(15)
                    << info_update.AUTHOR_NAME << setw(15) << info_update.QUANTITY << setw(15) << endl;
                cout << " _______________________________________________________________________________________________________________" << endl;

                move_next = (move_next) * sizeof(info_update);
                myfile.seekp(move_next);//to set the position of pointer to read 
                cin.ignore();
                cout << setfill('>') << setw(27) << "\nENTER ID_NUMBER : ";
                getline(cin, NEW_Name);
                if (NEW_Name.size() > 0)
                {	//Copying The BOOKID TO Existing Record
                    info_update.ID_NUMBER = NEW_Name;//copying string object
                    
                    cin.ignore();
                }

                cout << setfill('>') << setw(27) << "\nENTER BOOK_NAME : ";
                getline(cin, NEW_Name);
                if (NEW_Name.size() > 0)
                {	//Copying The Book Name TO Existing Record
                    info_update.BOOK_NAME = NEW_Name;

                }
                cin.ignore();
                cout << setfill('>') << setw(27) << "\nENTER BOOK_PUBLISHING_DATE : ";
                getline(cin, NEW_Name);
                if (NEW_Name.size() > 0)
                {	//Copying The Member Name TO Existing Record
                    info_update.PUBLISHING_DATE = NEW_Name;
                  
                }
                cin.ignore();
                cout << setfill('>') << setw(27) << "\nENTER BOOK_AUTHOR_NAME : ";
                getline(cin, NEW_Name);
                if (NEW_Name.size() > 0)
                {	//Copying The Member Name TO Existing Record
                    info_update.AUTHOR_NAME = NEW_Name;
                    cin.ignore();
                }
                cout << setfill('>') << setw(27) << "ENTER BOOK_QUANTITY : ";
                cin >> New_Age;
                if (New_Age != info_update.QUANTITY)
                {	//Copying The Member Age TO Existing Record
                    info_update.QUANTITY = New_Age;
                    
                }
                else
                {
                    continue;
                }
 
                myfile.close();
                Match = 1;
                if (Match == 1)
                {
                    break;
                }
                myfile.write((char*)&info_update, sizeof(Science_lib));
            }
            move_next++;
        }
        //function to cheCk if  the  record not found
        if (Match == 0)
        {
            cout << "YOUR ENTERED RECORD DOESNOT MATCHED ..." << endl;
        }
        char op;
        cout << "\n\nPRESS THE BUTTON  Y TO DELETE MORE RECORDS ?: [y/n] ";
        cin >> op;
        if (op == 'N' || op == 'n')
        {
            false;
            break;
        }
    }
}

//______________SEARCH RECORD  IN SCIENCE LIBRARY _______________________________

void  Science_lib::search_Science_lib(void)
{
    int n = 0;
    Science_lib SEARCH;
    string requirement;
    long int move_next = 0;	//This will be incremented if stinng doesn't match i.e will help to set postion of seekg pointer
    int match = 0;
    while (true)
    {
        ifstream file("Science_l.txt", ios::in);
        if (!file)
        {
            cout << "FAILURE TO OPEN THE FILE" << endl;
            exit(1);
        }
        system("cls");

        cout << "\nENTER  THE BOOK ID-NUMBER\n: ";
        cin.ignore();
        getline( cin,requirement);
        
        while (file.read((char*)(&SEARCH), sizeof(Science_lib)))
        {

            int res = requirement.compare(SEARCH.ID_NUMBER);

            if (res == 0)
            {
                cout << "\n_____________________________________________________________________________________________________________" << endl;
                cout << left << "ID_NUMBER|\t" << setw(15) << "BOOK_NAME |" << setw(15) << "BOOK_PUBLISHING_DATE |"
                    << setw(15) << "BOOK_AUTHOR_NAME |" << setw(15) << "BOOK_QANTITY |" << endl;

                SEARCH.show_lib_Details();
                cout << " _______________________________________________________________________________________________________________" << endl;

                int ch;
                cout << "press 1 if you want to take this book:";
                cin >> ch;
                if (ch == 1)
                {
                    ++n;
                }
                file.close();
                match = 1;
            }
            move_next++;

            //function to check if  the  record not found
            if (match == 0)
            {
                cout << "YOUR ENTERED RECORD DOESNOT MATCHED ..." << endl;
            }
        }
        char op;
        cout << "\n\nPRESS THE BUTTON  Y TO SEARCH MORE RECORDS ?: [y/n] ";
       
        cin >> op;
        if (op == 'N' || op == 'n')
        {
            false;
            break;
        }

    }
}

//______________ADD RECORD  IN SCIENCE LIBRARY ___________________________________

void Science_lib::ADD_Science_lib_Data()
{
    Science_lib informat_ion;
    string line;
    ofstream myfile;


    myfile.open("Science_l.txt", ios::app);
    {
        if (!myfile)
        {
            cout << "ERROR IN OPENING FILE.." << endl;
        }
        else
        {
            informat_ion.get_lib_Details();
            myfile.write((char*)&informat_ion, sizeof(Science_lib));    //read from file

        }
    }



    myfile.close(); //close the file
}

//______________DISPLAY  RECORD  IN SCIENCE LIBRARY ______________________________

void Science_lib::Show_Science_lib_Data()
{
    Science_lib informat_ion;
    ifstream file("Science_l.txt", ios::in);
    if (!file)
    {
        cout << "File opening error." << endl;
        system("pause");
        exit(1);
    }

    while (!file.eof())
    {

        file.read((char*)&informat_ion, sizeof(Science_lib));;
        informat_ion.Show_library_Details();
    }

    file.close();
}

                        //PURE VIRTUAL FUNCTIONS

//________________________FUNCTION FOR CHOICES OF OPERATION_______________________

void Science_lib::Member_Info_choices(void)
{
    system("CLS");
    cout << setfill('*') << setw(35) << "LIBRARY MEMBER MANAGEMENT PROCESS" << setiosflags(ios::right) << setfill('*') << endl;
    cout << "\n\n 'SELECT YOUR  OPTION:' " << endl;
    cout << "\n =>1: " << "TO CHECK  CURRENT  BOOKS" << endl;
    cout << "\n =>2: " << "TO ADD    BOOKS" << endl;
    cout << "\n =>3: " << "TO SEARCH BOOK" << endl;
    cout << "\n =>4: " << "TO DELETE BOOK" << endl;
    cout << "\n =>5: " << "TO UPDATE BOOK" << endl;
}



void Science_lib::get_choice()
{
    Science_lib DATA;
    while (true)
    {
        int a;
        cout << "YOUR OPTION IS :";
        cin >> a;
        cout << endl;
        switch (a)
        {
                case(1):
                {
                    DATA.Show_Science_lib_Data();
                    break;
                }
                case(2):
                {
                    DATA.ADD_Science_lib_Data();
                    break;
                }
                case(3):
                {
                    DATA.search_Science_lib();
                    break;
                }
                case(4):
                {
                    DATA.DEL_Science_lib_REcord();;
                    break;
                }
                case(5):
                {
                    DATA.Update_Science_lib_Record();
                    break;
                }
            default:
            {
                cout << "NO SUCH OPTION  EXIT:";
               
            }
        }
        char op;
        cin.ignore();
        cout << "IF  YOU  WANT TO REUSE AN OPERATION PRESS 'R' OR ELSE PRESS 'E' TO EXIT :";
        cin >> op;

        if (op == 'e' || op == 'E')
        {
            false;
            break;
        }
        else
        {
            continue;
        }
    }
}




