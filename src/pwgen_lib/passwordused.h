#pragma once
#include <../src/pwgen_lib/generatepassword.h>
#include <../src/pwgen_lib/newpassword.h>
#include <../src/pwgen_lib/passwordused.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale.h>
#include <string>
#include <vector>
using namespace std;
bool isPasswordUsed(string password, string file_name);