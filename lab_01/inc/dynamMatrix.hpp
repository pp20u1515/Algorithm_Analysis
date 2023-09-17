#ifndef DYNAM_MATRIX_H
#define DYNAM_MATRIX_H

#include <iostream>

/**
 * @brief allocateMatrix - Динамическое выделение памяти матрицы
 * 
 * @param rows Количество строк матрицы
 * @param columns Количество столбцов матрицы 
 * @return Выделенную матрицу
 */
int **allocateMatrix(const std::size_t rows, const std::size_t columns);

/**
 * @brief freeMatrix - Освобождение память матрицы
 * 
 * @param matrix Динамическая матрица
 * @param rows Количество строк матрицы
 */
void freeMatrix(int **matrix, const std::size_t rows);

#endif // DYNAM_MATRIX_H