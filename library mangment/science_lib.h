#pragma once
#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;


class Science_lib :public Library
{
public:
    //VIRTUAL FUNCTON_____________
    void Get_library_Details();
    void Show_library_Details();
    void get_choice();
    void Member_Info_choices();

    //_NON-MEMBER__FUNCTION__________
    void DEL_Science_lib_REcord();
    void Update_Science_lib_Record();
    void  search_Science_lib();
    void ADD_Science_lib_Data();
    void Show_Science_lib_Data();
    void write_Mem_info_display();
};
