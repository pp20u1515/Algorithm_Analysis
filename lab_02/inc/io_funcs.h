#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief menu - Меню программы
 * 
 */
void menu();

/**
 * @brief callReadMatrices - Функция, которая заполняет несколько матриц
 * 
 * @param firstMatrix Первая матрица
 * @param secondMatrix Вторая матрица
 */
void callReadMatrices(vector<vector<int>> &firstMatrix, vector<vector<int>> &secondMatrix);

/**
 * @brief readMatrix - Функция, которая заполняет матрицу
 * 
 * @param matrix Матрица
 * @return Код успеха или код ошибки 
 */
int readMatrix(vector<vector<int>> &matrix);

/**
 * @brief inputMatrix - Функция, которая заполняет матрицу элементами
 * 
 * @param matrix Матрица
 * @param rows Количество строк
 * @param columns Количество столбцов
 * @return Код успеха или код ошибки 
 */
int inputMatrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns);

/**
 * @brief printMatrix - Вывод Матрицы
 * 
 * @param matrix Матрица
 * @param rows Количество строк
 * @param columns Количество столбцов
 */
void printMatrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns);

/**
 * @brief inputAutoMatrix - Функция, которая автоматически заполняет матрицу элементами
 * 
 * @param matrix Матрица
 * @param rows Количество строк
 * @param columns Количество столбцов
 */
void inputAutoMatrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns);

#endif // IO_FUNCS_H