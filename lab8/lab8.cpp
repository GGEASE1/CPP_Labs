#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

class FileException
{
private:
    string msg;

public:
    FileException(string msg)
    {
        this->msg = msg;
    }

    string what()
    {
        return msg;
    }
};

class FileEncryptor
{
private:
    string inFile;
    string outFile;
    int key;

public:
    FileEncryptor(string inFile, string outFile, int key)
    {
        this->inFile = inFile;
        this->outFile = outFile;
        this->key = key;
    }

    void encrypt()
    {
        ifstream fin(inFile);
        if (!fin)
            throw FileException("Не удалось открыть входной файл");

        ofstream fout(outFile);
        if (!fout)
            throw FileException("Не удалось открыть выходной файл");

        char ch;
        while (fin.get(ch))
            fout.put(ch + key);

        fin.close();
        fout.close();
    }

    void decrypt()
    {
        ifstream fin(inFile);
        if (!fin)
            throw FileException("Не удалось открыть входной файл");

        ofstream fout(outFile);
        if (!fout)
            throw FileException("Не удалось открыть выходной файл");

        char ch;
        while (fin.get(ch))
            fout.put(ch - key);

        fin.close();
        fout.close();
    }
};

void showFile(string name)
{
    ifstream fin(name);
    if (!fin)
        throw FileException("Не удалось открыть файл");

    char ch;
    while (fin.get(ch))
        cout << ch;

    cout << endl;
    fin.close();
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string inFile = "text.txt";
    string outFile = "encrypted.txt";
    int key = 2;
    int c;

    do
    {
        cout << "\n=== ЛР8 ===\n";
        cout << "1. Показать входной файл\n";
        cout << "2. Зашифровать файл\n";
        cout << "3. Расшифровать файл\n";
        cout << "4. Задать файлы и ключ\n";
        cout << "0. Выход\n> ";
        cin >> c;

        try
        {
            if (c == 1)
            {
                showFile(inFile);
            }
            else if (c == 2)
            {
                FileEncryptor f(inFile, outFile, key);
                f.encrypt();
                cout << "Файл зашифрован\n";
            }
            else if (c == 3)
            {
                FileEncryptor f(outFile, "decoded.txt", key);
                f.decrypt();
                cout << "Файл расшифрован в decoded.txt\n";
            }
            else if (c == 4)
            {
                cout << "Введите входной файл: ";
                cin >> inFile;
                cout << "Введите выходной файл: ";
                cin >> outFile;
                cout << "Введите ключ: ";
                cin >> key;
            }
        }
        catch (FileException e)
        {
            cout << "Ошибка: " << e.what() << endl;
        }

    } while (c != 0);

    return 0;
}