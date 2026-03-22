#include <iostream>
#include <windows.h>
using namespace std;

// ===== ЗАДАНИЕ 1 =====
int power(int x, int n)
{
    int r = 1;
    for (int i = 0; i < n; i++) r *= x;
    return r;
}

void task1()
{
    int x, n;
    cout << "\n--- Степени числа ---\nВведите число и степень: ";
    cin >> x >> n;

    for (int i = 0; i <= n; i++)
        cout << x << "^" << i << " = " << power(x, i) << endl;
}

// ===== ЗАДАНИЕ 2 =====
void task2()
{
    int n;
    cout << "\n--- Указатели ---\nРазмер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Ошибка\n";
        return;
    }

    int* a = new int[n];
    cout << "Введите элементы:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    int* p1 = a;
    int* p2 = &a[n - 1];

    cout << "\np1: " << *p1 << endl;
    if (n > 1) cout << "p1++ -> " << *(++p1) << endl;

    cout << "p2: " << *p2 << endl;
    cout << "p2 - p1 = " << p2 - p1 << endl;

    delete[] a;
}

// ===== ЗАДАНИЕ 3 =====
void swapVal(int a, int b)
{
    int t = a; 
    a = b;
    b = t;
    cout << "Внутри (value): " << a << " " << b << endl;
}

void swapPtr(int* a, int* b)
{
    int t = *a; 
    *a = *b; 
    *b = t;
}

void swapRef(int& a, int& b)
{
    int t = a; 
    a = b; 
    b = t;
}

void task3()
{
    int a, b;
    cout << "\n--- Обмен ---\nВведите a и b: ";
    cin >> a >> b;

    cout << "\nДо: " << a << " " << b << endl;
    cout << "(value не меняет оригинал)\n";

    swapVal(a, b);
    cout << "После value: " << a << " " << b << endl;

    swapPtr(&a, &b);
    cout << "После pointer: " << a << " " << b << endl;

    swapRef(a, b);
    cout << "После reference: " << a << " " << b << endl;
}

// ===== MAIN =====
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int c;
    do
    {
        cout << "\n=== ЛР1 ===\n1. Степень\n2. Указатели\n3. Обмен\n0. Выход\n> ";
        cin >> c;

        if      (c == 1) task1();
        else if (c == 2) task2();
        else if (c == 3) task3();

    } while (c != 0);
}