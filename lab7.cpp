#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ===== АБСТРАКТНЫЙ КЛАСС =====
class Point
{
protected:
    int x, y;
    string color;

public:
    Point(int x = 0, int y = 0, string color = "white")
    {
        this->x = x;
        this->y = y;
        this->color = color;
    }

    virtual void show() = 0;
    virtual void hide() = 0;

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    void setColor(const string& c)
    {
        color = c;
    }

    virtual ~Point() {}
};

// ===== КРУГ =====
class Circle : public Point
{
protected:
    int radius;

public:
    Circle(int x = 0, int y = 0, int r = 10, string color = "white")
        : Point(x, y, color)
    {
        radius = r;
    }

    void show() override
    {
        cout << "Круг: x=" << x
             << " y=" << y
             << " r=" << radius
             << " color=" << color << endl;
    }

    void hide() override
    {
        cout << "Круг скрыт\n";
    }
};

// ===== КОЛЬЦО =====
class Ring : public Circle
{
private:
    int width;
    int sector;

public:
    Ring(int x = 0, int y = 0, int r = 10, int w = 3,
         int s = 60, string color = "white")
        : Circle(x, y, r, color)
    {
        width = w;
        sector = s;
    }

    void show() override
    {
        cout << "Кольцо: x=" << x
             << " y=" << y
             << " r=" << radius
             << " width=" << width
             << " sector=" << sector
             << " color=" << color << endl;
    }

    void hide() override
    {
        cout << "Кольцо скрыто\n";
    }

    void widenSector(int d)
    {
        sector += d;
        if (sector > 360) sector = 360;
    }

    void narrowSector(int d)
    {
        sector -= d;
        if (sector < 0) sector = 0;
    }

    void moveWithColor(int dx, int dy, const string& newColor)
    {
        move(dx, dy);
        color = newColor;
    }
};

// ===== ПОКАЗАТЬ ОБА ОБЪЕКТА =====
void showObjects(Circle& c, Ring& r)
{
    cout << endl;
    c.show();
    r.show();
}

// ===== ПЕРЕМЕЩЕНИЕ ОБЪЕКТОВ =====
void moveObjects(Circle& c, Ring& r)
{
    int dx1, dy1, dx2, dy2;

    cout << "Введите dx и dy для круга: ";
    cin >> dx1 >> dy1;

    cout << "Введите dx и dy для кольца: ";
    cin >> dx2 >> dy2;

    c.move(dx1, dy1);
    r.move(dx2, dy2);

    showObjects(c, r);
}

// ===== ИЗМЕНЕНИЕ СЕКТОРА =====
void changeSector(Ring& r)
{
    int ch, d;

    cout << "1. Расширить сектор\n";
    cout << "2. Сузить сектор\n> ";
    cin >> ch;

    cout << "На сколько изменить: ";
    cin >> d;

    if (ch == 1) r.widenSector(d);
    else if (ch == 2) r.narrowSector(d);

    r.show();
}

// ===== ПЕРЕМЕЩЕНИЕ КОЛЬЦА СО СМЕНОЙ ЦВЕТА =====
void moveRingColor(Ring& r)
{
    int dx, dy;
    string color;

    cout << "Введите dx и dy: ";
    cin >> dx >> dy;

    cout << "Введите новый цвет: ";
    cin >> color;

    r.moveWithColor(dx, dy, color);
    r.show();
}

// ===== СКРЫТЬ ОБЪЕКТЫ =====
void hideObjects(Circle& c, Ring& r)
{
    c.hide();
    r.hide();
}

// ===== MAIN =====
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Circle c(10, 10, 15, "red");
    Ring r(30, 20, 20, 4, 90, "blue");

    int ch;
    do
    {
        cout << "\n=== ЛР7 ===\n";
        cout << "1. Показать объекты\n";
        cout << "2. Переместить объекты\n";
        cout << "3. Изменить сектор кольца\n";
        cout << "4. Переместить кольцо и сменить цвет\n";
        cout << "5. Скрыть объекты\n";
        cout << "0. Выход\n> ";
        cin >> ch;

        if      (ch == 1) showObjects(c, r);
        else if (ch == 2) moveObjects(c, r);
        else if (ch == 3) changeSector(r);
        else if (ch == 4) moveRingColor(r);
        else if (ch == 5) hideObjects(c, r);

    } while (ch != 0);

    return 0;
}