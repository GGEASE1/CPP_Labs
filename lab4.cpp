#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

// ===== ВВОД =====
void inputStrings(char s1[], char s2[])
{
    cout << "\nВведите первую строку: ";
    cin.getline(s1, 100);

    cout << "Введите вторую строку: ";
    cin.getline(s2, 100);
}

void printStrings(char s1[], char s2[])
{
    cout << "\nstr1 = " << s1 << endl;
    cout << "str2 = " << s2 << endl;
}

// ===== СВОИ ФУНКЦИИ ДЛИНЫ =====
int len1(char s[])
{
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int len2(char s[])
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) n++;
    return n;
}

int len3(char* s)
{
    int n = 0;
    while (*s)
    {
        n++;
        s++;
    }
    return n;
}

// ===== КОПИРОВАНИЕ =====
void copyStr(char a[], char b[])
{
    int i = 0;
    while (b[i] != '\0')
    {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

// ===== СРАВНЕНИЕ =====
int compareStr(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return a[i] - b[i];
        i++;
    }
    return a[i] - b[i];
}

// ===== СЦЕПЛЕНИЕ =====
void concatStr(char a[], char b[])
{
    int i = 0, j = 0;

    while (a[i] != '\0') i++;
    while (b[j] != '\0')
    {
        a[i] = b[j];
        i++;
        j++;
    }

    a[i] = '\0';
}

// ===== ЗАДАНИЕ 1. БИБЛИОТЕЧНЫЕ =====
void task1(char s1[], char s2[])
{
    char a[200], b[200];

    copyStr(a, s1);
    copyStr(b, s2);

    cout << "\n--- Библиотечные функции ---\n";
    cout << "strlen(str1) = " << strlen(a) << endl;
    cout << "strlen(str2) = " << strlen(b) << endl;

    char c1[200], c2[200];
    strcpy(c1, a);
    strcpy(c2, b);

    cout << "\nПосле strcpy:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "\nstrcmp(str1, str2) = "
         << strcmp(a, b) << endl;

    strcat(c1, c2);
    cout << "После strcat(c1, c2): "
         << c1 << endl;
}

// ===== ЗАДАНИЕ 2. СВОИ ФУНКЦИИ =====
void task2(char s1[], char s2[])
{
    cout << "\n--- Свои функции ---\n";

    cout << "len1(str1) = " << len1(s1) << endl;
    cout << "len1(str2) = " << len1(s2) << endl;

    cout << "len2(str1) = " << len2(s1) << endl;
    cout << "len2(str2) = " << len2(s2) << endl;

    cout << "len3(str1) = " << len3(s1) << endl;
    cout << "len3(str2) = " << len3(s2) << endl;

    char c1[200], c2[200], c3[200];
    copyStr(c1, s1);
    copyStr(c2, s2);

    cout << "\nПосле copyStr:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "\ncompareStr(str1, str2) = "
         << compareStr(s1, s2) << endl;

    copyStr(c3, s1);
    concatStr(c3, s2);

    cout << "После concatStr(str1, str2): "
         << c3 << endl;
}

// ===== MAIN =====
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char str1[100];
    char str2[100];
    inputStrings(str1, str2);
    
    int c;

    do
    {
        cout << "\n=== ЛР4 ===\n";
        cout << "1. Показать строки\n";
        cout << "2. Библиотечные функции\n";
        cout << "3. Свои функции\n";
        cout << "4. Ввести строки заново\n";
        cout << "0. Выход\n> ";
        cin >> c;
        cin.ignore();

        if      (c == 1) printStrings(str1, str2);
        else if (c == 2) task1(str1, str2);
        else if (c == 3) task2(str1, str2);
        else if (c == 4) inputStrings(str1, str2);

    } while (c != 0);
}