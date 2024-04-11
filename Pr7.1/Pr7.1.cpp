#include <iostream>
#include <iomanip>
#include <time.h>
#include <algorithm>
#include <locale>

using namespace std;

const int ROWS = 7;
const int COLS = 9;

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** q, const int rowCount, const int colCount);
void Sort(int** q, const int rowCount, const int colCount);
void Change(int** q, const int row1, const int row2);
void Calc(int** q, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));
    int Low = -41;
    int High = 23;
    int rowCount = ROWS;
    int colCount = COLS;

    setlocale(LC_ALL, "en_US.UTF-8"); // Встановлення кодування виводу

    int** q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        q[i] = new int[colCount];

    Create(q, rowCount, colCount, Low, High);
    cout << "Матриця до сортування:" << endl;
    Print(q, rowCount, colCount);
    Sort(q, rowCount, colCount);
    cout << "Матриця після сортування:" << endl;
    Print(q, rowCount, colCount);

    int S = 0;
    int k = 0;

    Calc(q, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    cout << "Матриця після обчислень:" << endl;
    Print(q, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] q[i];
    delete[] q;
    return 0;
}

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            q[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** q, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << q[i][j];
        cout << endl;
    }
}

void Sort(int** q, const int rowCount, const int colCount) {
    auto cmp = [](const int* row1, const int* row2) {
        if (row1[0] != row2[0])
            return row1[0] < row2[0];
        else if (row1[0] % 2 != 0 && row2[0] % 2 != 0) // Якщо обидва непарні
            return row1[1] < row2[1];
        else if (row1[0] % 2 != 0) // Якщо перший непарний, а другий - парний
            return false;
        else if (row2[0] % 2 != 0) // Якщо перший парний, а другий - непарний
            return true;
        else // Якщо обидва парні
            return row1[2] > row2[2];
        };
    sort(q, q + rowCount, cmp);
}

void Change(int** q, const int row1, const int row2) {
    for (int j = 0; j < COLS; j++) {
        int tmp = q[row1][j];
        q[row1][j] = q[row2][j];
        q[row2][j] = tmp;
    }
}

void Calc(int** q, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (!(q[i][j] > 0 && q[i][j] % 2 == 0)) {
                S += q[i][j];
                k++;
            }
        }
    }
}
