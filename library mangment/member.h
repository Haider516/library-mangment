#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

class Member
{
private:
	char NAME[30];
	int  M_age;
	char M_contact[15];
public:
	Member() :NAME(), M_age(0), M_contact()
	{	}

//_____NON_MEMBER__FUNCTION____
	void Mem_info();				//TO GET MEMBER INFORMATION
	void Mem_info_display();		//TO DISPLAY  MEMBER INFORMATION

	void ADD_NEW_Mem_Info();		//TO ADD
	void show_Mem_info_display();	//TO SHOW
	void DEL_Mem_REcord();			//TO DELETE
	void search_Member();			//TO SEARCH

	//used virtal function
	 void Member_Info_choices();
	 void get_choice() ;
	
};
