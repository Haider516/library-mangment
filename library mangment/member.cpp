
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "library.h"
#include "member.h"

using namespace std;
//__________VIRTUAL___FUNCTIONS_____________________

void Member::Mem_info_display()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\n______________________________________________________________________________________________" << endl;
	cout << left << "| MEMBER_NAME|\t" << setw(20) << "MEMBER_AGE |" << setw(25) << "MEMBER_CONTACT_NUMBER |" << endl;
	cout << " _______________________________________________________________________________________________" << endl;
	cout << left << NAME << "\t\t" << M_age << "\t\t" << M_contact << endl;
}
void Member::Mem_info()
{
	cout << "ENTER  THE NAME OF MEMBER :";
	cin.ignore();
	cin.getline(NAME, 30);

	cout << "ENTER  THE AGE OF MEMBER :";
	cin >> M_age;
	cin.ignore();
	cout << "ENTER  THE CONTACT OF MEMBER :";
	cin.getline(M_contact, 15);
	cout << endl;
}

						//OPERATION_FUNCTION

//_______DISPLAY___FUNCTION____________________________________________________

void Member::show_Mem_info_display()
{
	Member informat_ion;

	ifstream myfile("Member3.txt", ios::in);
	if (!myfile)
	{
		cout << "Error in creating file.." << endl;
	}
	while (!myfile.eof())
	{
		myfile.read((char*)&informat_ion, sizeof(informat_ion));    //read from file
		informat_ion.Mem_info_display();
	}

	//close the file

	myfile.close();
}

//__________ADD___MEMBER___DATA_______________________________________________

void Member::ADD_NEW_Mem_Info()
{
	Member new_info;
	//char op;
	ofstream add_m_data("Member3.txt", ios::app);
	if (!add_m_data)
	{
		cout << "ERROR IN  OPENING OF FILE" << endl;
		exit(1);
	}

	new_info.Mem_info();
	add_m_data.write((char*)&new_info, sizeof(Member));

	add_m_data.close();

}

//__________DELETING____MEMBER______________________________________________

void Member::DEL_Mem_REcord()
{
	Member info;
	int check = 0;
	char op;
	while (true)
	{
		char DEl_name[30];

		ifstream MEM;
		MEM.open("Member3.txt", ios::in);
		ofstream N_MEM;
		N_MEM.open("MEMBER_New.txt", ios::out);
		if (!MEM)
		{
			cout << "ERROR IN FINDING THE FILE" << endl;
			exit(1);
		}
		system("cls");

		cout << "\n\nENTER THE MEMBER'S NAME TO DELETE : ";
		cin.ignore();
		cin.getline(DEl_name, 30);
		while (MEM.read((char*)&info, sizeof(Member)));

		{
			if (strcmp(DEl_name, info.NAME) == 0)
			{
				cout << "\n___________________________________________________________________________________________" << endl;
				cout << left << "MEMBER_NAME|\t" << setw(15) << "MEMBER_AGE |" << setw(15) << "MEMBER_CONTACT_NUMBER |" << endl;
				cout << " ____________________________________________________________________________________________" << endl;
				cout << "  " << info.NAME << " \t  " << setw(15) << info.M_age << " \t " << info.M_contact << setw(15) << endl;
				check = 1;
			}
			if (strcmp(DEl_name, info.NAME) != 0)
				cout << "  " << info.NAME << " \t  " << setw(15) << info.M_age << " \t " << info.M_contact << setw(15) << endl;
			N_MEM.write((char*)&info, sizeof(Member));

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
			remove("Member3.txt");
			return_check = rename("MEMBER_New.txt", "Member3.txt");
			if (return_check != 0)
			{
				cout << "\nUNABLE TO  RENAME THE FILE !\nRECORD CORRUPTION'\n", return_check;
			}
			else
			{
				cout << "RECORD DELETED SUCCESSFULLY!" << endl;
			}
		}

		cout << "\n\nPRESS THE BUTTON  Y TO DELETE MORE RECORDS ?: [y/n] ";
		cin >> op;
		if (op == 'N' || op == 'n')
		{
			false;
			break;
		}
		else if (op == 'y' || op == 'Y')
		{
			continue;
		}
	}
}

//_________SEARCH___MEMBER__________________________________________________

void Member::search_Member()
{
	int match = 0;
	Member S_R_info;
	char Spe_S_h[30];//MEMBER NAME SEARCH 
	long int move_next = 0;	//This will be incremented if stinng doesn't match i.e will help to set postion of seekg pointer
	while (true)
	{
		//int  New_Age;
		long int move_next = 0;	//This will be incremented if stinng doesn't match i.e will help to set postion of seekg pointer
		fstream myfile;
		//READING THE FILE AND THEN  SEARCHING ON THE SAME FILE TO GET RECORD
		myfile.open("Member3.txt", ios::in);
		if (!myfile)
		{
			cout << "ERROR!COULD NOT OPEN YOUR FILE " << endl;
			exit(1);
		}
		system("cls");
		cout << "\n\nENTER THE MEMBER NAME  TO SEARCH : ";
		cin.getline(Spe_S_h, 30);
		cin.ignore();
		while (myfile.read((char*)(&S_R_info), sizeof(S_R_info)))
		{
			if (strcmp(Spe_S_h, S_R_info.NAME) == 0)
			{
				move_next = (move_next - 1) * sizeof(S_R_info);
				myfile.seekg(move_next);
				cout << "\n\n _______________________________________________________________________________________________" << endl;
				cout << "| MEMBER_NAME|\t" << setw(20) << "MEMBER_AGE |" << setw(25) << "MEMBER_CONTACT_NUMBER |" << endl;
				cout << " _______________________________________________________________________________________________" << endl;
				cout << S_R_info.NAME << "\t" << setw(20) << S_R_info.M_age << setw(25) << S_R_info.M_contact << endl;
				system("PAUSE");
				myfile.close();
				match = 1;
			}
			move_next++;
		}
		//function to check if  the  record not found
		if (match == 0)
		{
			cout << "YOUR ENTERED RECORD DOESNOT MATCHED ..." << endl;
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


					//PURE VIRTUAL FUNCTIONS
					
//_____________________CHOOSE FUNCTION___________________________________________
void Member::get_choice()
{
	Member DATA;
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
			DATA.ADD_NEW_Mem_Info();
			break;
		}
		case(2):
		{
			DATA.show_Mem_info_display();
			break;
		}
		case(3):
		{
			DATA.DEL_Mem_REcord();
		}
		case(4):
		{
			DATA.search_Member();
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

//____________________DETAILS FUNCTION___________________________________________
void Member::Member_Info_choices(void)
{
	system("CLS");
	cout << setfill('*') << setw(35) << "LIBRARY MEMBER MANAGEMENT PROCESS" << setiosflags(ios::right) << setfill('*') << endl;
	cout << "\n\n 'SELECT YOUR  OPTION:' " << endl;
	cout << "\n =>1: " << "TO CHECK ADD MEMBER" << endl;
	cout << "\n =>2: " << "TO SHOW   MEMBER" << endl;
	cout << "\n =>3: " << "TO DELETE MEMBER" << endl;
	cout << "\n =>4: " << "TO SEARCH MEMBER" << endl;

}