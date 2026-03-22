#include <iostream>
using namespace std;

// 1. Передача по значению
// Меняются только копии переменных (оригиналы не изменяются)
void swap1(int a, int b)
{
    int t = a;
    a = b;
    b = t;

    cout << "Inside swap1: a = " << a << ", b = " << b << endl;
}

// 2. Передача через указатели
// Меняются реальные значения по адресам
void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 3. Передача по ссылке
// Самый удобный способ — меняются реальные переменные
void swap3(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a, b;

    // Ввод значений
    cout << "Enter a and b: ";
    cin >> a >> b;

    // Проверка swap1
    cout << "\nBefore swap1: " << a << " " << b << endl;
    swap1(a, b);
    cout << "After swap1: " << a << " " << b << endl;

    // Проверка swap2
    cout << "\nBefore swap2: " << a << " " << b << endl;
    swap2(&a, &b);
    cout << "After swap2: " << a << " " << b << endl;

    // Проверка swap3
    cout << "\nBefore swap3: " << a << " " << b << endl;
    swap3(a, b);
    cout << "After swap3: " << a << " " << b << endl;

    return 0;
}