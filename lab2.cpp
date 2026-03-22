#include <iostream>
#include <windows.h>
using namespace std;

const int N = 5;

void fillMatrix(double a[N][N])
{
    cout << "Введите элементы матрицы " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
}

void printMatrix(double a[N][N])
{
    cout << "\nМатрица:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

double minMatrix(double a[N][N])
{
    double mn = a[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] < mn) mn = a[i][j];
    return mn;
}

double maxMatrix(double a[N][N])
{
    double mx = a[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] > mx) mx = a[i][j];
    return mx;
}

double maxLower(double a[N][N])
{
    double mx = a[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (a[i][j] > mx) mx = a[i][j];
    return mx;
}

double maxUpper(double a[N][N])
{
    double mx = a[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (a[i][j] > mx) mx = a[i][j];
    return mx;
}

double minLower(double a[N][N])
{
    double mn = a[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (a[i][j] < mn) mn = a[i][j];
    return mn;
}

double minUpper(double a[N][N])
{
    double mn = a[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (a[i][j] < mn) mn = a[i][j];
    return mn;
}

double minMainDiag(double a[N][N])
{
    double mn = a[0][0];
    for (int i = 0; i < N; i++)
        if (a[i][i] < mn) mn = a[i][i];
    return mn;
}

double maxMainDiag(double a[N][N])
{
    double mx = a[0][0];
    for (int i = 0; i < N; i++)
        if (a[i][i] > mx) mx = a[i][i];
    return mx;
}

double minSideDiag(double a[N][N])
{
    double mn = a[0][N - 1];
    for (int i = 0; i < N; i++)
        if (a[i][N - 1 - i] < mn) mn = a[i][N - 1 - i];
    return mn;
}

double maxSideDiag(double a[N][N])
{
    double mx = a[0][N - 1];
    for (int i = 0; i < N; i++)
        if (a[i][N - 1 - i] > mx) mx = a[i][N - 1 - i];
    return mx;
}

double avgMatrix(double a[N][N])
{
    double s = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            s += a[i][j];
    return s / (N * N);
}

double avgLower(double a[N][N])
{
    double s = 0;
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            s += a[i][j];
            k++;
        }
    return s / k;
}

double avgUpper(double a[N][N])
{
    double s = 0;
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            s += a[i][j];
            k++;
        }
    return s / k;
}

void rowSums(double a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        double s = 0;
        for (int j = 0; j < N; j++) s += a[i][j];
        cout << "Сумма строки " << i + 1 << ": " << s << endl;
    }
}

void colSums(double a[N][N])
{
    for (int j = 0; j < N; j++)
    {
        double s = 0;
        for (int i = 0; i < N; i++) s += a[i][j];
        cout << "Сумма столбца " << j + 1 << ": " << s << endl;
    }
}

void rowMins(double a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        double mn = a[i][0];
        for (int j = 1; j < N; j++)
            if (a[i][j] < mn) mn = a[i][j];
        cout << "Минимум строки " << i + 1 << ": " << mn << endl;
    }
}

void colMins(double a[N][N])
{
    for (int j = 0; j < N; j++)
    {
        double mn = a[0][j];
        for (int i = 1; i < N; i++)
            if (a[i][j] < mn) mn = a[i][j];
        cout << "Минимум столбца " << j + 1 << ": " << mn << endl;
    }
}

void rowMaxs(double a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        double mx = a[i][0];
        for (int j = 1; j < N; j++)
            if (a[i][j] > mx) mx = a[i][j];
        cout << "Максимум строки " << i + 1 << ": " << mx << endl;
    }
}

void colMaxs(double a[N][N])
{
    for (int j = 0; j < N; j++)
    {
        double mx = a[0][j];
        for (int i = 1; i < N; i++)
            if (a[i][j] > mx) mx = a[i][j];
        cout << "Максимум столбца " << j + 1 << ": " << mx << endl;
    }
}

void rowAvgs(double a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        double s = 0;
        for (int j = 0; j < N; j++) s += a[i][j];
        cout << "Среднее строки " << i + 1 << ": " << s / N << endl;
    }
}

void colAvgs(double a[N][N])
{
    for (int j = 0; j < N; j++)
    {
        double s = 0;
        for (int i = 0; i < N; i++) s += a[i][j];
        cout << "Среднее столбца " << j + 1 << ": " << s / N << endl;
    }
}

void sumLowerUpper(double a[N][N])
{
    double lower = 0, upper = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (j <= i) lower += a[i][j];
            if (j >= i) upper += a[i][j];
        }

    cout << "Сумма нижней части: " << lower << endl;
    cout << "Сумма верхней части: " << upper << endl;
}

void closestToAvg(double a[N][N])
{
    double avg = avgMatrix(a);
    double best = a[0][0];
    double diff = best - avg;
    if (diff < 0) diff = -diff;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            double cur = a[i][j] - avg;
            if (cur < 0) cur = -cur;

            if (cur < diff)
            {
                diff = cur;
                best = a[i][j];
            }
        }

    cout << "Среднее матрицы: " << avg << endl;
    cout << "Ближайший элемент: " << best << endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double a[N][N];
    int c;

    fillMatrix(a);
    printMatrix(a);

    do
    {
        cout << "\n=== ЛР2 ===\n";
        cout << "1. Минимум матрицы\n";
        cout << "2. Максимум матрицы\n";
        cout << "3. Максимум нижней части\n";
        cout << "4. Максимум верхней части\n";
        cout << "5. Минимум нижней части\n";
        cout << "6. Минимум верхней части\n";
        cout << "7. Минимум главной диагонали\n";
        cout << "8. Максимум главной диагонали\n";
        cout << "9. Минимум побочной диагонали\n";
        cout << "10. Максимум побочной диагонали\n";
        cout << "11. Среднее всей матрицы\n";
        cout << "12. Среднее нижней части\n";
        cout << "13. Среднее верхней части\n";
        cout << "14. Суммы строк\n";
        cout << "15. Суммы столбцов\n";
        cout << "16. Минимумы строк\n";
        cout << "17. Минимумы столбцов\n";
        cout << "18. Максимумы строк\n";
        cout << "19. Максимумы столбцов\n";
        cout << "20. Средние строк\n";
        cout << "21. Средние столбцов\n";
        cout << "22. Суммы нижней и верхней частей\n";
        cout << "23. Элемент, ближайший к среднему\n";
        cout << "24. Показать матрицу\n";
        cout << "0. Выход\n> ";
        cin >> c;

        if      (c == 1)  cout << "Минимум: " << minMatrix(a) << endl;
        else if (c == 2)  cout << "Максимум: " << maxMatrix(a) << endl;
        else if (c == 3)  cout << "Максимум нижней части: " << maxLower(a) << endl;
        else if (c == 4)  cout << "Максимум верхней части: " << maxUpper(a) << endl;
        else if (c == 5)  cout << "Минимум нижней части: " << minLower(a) << endl;
        else if (c == 6)  cout << "Минимум верхней части: " << minUpper(a) << endl;
        else if (c == 7)  cout << "Минимум главной диагонали: " << minMainDiag(a) << endl;
        else if (c == 8)  cout << "Максимум главной диагонали: " << maxMainDiag(a) << endl;
        else if (c == 9)  cout << "Минимум побочной диагонали: " << minSideDiag(a) << endl;
        else if (c == 10) cout << "Максимум побочной диагонали: " << maxSideDiag(a) << endl;
        else if (c == 11) cout << "Среднее матрицы: " << avgMatrix(a) << endl;
        else if (c == 12) cout << "Среднее нижней части: " << avgLower(a) << endl;
        else if (c == 13) cout << "Среднее верхней части: " << avgUpper(a) << endl;
        else if (c == 14) rowSums(a);
        else if (c == 15) colSums(a);
        else if (c == 16) rowMins(a);
        else if (c == 17) colMins(a);
        else if (c == 18) rowMaxs(a);
        else if (c == 19) colMaxs(a);
        else if (c == 20) rowAvgs(a);
        else if (c == 21) colAvgs(a);
        else if (c == 22) sumLowerUpper(a);
        else if (c == 23) closestToAvg(a);
        else if (c == 24) printMatrix(a);

    } while (c != 0);
}