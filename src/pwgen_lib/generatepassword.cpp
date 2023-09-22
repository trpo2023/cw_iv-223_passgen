#include <iostream>
#include <pwgen_lib/generatepassword.h>
#include <string>
using namespace std;

string generatePassword(int length)
{
    setlocale(LC_ALL, "RU");

    string charset
            = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@"
              "#$%^&*"; // Определяет набор символов для использования в пароле

    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Генерирование пароля
    string password = "";
    for (int i = 0; i < length; i++) {
        password += charset[rand() % charset.length()];
    }

    return password;
}