#include <iostream>
#include <windows.h>
using namespace std;

// Прототипы функций
int powerNumber(int x, int n);
void exchangeValue(int a, int b);
void exchangePointer(int* a, int* b);
void exchangeReference(int& a, int& b);
void taskPower();
void taskPointers();
void taskExchange();

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do
    {
        cout << "\n====================================\n";
        cout << "       Лабораторная работа 1\n";
        cout << "====================================\n";
        cout << "1. Возведение числа в степень\n";
        cout << "2. Работа с указателями\n";
        cout << "3. Обмен переменных\n";
        cout << "0. Выход\n";
        cout << "------------------------------------\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice)
        {
        case 1: taskPower(); break;
        case 2: taskPointers(); break;
        case 3: taskExchange(); break;
        case 0: cout << "\nПрограмма завершена.\n"; break;
        default: cout << "\nОшибка: такого пункта нет.\n";
        }
    } while (choice != 0);

    return 0;
}

// Задание 1. Возведение в степень
int powerNumber(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++) result *= x;
    return result;
}

void taskPower()
{
    int x, n;
    cout << "\n--- Задание 1. Возведение в степень ---\n";
    cout << "Введите основание: ";
    cin >> x;
    cout << "Введите максимальную степень: ";
    cin >> n;

    for (int i = 0; i <= n; i++)
        cout << x << "^" << i << " = " << powerNumber(x, i) << endl;
}

// Задание 2. Работа с указателями
void taskPointers()
{
    int n;
    cout << "\n--- Задание 2. Работа с указателями ---\n";
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Ошибка: размер должен быть больше 0.\n";
        return;
    }

    int* arr = new int[n];
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int* p1 = arr;
    int* p2 = &arr[n - 1];

    cout << "\nАдрес p1: " << p1 << ", значение: " << *p1 << endl;
    if (n > 1)
    {
        p1++;
        cout << "После p1++ значение: " << *p1 << endl;
    }

    cout << "Значение p2: " << *p2 << endl;
    cout << "Разность p2 - p1 = " << p2 - p1 << endl;

    delete[] arr;
}

// Задание 3. Обмен переменных
void exchangeValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Внутри exchangeValue: a = " << a << ", b = " << b << endl;
}

void exchangePointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchangeReference(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void taskExchange()
{
    int a, b;
    cout << "\n--- Задание 3. Обмен переменных ---\n";
    cout << "Введите a и b: ";
    cin >> a >> b;

    cout << "\nДо exchangeValue: a = " << a << ", b = " << b << endl;
    exchangeValue(a, b);
    cout << "После exchangeValue: a = " << a << ", b = " << b << endl;

    cout << "\nДо exchangePointer: a = " << a << ", b = " << b << endl;
    exchangePointer(&a, &b);
    cout << "После exchangePointer: a = " << a << ", b = " << b << endl;

    cout << "\nДо exchangeReference: a = " << a << ", b = " << b << endl;
    exchangeReference(a, b);
    cout << "После exchangeReference: a = " << a << ", b = " << b << endl;
}