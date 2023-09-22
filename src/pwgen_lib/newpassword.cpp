#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale.h>
#include <pwgen_lib/newpassword.h>
#include <string>
using namespace std;

// Функция для добавления пароля в файл
void addUsedPassword(string username, string password, string file_name)
{
    ofstream file(file_name, ios::app);
    file << "Логин: " << username << " "
         << "Пароль: " << password << endl;
}

void NewUsedPassword(string str, string password, string file_name)
{
    ofstream file(file_name, ios::app);
    file << "Логин: " << str << " "
         << "Новый пароль: " << password << endl;
}