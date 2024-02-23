#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief mulMatrices - Стандартный алгоритм умножения матриц
 * 
 * @param firstMatrix Первая матрица
 * @param secondMatrix Вторая матрица
 * @return Результирующая матрица
 */
vector<vector<int>> mulMatrices(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix);

/**
 * @brief optVinogradAlg - Оптимизированный алгоритм Винограда умножения матриц
 * 
 * @param firstMatrix Первая матрица
 * @param secondMatrix Вторая матрица
 * @return Результирующая матрица 
 */
vector<vector<int>> optVinogradAlg(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix);

/**
 * @brief mulVinogradAlg - Алгоритм Винограда умножения матриц
 * 
 * @param firstMatrix Первая матрица
 * @param secondMatrix Вторая матрица
 * @return Результирующая матрица 
 */
vector<vector<int>> mulVinogradAlg(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix);

/**
 * @brief compareAlgorithms - Функция, которая сравнивает процессорное время и память каждого
 * реализованного алгоритма
 * 
 * @param firstMatrix Первая матрица
 * @param secondMatrix Вторая матрица
 */
void compareAlgorithms(vector<vector<int>> &firstMatrix, vector<vector<int>> &secondMatrix);

/**
 * @brief callCompareAlg - Функция, которая готовит реализованные алгоритм к сравнению и вызывает функцию compareAlgorithms
 * 
 */
void callCompareAlg();

/**
 * @brief strassenMultiply - Алгоритм Штрассена умножения матриц
 * 
 * @param A Первая матрица
 * @param B Вторая матрица
 * @return Результирующая матрица 
 */
std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>>& B);

#endif // ALGORITHMS_H