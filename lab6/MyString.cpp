#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
    str[0] = '\0';
}

MyString::MyString(const char* s)
{
    strcpy(str, s);
}

MyString::MyString(const MyString& other)
{
    strcpy(str, other.str);
}

void MyString::input()
{
    cout << "Введите строку: ";
    cin.getline(str, 100);
}

void MyString::print()
{
    cout << str << endl;
}

int MyString::length()
{
    return strlen(str);
}

MyString MyString::operator+(const MyString& other)
{
    MyString temp;
    strcpy(temp.str, str);
    strcat(temp.str, other.str);
    return temp;
}

bool MyString::operator==(const MyString& other)
{
    return strcmp(str, other.str) == 0;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
        strcpy(str, other.str);

    return *this;
}