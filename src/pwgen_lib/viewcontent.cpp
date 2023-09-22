#include <fstream>
#include <iostream>
#include <pwgen_lib/viewcontent.h>
#include <string>
using namespace std;

void viewcontent() // Функция для просмотра файла
{
    string path = "used_passwords.txt";

    ifstream fin;
    fin.open(path);
    if (fin.is_open()) {
        cout << "\nИспользуемые пароли: \n" << endl;
        char ch;
        while (fin.get(ch)) {
            cout << ch;
        }
    } else {
        cout << "!!!ОШИБКА!!!  Файл не открывается!" << endl;
    }
    fin.close();
}
