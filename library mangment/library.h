#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace  std;

class Library
{
protected:

	string ID_NUMBER;
	string  BOOK_NAME;
	string PUBLISHING_DATE;
	string  AUTHOR_NAME;
	int		QUANTITY;
public:

	//_____NON-MEMBER__FUNCTION_______
	void show_lib_Details();
	void get_lib_Details();
	void show();
	//_____PURE __VIRTUAL__FUNCTION_______
	virtual void   Get_library_Details() = 0;
	virtual void  Show_library_Details() = 0;
	virtual void Member_Info_choices() = 0;
	virtual void get_choice() = 0;

};