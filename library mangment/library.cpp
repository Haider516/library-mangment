#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace  std;

//Library::Library()//(string  a, string  b)
//{
//	ID_NUMBER;  
//	BOOK_NAME(""), PUBLISHING_DATE(""), AUTHOR_NAME(""), QUANTITY(0);
//}

void Library::get_lib_Details()
{
	cout << endl;
	cin.ignore();
	cout << "ENTRE BOOK ID_NUMBER :";
	getline(cin, ID_NUMBER);
	cin.ignore();
	cout << "\nENTRE BOOK NAME :";
	getline(cin, BOOK_NAME);
	cin.ignore();
	cout << "\nENTRE BOOK PUBLISHING DATE(dd/mm/yy) :";
	getline(cin, PUBLISHING_DATE);
	cin.ignore();
	cout << "\nENTRE BOOK AUTHOR NAME  :";
	getline(cin, AUTHOR_NAME);
	cin.ignore();
	cout << "\nENTRE BOOK  QUANTITY  :";
	cin >> QUANTITY;
}
//______________SHOWING__DETAIL__FUNCTION________________________
void Library::show_lib_Details()
{
	cout<< endl;
	cout <<" ID_NUMBER \t\t BOOK_NAME \t\t PUBLISHING_DATE \t\t AUTHOR_NAME \t\t QUANTITY "<< endl << endl;
	cout << ID_NUMBER << "\t\t\t" << BOOK_NAME << "\t\t" << PUBLISHING_DATE << "\t\t\t" << AUTHOR_NAME << setw(20) << QUANTITY << endl;
}
