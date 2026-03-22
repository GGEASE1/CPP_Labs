#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Bus
{
    int number;
    string driver;
    string route;
};

struct Node
{
    Bus data;
    Node* next;
    Node* prev;
};

class BusPark
{
private:
    Node* head;
    Node* tail;

public:
    BusPark()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~BusPark()
    {
        Node* p = head;
        while (p)
        {
            Node* t = p;
            p = p->next;
            delete t;
        }
    }

    void addBus(Bus bus)
    {
        Node* p = new Node;
        p->data = bus;
        p->next = nullptr;
        p->prev = tail;

        if (head == nullptr)
            head = tail = p;
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    void showPark()
    {
        if (head == nullptr)
        {
            cout << "Парк пуст\n";
            return;
        }

        Node* p = head;
        cout << "\nАвтобусы в парке:\n";

        while (p)
        {
            cout << "Номер: " << p->data.number
                 << ", Водитель: " << p->data.driver
                 << ", Маршрут: " << p->data.route << endl;
            p = p->next;
        }
    }

    void departBus(int number)
    {
        Node* p = head;

        while (p)
        {
            if (p->data.number == number)
            {
                if (p->prev) p->prev->next = p->next;
                else head = p->next;

                if (p->next) p->next->prev = p->prev;
                else tail = p->prev;

                cout << "Автобус " << p->data.number
                     << " выехал на маршрут "
                     << p->data.route << endl;

                delete p;
                return;
            }

            p = p->next;
        }

        cout << "Автобус не найден\n";
    }

    void returnBus(Bus bus)
    {
        addBus(bus);
        cout << "Автобус " << bus.number
             << " вернулся в парк\n";
    }

    bool empty()
    {
        return head == nullptr;
    }
};

Bus inputBus()
{
    Bus bus;

    cout << "Введите номер автобуса: ";
    cin >> bus.number;
    cin.ignore(1000, '\n');

    cout << "Введите водителя: ";
    getline(cin, bus.driver);

    cout << "Введите маршрут: ";
    getline(cin, bus.route);

    return bus;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    BusPark park;
    int c;

    do
    {
        cout << "\n=== ЛР10 ===\n";
        cout << "1. Показать автобусы\n";
        cout << "2. Добавить автобус в парк\n";
        cout << "3. Выезд автобуса\n";
        cout << "4. Возврат автобуса\n";
        cout << "5. Добавить тестовые данные\n";
        cout << "0. Выход\n> ";
        cin >> c;

        if (c == 1)
        {
            park.showPark();
        }
        else if (c == 2)
        {
            cin.ignore(1000, '\n');
            Bus bus = inputBus();
            park.addBus(bus);
        }
        else if (c == 3)
        {
            int number;
            cout << "Введите номер автобуса: ";
            cin >> number;
            park.departBus(number);
        }
        else if (c == 4)
        {
            cin.ignore(1000, '\n');
            Bus bus = inputBus();
            park.returnBus(bus);
        }
        else if (c == 5)
        {
            park.addBus({101, "Иванов", "Маршрут 1"});
            park.addBus({202, "Петров", "Маршрут 2"});
            park.addBus({303, "Сидоров", "Маршрут 3"});
            cout << "Тестовые данные добавлены\n";
        }

    } while (c != 0);

    return 0;
}