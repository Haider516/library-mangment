#pragma once
#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;


//______CLASS FOR  CALCU_BOOK___________________________________________________
class Calcu_lib :public Library
{
public:
    //_____NON MEMBER FUNCTION
   //_____________________________________________________________
    void Get_library_Details();
    void Show_library_Details();
    //_________________DISPLAY____________________________________
    void  get_choice();
    void Member_Info_choices();
    // _______________FUNCTIONS____________________________________
    void DEL_Calcu_lib_REcord();
    void Update_Calcu_lib_Record();
    void  search_Calcu_lib();
    void ADD_Calcu_lib_Data();
    void Show_Calcu_lib_Data();
    void show_Mem_info_display();
    void write_Mem_info_display();


};
