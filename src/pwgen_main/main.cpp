#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale.h>
#include <string>
#include <vector>

#include <../src/pwgen_lib/generatepassword.h>
#include <../src/pwgen_lib/generator.h>
#include <../src/pwgen_lib/newpassword.h>
#include <../src/pwgen_lib/passchanger.h>
#include <../src/pwgen_lib/passwordused.h>
#include <../src/pwgen_lib/viewcontent.h>
#include <pwgen_lib/deletepasswords.h>

using namespace std;

int main()
{
    int x = 6;
    while (true) {
        if (x == 0)
            break;
        cout << "\n1 - Создайте логин для генерации пароля\n"
                "2 - Просмотреть логины и пароли пользователей\n"
                "3 - Сменить пароль для входа в систему\n"
                "4 - Удалить логин и пароль\n"
                "0 - Закончить работу\n\n";
        cin >> x;
        switch (x) {
        case 1:
            generator();
            break;
        case 2:
            viewcontent();
            break;
        case 3:
            passchanger();
            break;
        case 4:
            deletepasswords();
            break;
        case 0:
            break;
        default:
            cout << "x is undefined\n";
            break;
        }
    }
    return 0;
}