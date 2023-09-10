#ifndef IO_FUNCS_HPP
#define IO_FUNCS_HPP

/**
 * @brief menu - Меню программы
 */
void menu();

/**
 * @brief printMatrix - Вывод матрицы
 * 
 * @param matrix - Матрица
 * @param rows - Количество строк матрицы
 * @param columns - Количество столбцов матрицы
 */
void printMatrix(const int **matrix, const std::size_t rows, const std::size_t columns);

#endif // IO_FUNCS_HPP