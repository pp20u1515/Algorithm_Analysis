#ifndef IO_FUNCS_HPP
#define IO_FUNCS_HPP

#include <string>
#include <iostream>
#include <vector>

/**
 * @brief menu - Меню программы
 */
void menu();

/**
 * @brief printMatrix - Вывод матрицы
 * 
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param columns Количество столбцов матрицы
 */
void printMatrix(const std::vector<std::vector<int>> &matrix, const std::size_t &rows, const std::size_t &columns);

/**
 * @brief inputWord - Ввод слова
 * 
 * @param chooseWord Счетчик
 * @return Слово 
 */
std::wstring inputWord(const std::string chooseWord);

#endif // IO_FUNCS_HPP