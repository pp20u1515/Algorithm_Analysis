#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

/**
 * @brief menu - Меню 
 */
void menu();

/**
 * @brief input_num - Ввод элемента массива, который необходимо найти
 * 
 * @param target элемента массива, который необходимо найти
 */
void input_num(int &target);

/**
 * @brief input_elems - Ввод элемента в массив 
 * 
 * @param array Массив
 * @param size Размер массива
 */
void input_elems(vector<int> &array, const size_t &size);

/**
 * @brief fill_array - Функция, которая заполняет массив элементами 
 * 
 * @param array Массив
 */
void fill_array(vector<int> &array);

/**
 * @brief print_result - Вывод результата 
 * 
 * @param result Индекс элемента массива
 * @param target Элемент, который нужно найти в массиве
 * @param start Начальное время измерения скорость работы алгоритма поиска элемента в массиве
 * @param finish Конечное время измерения скорость работы алгоритма поиска элемента в массиве
 */
void print_result(const int &result, const int &target, const time_t &start, const time_t &finish);

/**
 * @brief generate_unique_array - Функция, которая автоматически заполняет массив элементами, которые уникальны
 * 
 * @param array Массив
 * @param size Размер массива
 */
void generate_unique_array(vector<int>& array, const size_t& size);

#endif // IO_FUNCS_H