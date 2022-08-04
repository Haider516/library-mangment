#pragma once
#pragma once
#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include"Calculus_lib.h"
using namespace std;



//___________NON__MEMBER__FUNCTION______________________________________________
void Calcu_lib::Get_library_Details()
{
Library:get_lib_Details();
}

void Calcu_lib::Show_library_Details()
{
Library:show_lib_Details();
}

//______________DELETE RECORD  IN SCIENCE LIBRARY _____________________________
void Calcu_lib::DEL_Calcu_lib_REcord()
{
    Calcu_lib b;
    Calcu_lib info;
    int check = 0;
   // char op;
    while (true)
    {
        string DEl_name;

        ifstream MEM;
        while (true)
        {
            MEM.open("lib.txt", ios::in);
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
                    cout << "\n_____________________________________" << endl;
                    cout << left << "ID_NUMBER|\t" << setw(15) << "BOOK_NAME |" << setw(15) << "BOOK_PUBLISHING_DATE |"
                        << setw(15) << "BOOK_AUTHOR_NAME |" << setw(15) << "BOOK_QANTITY |" << endl;

                    cout << "  " << info.ID_NUMBER << " \t  " << setw(15) << info.BOOK_NAME << " \t " << info.PUBLISHING_DATE << setw(15)
                        << info.AUTHOR_NAME << setw(15) << info.QUANTITY << setw(15) << endl;
                    cout << " _____________________________________" << endl;
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
                info = b;
            }
        }
        cin.ignore();

        char  op;
        cout << "ENTRE RECORED FOR MORE MEMBERS? [y/n] : ";
        cin >> op;
        if (op == 'n' || op == 'N')
        {
            false;
            break;
        }

    }
}
//______________UPDATE RECORD  IN SCIENCE LIBRARY _____________________________

void Calcu_lib::Update_Calcu_lib_Record() {
    Calcu_lib info_update;
    string  NEW_Name;
    int Match = 0;
    while (true)
    {
        int  New_Age;
        long int move_next = 0;	//This will be incremented if stinng doesn't match i.e will help to set postion of seekg pointer

        fstream myfile;
        //READING THE FILE AND THEN  WRITNG ON THE SAME FILE TO MODIFY RECORD
        myfile.open("lib.txt", ios::in | ios::out);
        if (!myfile)
        {
            cout << "ERROR!COULD NOT OPEN YOUR FILE " << endl;
            exit(1);
        }
        system("cls");
        cout << "\n\nEnter name of the product to modify : ";
        //EXISTING BOOK NAME
        getline(cin, BOOK_NAME);
        cin.ignore();
        while (myfile.read((char*)&info_update, sizeof(info_update)))
        {
            //COMPARING THE EXISTING MEMBER  NAME WITH  THE MEMBER ALREADY PRESENT.
            int res = BOOK_NAME.compare(info_update.BOOK_NAME);

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
                int newID_NUMBER;
                cin >> newID_NUMBER;
                if (newID_NUMBER != 0)
                {	//Copying The BOOKID TO Existing Record
                    info_update.ID_NUMBER = newID_NUMBER;//copying string object
                    cin.ignore();
                }

                cout << setfill('>') << setw(27) << "\nENTER BOOK_NAME : ";
                getline(cin, NEW_Name);
                if (NEW_Name.size() > 0)
                {	//Copying The Book Name TO Existing Record
                    info_update.BOOK_NAME = NEW_Name;
                    cin.ignore();
                }
                cin.ignore();
                cout << setfill('>') << setw(27) << "\nENTER BOOK_PUBLISHING_DATE : ";
                getline(cin, NEW_Name);
                if (NEW_Name.size() > 0)
                {	//Copying The Member Name TO Existing Record
                    info_update.PUBLISHING_DATE = NEW_Name;
                    cin.ignore();
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
                cin.ignore();
                myfile.write((char*)&info_update, sizeof(info_update));
                myfile.close();
                Match = 1;
                if (Match == 1)
                {
                    break;
                }
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

//______________SEARCH RECORD  IN SCIENCE LIBRARY _____________________________


void  Calcu_lib::search_Calcu_lib(void)
{
    int n = 0;
    Calcu_lib SEARCH;
    string requirement;
    long int move_next = 0;	//This will be incremented if stinng doesn't match i.e will help to set postion of seekg pointer
    int match = 0;
    while (true)
    {
        ifstream file("lib.txt", ios::in);
        if (!file)
        {
            cout << "FAILURE TO OPEN THE FILE" << endl;
            exit(1);
        }
        system("cls");

        cout << "\nENTER  THE BOOK ID-NUMBER\n: ";
        cin >> requirement;
        while (file.read((char*)(&SEARCH), sizeof(SEARCH)))
        {

            int res = requirement.compare(SEARCH.ID_NUMBER);

            if (requirement == SEARCH.ID_NUMBER)
            {
                match = 1;
                cout << "\n_____________________________________" << endl;
                cout << left << "ID_NUMBER|\t" << setw(15) << "BOOK_NAME |" << setw(15) << "BOOK_PUBLISHING_DATE |"
                    << setw(15) << "BOOK_AUTHOR_NAME |" << setw(15) << "BOOK_QANTITY |" << endl;

                /*cout << "  " << SEARCH.ID_NUMBER << " \t  " << setw(15) << SEARCH.BOOK_NAME << " \t " << SEARCH.PUBLISHING_DATE << setw(15)
                    << SEARCH.AUTHOR_NAME << setw(15) << SEARCH.QUANTITY << setw(15) << endl;*/
                SEARCH.show_lib_Details();
                cout << " _____________________________________" << endl;
                int ch;
                cout << "press 1 if you want to take this book:";
                cin >> ch;
                if (ch == 1)
                {
                    ++n;
                }
                file.close();

            }
            else
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
    cout << "Total number of books you have taken from this domain are:" << n;
}

//______________ADD RECORD  IN SCIENCE LIBRARY ______________________________

void Calcu_lib::ADD_Calcu_lib_Data()
{
    Calcu_lib informat_ion;
    string line;
    ofstream myfile;


    myfile.open("lib.txt", ios::app);
    {
        if (!myfile)
        {
            cout << "ERROR IN OPENING FILE.." << endl;
        }
        else
        {
            informat_ion.get_lib_Details();
            myfile.write((char*)&informat_ion, sizeof(Calcu_lib));    //read from file

        }
    }



    myfile.close(); //close the file
}


//______________SHOW RECORD  IN SCIENCE LIBRARY _____________________________
void Calcu_lib::Show_Calcu_lib_Data()
{
    Calcu_lib informat_ion;
    ifstream file("lib.txt", ios::in);
    if (!file)
    {
        cout << "File opening error." << endl;
        system("pause");
        exit(1);
    }

    while (!file.eof())
    {

        file.read((char*)&informat_ion, sizeof(Calcu_lib));;
        informat_ion.Show_library_Details();
    }
    file.close();
}


void Calcu_lib::Member_Info_choices(void)
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

//________________________FUNCTION FOR CHOICES OF OPERATION______________

void Calcu_lib::get_choice()
{
    Calcu_lib DATA;
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
            DATA.Show_Calcu_lib_Data();
            break;
        }
        case(2):
        {
            DATA.ADD_Calcu_lib_Data();
            break;
        }
        case(3):
        {
            DATA.search_Calcu_lib();
        }
        case(4):
        {
            DATA.DEL_Calcu_lib_REcord();
            break;
        }
        case(5):
        {
            DATA.Update_Calcu_lib_Record();
            break;
        }
        default:
        {
            cout << "NO SUCH OPTION  EXIT:";
            false;
            break;
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

//______________________END__OF__CALCULUS__BOOK CLASS________________________________



//void Calcu_lib::write_Mem_info_display()
//{
//    Calcu_lib informat_ion;
//
//    ofstream myfile("Calcu_lib.txt", ios::a);
//    if (!myfile)
//    {
//        cout << "Error in creating file.." << endl;
//    }
//
//    informat_ion.get_lib_Details();
//    myfile.write((char*)&informat_ion, sizeof(informat_ion));    //read from file
//
//       //close the file
//
//    myfile.close();
//}
//
//void Calcu_lib::show_Mem_info_display()
//{
//    Calcu_lib informat_ion;
//
//    
//        ifstream myfile("Calcu_lib.txt", ios::in);
//        if (!myfile)
//        {
//            cout << "Error in creating file.." << endl;
//        }
//        while (!myfile.eof())
//        {
//            while (!myfile.eof())
//            {
//                myfile.read((char*)&informat_ion, sizeof(Calcu_lib));    //read from file
//                informat_ion.Show_library_Details();
//            }
//        }
//       //close the file
//    myfile.close();
//
//}
//
