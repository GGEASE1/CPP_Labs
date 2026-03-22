#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

// ===== ШАБЛОН СОРТИРОВКИ =====
template <class T>
void Sort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                T t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

// ===== ШАБЛОН МАКСИМУМА =====
template <class T>
T getmax(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
T getmax(T a[], int n)
{
    T m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}

char* getmax(char* s1, char* s2)
{
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

// ===== ШАБЛОН СТЕКА =====
template <class T, int maxSize>
class TStack
{
private:
    T items[maxSize];
    int top;

public:
    TStack()
    {
        top = -1;
    }

    bool push(T x)
    {
        if (top >= maxSize - 1) return false;
        items[++top] = x;
        return true;
    }

    bool pop(T& x)
    {
        if (top < 0) return false;
        x = items[top--];
        return true;
    }

    bool empty()
    {
        return top == -1;
    }

    void print()
    {
        if (empty())
        {
            cout << "Стек пуст\n";
            return;
        }

        for (int i = top; i >= 0; i--)
            cout << items[i] << " ";
        cout << endl;
    }
};

// ===== ВЫВОД МАССИВА =====
template <class T>
void printArray(T a[], int n)
{
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

// ===== 1. СОРТИРОВКА =====
void task1()
{
    int a[] = {10, 20, 30, 11, 25, 32, 0};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\nДо сортировки:\n";
    printArray(a, n);

    Sort(a, n);

    cout << "После сортировки:\n";
    printArray(a, n);
}

// ===== 2. МАКСИМУМ ДВУХ ЧИСЕЛ =====
void task2()
{
    int x, y;
    cout << "\nВведите два числа: ";
    cin >> x >> y;

    cout << "Максимум = " << getmax(x, y) << endl;
}

// ===== 3. МАКСИМУМ МАССИВА =====
void task3()
{
    int a[] = {10, 20, 30, 11, 25, 32, 0};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\nМассив:\n";
    printArray(a, n);

    cout << "Максимум массива = " << getmax(a, n) << endl;
}

// ===== 4. МАКСИМУМ ИЗ ДВУХ СТРОК =====
void task4()
{
    char s1[100], s2[100];

    cout << "\nВведите первую строку: ";
    cin.ignore(1000, '\n');
    cin.getline(s1, 100);

    cout << "Введите вторую строку: ";
    cin.getline(s2, 100);

    cout << "Максимальная строка = " << getmax(s1, s2) << endl;
}

// ===== 5. СТЕК =====
void task5()
{
    TStack<int, 10> st;
    int c, x;

    do
    {
        cout << "\n--- Стек ---\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Показать стек\n";
        cout << "0. Назад\n> ";
        cin >> c;

        if (c == 1)
        {
            cout << "Введите число: ";
            cin >> x;

            if (st.push(x)) cout << "Элемент добавлен\n";
            else cout << "Стек заполнен\n";
        }
        else if (c == 2)
        {
            if (st.pop(x)) cout << "Удалён элемент: " << x << endl;
            else cout << "Стек пуст\n";
        }
        else if (c == 3)
            st.print();

    } while (c != 0);
}

// ===== MAIN =====
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int c;
    do
    {
        cout << "\n=== ЛР9 ===\n";
        cout << "1. Шаблон сортировки\n";
        cout << "2. Шаблон getmax для двух чисел\n";
        cout << "3. Шаблон getmax для массива\n";
        cout << "4. getmax для строк\n";
        cout << "5. Шаблонный стек\n";
        cout << "0. Выход\n> ";
        cin >> c;

        if      (c == 1) task1();
        else if (c == 2) task2();
        else if (c == 3) task3();
        else if (c == 4) task4();
        else if (c == 5) task5();

    } while (c != 0);

    return 0;
}