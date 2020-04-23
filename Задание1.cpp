// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Matrix3x3.h"
#include <iostream>
#include <time.h>
#include "MatrixXnX.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix3x3 matr;
    matr.setElement(0, 2, 4);
    matr.fillRandomElements(-10, 10);
    cout << "Статическая матрица: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matr.element(i, j) << " ";
        cout << endl;
    }
    cout << "Суммы элементов диагоналей:" << endl;
    cout << " Главная: " << matr.sumPrincipalDiag() << " Побочная: " << matr.sumSecondaryDiag() << endl;
    cout << "Произведения элементов диагоналей:" << endl;
    cout << " Главная: " << matr.productPrincipalDiag() << " Побочная: " << matr.productSecondaryDiag() << endl;
    cout << "Суммы элементов строк:" << endl;
    for (int i = 0; i < 3; i++)
        cout << i+1 << ": " << matr.sumRow(i)<< endl;
    cout << "Максимальные элементы столбцов:" << endl;
    for (int j = 0; j < 3; j++)
        cout << j+1 << ": " << matr.maxColumn(j) << endl;
    cout << "Минимальные элементы столбцов:" << endl;
    for (int j = 0; j < 3; j++)
        cout << j+1 << ": " << matr.minColumn(j) << endl;
    cout << endl << endl;
    MatrixXnX matrix = MatrixXnX(4);
    matrix.fillRandomElements(-10,10);
    cout << "Динамическая матрица: " << endl;
    for (int i = 0; i < matrix.dim; i++)
    {
        for (int j = 0; j < matrix.dim; j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }
    cout << "Суммы элементов диагоналей:" << endl;
    cout << " Главная: " << matrix.sumPrincipalDiag() << " Побочная: " << matrix.sumSecondaryDiag() << endl;
    cout << "Произведения элементов диагоналей:" << endl;
    cout << " Главная: " << matrix.productPrincipalDiag() << " Побочная: " << matrix.productSecondaryDiag() << endl;
    cout << "Суммы элементов строк:" << endl;
    for (int i = 0; i < matrix.dim; i++)
        cout << i+1 << ": " << matrix.sumRow(i) << endl;
    cout << "Максимальные элементы столбцов:" << endl;
    for (int j = 0; j < matrix.dim; j++)
        cout << j+1 << ": " << matrix.maxColumn(j) << endl;
    cout << "Минимальные элементы столбцов:" << endl;
    for (int j = 0; j < matrix.dim; j++)
        cout << j+1 << ": " << matrix.minColumn(j) << endl;
    matrix.freeMemory();
}


