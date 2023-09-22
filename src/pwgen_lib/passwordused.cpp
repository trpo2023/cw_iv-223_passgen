#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale.h>
#include <pwgen_lib/passwordused.h>
#include <string>
#include <vector>
using namespace std;

bool isPasswordUsed(string password, string file_name)
{
    ifstream file(file_name);
    string line;
    while (getline(file, line)) {
        if (line == password) {
            return true;
        }
    }
    return false;
}