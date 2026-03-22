#include <iostream>
#include <windows.h>
using namespace std;

void inputArray(int* a, int n)
{
    cout << "\nВведите элементы массива:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
}

void printArray(int* a, int n)
{
    cout << "Массив: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void copyArray(int* a, int* b, int n)
{
    for (int i = 0; i < n; i++) b[i] = a[i];
}

void swapValues(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

// ===== 1. МИНИ-МАКС =====
void minMaxSort(int* a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int min = i, max = i;

        for (int j = i; j < n - i; j++)
        {
            if (a[j] < a[min]) min = j;
            if (a[j] > a[max]) max = j;
        }

        swapValues(a[i], a[min]);
        if (max == i) max = min;
        swapValues(a[n - i - 1], a[max]);
    }
}

// ===== 2. ПУЗЫРЁК =====
void bubbleSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
                swapValues(a[j], a[j + 1]);
}

// ===== 2. БЫСТРАЯ =====
void quickSort(int* a, int l, int r)
{
    int i = l, j = r;
    int x = a[(l + r) / 2];

    while (i <= j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j)
        {
            swapValues(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

// ===== 3. ЧЁТНЫЕ / НЕЧЁТНЫЕ =====
void evenOddSort(int* a, int n)
{
    int* even = new int[n];
    int* odd = new int[n];
    int e = 0, o = 0;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0) even[e++] = a[i];
        else odd[o++] = a[i];

    bubbleSort(even, e);
    bubbleSort(odd, o);

    for (int i = 0; i < o / 2; i++)
        swapValues(odd[i], odd[o - 1 - i]);

    for (int i = 0; i < e; i++) a[i] = even[i];
    for (int i = 0; i < o; i++) a[e + i] = odd[i];

    delete[] even;
    delete[] odd;
}

// ===== 4. УЧАСТОК ПО ВОЗРАСТАНИЮ =====
void partSortAsc(int* a, int l, int r)
{
    for (int i = l; i < r; i++)
        for (int j = l; j < r - (i - l); j++)
            if (a[j] > a[j + 1])
                swapValues(a[j], a[j + 1]);
}

// ===== 5. УЧАСТОК ПО УБЫВАНИЮ =====
void partSortDesc(int* a, int l, int r)
{
    for (int i = l; i < r; i++)
        for (int j = l; j < r - (i - l); j++)
            if (a[j] < a[j + 1])
                swapValues(a[j], a[j + 1]);
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Ошибка\n";
        return 0;
    }

    int* a = new int[n];
    int* b = new int[n];
    inputArray(a, n);

    int c;
    do
    {
        cout << "\n=== ЛР3 ===\n";
        cout << "1. Показать массив\n";
        cout << "2. Мини-макс сортировка\n";
        cout << "3. Пузырёк\n";
        cout << "4. Быстрая сортировка\n";
        cout << "5. Чётные ↑, нечётные ↓\n";
        cout << "6. Участок ↑\n";
        cout << "7. Участок ↓\n";
        cout << "8. Ввести массив заново\n";
        cout << "0. Выход\n> ";
        cin >> c;

        copyArray(a, b, n);

        if (c == 1)
            printArray(a, n);
        else if (c == 2)
        {
            minMaxSort(b, n);
            printArray(b, n);
        }
        else if (c == 3)
        {
            bubbleSort(b, n);
            printArray(b, n);
        }
        else if (c == 4)
        {
            quickSort(b, 0, n - 1);
            printArray(b, n);
        }
        else if (c == 5)
        {
            evenOddSort(b, n);
            printArray(b, n);
        }
        else if (c == 6)
        {
            int l, r;
            cout << "Введите N1 и N2: ";
            cin >> l >> r;

            if (l < 0 || r >= n || l > r) cout << "Ошибка\n";
            else
            {
                partSortAsc(b, l, r);
                printArray(b, n);
            }
        }
        else if (c == 7)
        {
            int l, r;
            cout << "Введите N1 и N2: ";
            cin >> l >> r;

            if (l < 0 || r >= n || l > r) cout << "Ошибка\n";
            else
            {
                partSortDesc(b, l, r);
                printArray(b, n);
            }
        }
        else if (c == 8)
            inputArray(a, n);

    } while (c != 0);

    delete[] a;
    delete[] b;
}