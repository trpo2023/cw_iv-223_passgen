#pragma once
#include <../src/pwgen_lib/newpassword.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
void addUsedPassword(string username, string password, string file_name);
void NewUsedPassword(string str, string password, string file_name);