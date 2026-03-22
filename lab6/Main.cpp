#include <iostream>
#include <windows.h>
#include "MyString.h"
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    MyString s1, s2, s3;

    cout << "Введите строку s1:\n";
    s1.input();

    cout << "Введите строку s2:\n";
    s2.input();

    int c;
    do
    {
        cout << "\n=== ЛР6 ===\n";
        cout << "1. Показать строки\n";
        cout << "2. Ввести строки заново\n";
        cout << "3. Длина строк\n";
        cout << "4. Сложение строк\n";
        cout << "5. Сравнение строк\n";
        cout << "6. Присваивание\n";
        cout << "0. Выход\n> ";

        cin >> c;
        cin.ignore(1000, '\n');

        if (c == 1)
        {
            cout << "s1: ";
            s1.print();
            cout << "s2: ";
            s2.print();
            cout << "s3: ";
            s3.print();
        }
        else if (c == 2)
        {
            cout << "Введите строку s1:\n";
            s1.input();
            cout << "Введите строку s2:\n";
            s2.input();
        }
        else if (c == 3)
        {
            cout << "Длина s1: " << s1.length() << endl;
            cout << "Длина s2: " << s2.length() << endl;
        }
        else if (c == 4)
        {
            s3 = s1 + s2;
            cout << "s3 = s1 + s2: ";
            s3.print();
        }
        else if (c == 5)
        {
            if (s1 == s2) cout << "Строки равны\n";
            else cout << "Строки разные\n";
        }
        else if (c == 6)
        {
            s3 = s1;
            cout << "После s3 = s1:\n";
            cout << "s3: ";
            s3.print();
        }

    } while (c != 0);

    return 0;
}