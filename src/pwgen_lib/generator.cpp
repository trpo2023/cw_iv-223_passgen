#include <../src/pwgen_lib/generator.h>
#include <../src/pwgen_lib/newpassword.h>
#include <../src/pwgen_lib/passwordused.h>
#include <iostream>
#include <pwgen_lib/generatepassword.h>
#include <string>
using namespace std;

int generator()
{
    string username; // Название логина
    cout << "Введите логин: ";
    cin >> username;
    int length; // Длина пароля
    cout << "Введите длину пароля: ";
    cin >> length;

    string password; // Генерирует уникальный пароль
    do {
        password = generatePassword(length);
    } while (isPasswordUsed(password, "used_passwords.txt"));

    addUsedPassword(
            username,
            password,
            "used_passwords.txt"); // Добавляет этот новый пароль в
                                   // использованные

    return 0;
}