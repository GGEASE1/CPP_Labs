#include <iostream>
#include <windows.h>
using namespace std;

// Прототипы функций
void inputArray(int* a, int n);
void printArray(int* a, int n);
void copyArray(int* a, int* b, int n);
void swapValues(int& x, int& y);

void selectionSort(int* a, int n);
void bubbleSort(int* a, int n);
void quickSort(int* a, int left, int right);
void evenOddSort(int* a, int n);
void partSortAsc(int* a, int left, int right);
void partSortDesc(int* a, int left, int right);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Ошибка: размер массива должен быть больше 0.\n";
        return 0;
    }

    int* a = new int[n];
    int* b = new int[n];

    inputArray(a, n);

    int choice;
    do
    {
        cout << "\n====================================\n";
        cout << "       Лабораторная работа 3\n";
        cout << "====================================\n";
        cout << "1. Показать массив\n";
        cout << "2. Сортировка методом выбора\n";
        cout << "3. Сортировка методом пузырька\n";
        cout << "4. Быстрая сортировка\n";
        cout << "5. Чётные по возрастанию, нечётные по убыванию\n";
        cout << "6. Сортировка части массива по возрастанию\n";
        cout << "7. Сортировка части массива по убыванию\n";
        cout << "8. Ввести массив заново\n";
        cout << "0. Выход\n";
        cout << "------------------------------------\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        copyArray(a, b, n);

        switch (choice)
        {
        case 1:
            printArray(a, n);
            break;

        case 2:
            selectionSort(b, n);
            cout << "\nСортировка методом выбора:\n";
            printArray(b, n);
            break;

        case 3:
            bubbleSort(b, n);
            cout << "\nСортировка методом пузырька:\n";
            printArray(b, n);
            break;

        case 4:
            quickSort(b, 0, n - 1);
            cout << "\nБыстрая сортировка:\n";
            printArray(b, n);
            break;

        case 5:
            evenOddSort(b, n);
            cout << "\nЧётные по возрастанию, нечётные по убыванию:\n";
            printArray(b, n);
            break;

        case 6:
        {
            int left, right;
            cout << "Введите N1 и N2: ";
            cin >> left >> right;

            if (left < 0 || right >= n || left > right)
                cout << "Ошибка: неверный интервал.\n";
            else
            {
                partSortAsc(b, left, right);
                cout << "\nСортировка части массива по возрастанию:\n";
                printArray(b, n);
            }
            break;
        }

        case 7:
        {
            int left, right;
            cout << "Введите N1 и N2: ";
            cin >> left >> right;

            if (left < 0 || right >= n || left > right)
                cout << "Ошибка: неверный интервал.\n";
            else
            {
                partSortDesc(b, left, right);
                cout << "\nСортировка части массива по убыванию:\n";
                printArray(b, n);
            }
            break;
        }

        case 8:
            inputArray(a, n);
            break;

        case 0:
            cout << "\nПрограмма завершена.\n";
            break;

        default:
            cout << "\nОшибка: такого пункта нет.\n";
        }

    } while (choice != 0);

    delete[] a;
    delete[] b;
    return 0;
}

// Ввод массива
void inputArray(int* a, int n)
{
    cout << "\nВведите элементы массива:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

// Вывод массива
void printArray(int* a, int n)
{
    cout << "Массив: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Копирование массива
void copyArray(int* a, int* b, int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

// Обмен двух элементов
void swapValues(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

// Сортировка методом выбора
void selectionSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIndex])
                minIndex = j;

        swapValues(a[i], a[minIndex]);
    }
}

// Сортировка пузырьком
void bubbleSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
                swapValues(a[j], a[j + 1]);
}

// Быстрая сортировка
void quickSort(int* a, int left, int right)
{
    int i = left;
    int j = right;
    int middle = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < middle) i++;
        while (a[j] > middle) j--;

        if (i <= j)
        {
            swapValues(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

// Чётные по возрастанию, нечётные по убыванию
void evenOddSort(int* a, int n)
{
    int* even = new int[n];
    int* odd = new int[n];
    int evenCount = 0, oddCount = 0;

    // Разделяем элементы
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) even[evenCount++] = a[i];
        else odd[oddCount++] = a[i];
    }

    // Сортируем чётные по возрастанию
    bubbleSort(even, evenCount);

    // Сортируем нечётные по возрастанию, потом переворачиваем
    bubbleSort(odd, oddCount);
    for (int i = 0; i < oddCount / 2; i++)
        swapValues(odd[i], odd[oddCount - 1 - i]);

    // Собираем массив заново
    for (int i = 0; i < evenCount; i++)
        a[i] = even[i];

    for (int i = 0; i < oddCount; i++)
        a[evenCount + i] = odd[i];

    delete[] even;
    delete[] odd;
}

// Сортировка части массива по возрастанию
void partSortAsc(int* a, int left, int right)
{
    for (int i = left; i < right; i++)
        for (int j = left; j < right - (i - left); j++)
            if (a[j] > a[j + 1])
                swapValues(a[j], a[j + 1]);
}

// Сортировка части массива по убыванию
void partSortDesc(int* a, int left, int right)
{
    for (int i = left; i < right; i++)
        for (int j = left; j < right - (i - left); j++)
            if (a[j] < a[j + 1])
                swapValues(a[j], a[j + 1]);
}