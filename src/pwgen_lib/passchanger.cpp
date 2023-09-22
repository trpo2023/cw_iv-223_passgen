#include <../src/pwgen_lib/passwordused.h>
#include <iostream>
#include <pwgen_lib/passchanger.h>
#include <string>
using namespace std;

int passchanger()
{ //Функция смены пароля
    string username;
    std::ifstream ifs("used_passwords.txt");
    cout << "Введите логин: ";
    std::string str;
    std::cin >> str;
    using input_it = std::istream_iterator<std::string>;
    std::cout << std::boolalpha
              << (std::find(input_it(ifs), input_it(), str) != input_it());
    int length; // Длина пароля
    cout << "Введите длину пароля: ";
    cin >> length;

    string password; // Генерирует уникальный пароль
    do {
        password = generatePassword(length);
    } while (isPasswordUsed(password, "used_passwords.txt"));

    NewUsedPassword(
            str, password, "used_passwords.txt"); // Добавляет этот новый пароль
                                                  // в использованные

    return 0;
}
