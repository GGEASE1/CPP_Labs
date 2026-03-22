#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
private:
    char str[100];

public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);

    void input();
    void print();
    int length();

    MyString operator+(const MyString& other);
    bool operator==(const MyString& other);
    MyString& operator=(const MyString& other);
};

#endif