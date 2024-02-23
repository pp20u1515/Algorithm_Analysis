#include "return_codes.h"
#include "io_funcs.h"

#include <cstdio>
#include <limits>
#include <random>

#define NOT_EQUAL 1

void menu()
{
    cout << "\t\t\tМеню" << endl;
    cout << "\t1) Классический алгоритм умножения матриц." << endl;
    cout << "\t2) Алгоритм Винограда." << endl;
    cout << "\t3) Оптимизированный алгоритм Винограда." << endl;
    cout << "\t4) Алгоритм Штрассена." << endl;
    cout << "\t5) Провести анализ затрат работы алгоритмов по времени и по памяти." << endl; 
    cout << "\t0) Завершить программу." << endl; 
}

int inputMatrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns)
{
    int rc = OK; // код возврата
    matrix.resize(rows);

    for (size_t indexI = 0; rc == OK && indexI < rows; indexI++)
    {
        matrix[indexI].resize(columns);
        for (size_t indexJ = 0; rc == OK && indexJ < columns; indexJ++)
            if (scanf("%d", &matrix[indexI][indexJ]) != 1)
                rc = INPUT_ERROR;
    }
    
    return rc;
}

int readMatrix(vector<vector<int>> &matrix)
{
    size_t rows = 0, columns = 0;
    int rc = OK;

    cout << "Введите количество строк матрицы: ";
    cin >> rows;
    if (cin && rows > 0)
    {
        cout << "Введите количество столбцов матрицы: ";
        cin >> columns;
        if (cin && columns > 0)
        {
            cout << "Введите элементы матрицы:" << endl;
            rc = inputMatrix(matrix, rows, columns);

            if (rc != OK)
            {
                cout << "Ошибка: Неправильно ввели элемент матрицы!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Ошибка: Неправильно ввели количество столбцов матрицы!" << endl;
            rc = INPUT_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    else
    {
        cout << "Ошибка: Неправильно ввели количество строк матрицы!" << endl;
        rc = INPUT_ERROR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return rc;
}

int checkDimensions(vector<vector<int>> &firstMatrix, vector<vector<int>> &secondMatrix)
{
    return (firstMatrix[0].size() == secondMatrix.size()) ? OK : NOT_EQUAL;         
}

void callReadMatrices(vector<vector<int>> &firstMatrix, vector<vector<int>> &secondMatrix)
{
    int rc = INPUT_ERROR;

    while (rc != OK)
    {    
        rc = readMatrix(firstMatrix);

        if (rc == OK)
        {
            rc = readMatrix(secondMatrix);

            if (rc == OK)
                rc = checkDimensions(firstMatrix, secondMatrix);
        }

    }
}

void printMatrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns)
{
    for (size_t indexI = 0; indexI < rows; indexI++)
    {
        for (size_t indexJ = 0; indexJ < columns; indexJ++)
            cout << matrix[indexI][indexJ] << " ";

        cout << endl;    
    }
}

void inputAutoMatrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns)
{
    matrix.resize(rows);

    for (size_t indexI = 0; indexI < rows; indexI++)
    {
        matrix[indexI].resize(columns);
        for (size_t indexJ = 0; indexJ < columns; indexJ++)
            matrix[indexI][indexJ] = 1 + (rand() % 100);
    }
}