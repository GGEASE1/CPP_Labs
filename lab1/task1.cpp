#include <iostream>
using namespace std;

// Функция вычисляет x^n
int power(int x, int n)
{
    int result = 1;

    // Умножаем x само на себя n раз
    for (int i = 0; i < n; i++)
        result *= x;

    return result;
}

int main()
{
    int x, n;

    // Ввод основания степени
    cout << "Enter base: ";
    cin >> x;

    // Ввод максимальной степени
    cout << "Enter max power: ";
    cin >> n;

    // Вывод степеней от 0 до n
    for (int i = 0; i <= n; i++)
        cout << x << "^" << i << " = " << power(x, i) << endl;

    return 0;
}