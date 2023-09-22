#include "../thirdparty/ctest.h"
#include <../src/pwgen_lib/generatepassword.h>
#include <../src/pwgen_lib/generator.h>
#include <../src/pwgen_lib/newpassword.h>
#include <../src/pwgen_lib/passchanger.h>
#include <../src/pwgen_lib/passwordused.h>
#include <../src/pwgen_lib/viewcontent.h>
#include <pwgen_lib/deletepasswords.h>

using namespace std;
// проверка длины пароля
CTEST(check_password_generate, test1)
{
    int length = 10;
    string password = generatePassword(length);
    ASSERT_EQUAL(length, password.length());
}
//  проверка символов
CTEST(check_password_generate, test2)
{
    int num_tests = 100;
    int length = 16;
    string charset
            = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@"
              "#$%^&*";
    for (int i = 0; i < num_tests; i++) {
        string password = generatePassword(length);
        for (char c : password) {
            ASSERT_TRUE(charset.find(c) != string::npos);
        }
    }
}
// генерация рандомности паролей
CTEST(check_password_generate, test3)
{
    int length = 16;
    bool expected = false;
    string password1 = generatePassword(length);
    string password2 = generatePassword(length);
    for (int i = 0; i < length; i++) {
        if (password1[i] == password2[i])
            expected = true;
    }
    ASSERT_TRUE(expected);
}

//  проверка на то чтобы пароли не повторялись
CTEST(check_password_used, test1)
{
    bool expected = true;
    int length = 1;
    string password = generatePassword(length);
    if (isPasswordUsed(password, "used_passwords.txt") == false)
        expected = false;
    ASSERT_FALSE(expected);
}
// проверка на использование пароля в тктшник
CTEST(check_password_used, test2)
{
    string file_name = "used_passwords.txt";
    ofstream out_file(file_name);
    out_file.close();

    string password = "password1";
    ASSERT_FALSE(isPasswordUsed(password, file_name));

    remove(file_name.c_str());
}
// проверка правильности названия файла
CTEST(check_password_used, test3)
{
    string file_name = "invalid_file.txt";
    string password = "password1";
    ASSERT_FALSE(isPasswordUsed(password, file_name));
}
// проверка создания пароля
CTEST(check_add_used_password, test1)
{
    bool expected = false;
    string file_name = "test_file.txt";
    ofstream out_file(file_name);
    out_file.close();

    string username = "test_user";
    string password = "test_password";
    addUsedPassword(username, password, file_name);

    ifstream in_file(file_name);
    string line;
    getline(in_file, line);
    if (line == "Логин: test_user Пароль: test_password")
        expected = true;

    ASSERT_TRUE(expected);
    remove(file_name.c_str());
}
// проверка изменения пароля
CTEST(check_add_new_password, test1)
{
    bool expected = false;
    string file_name = "test_file.txt";
    ofstream out_file(file_name);
    out_file.close();

    string username = "test_user";
    string password = "test_password";
    addUsedPassword(username, password, file_name);
    NewUsedPassword(username, password, file_name);

    ifstream in_file(file_name);
    string line;
    getline(in_file, line);
    if (line == "Логин: test_user Пароль: test_password")
        expected = true;

    ASSERT_TRUE(expected);
    remove(file_name.c_str());
}
