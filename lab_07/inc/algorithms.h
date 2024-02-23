#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief standard_search - Стандартный алгоритм поиска элемента в массиве 
 * 
 * @param arr Массив
 * @param target Элемент, который нужно найти
 * @return Индекс элемента массива
 */
int standard_search(const vector<int> &arr, const int target);

/**
 * @brief binary_search - Бинарный алгоритм поиска элемента в массиве 
 * 
 * @param arr Массив
 * @param target Элемент, который необходимо найти
 * @return Индекс элемента массива
 */
int binary_search(const vector<int>& arr, const int target);

/**
 * @brief Функция, которая сравнивает стандартный алгоритм и бинарный алгоритм поиска элемента в массиве
 */
void compare_algorithms();

#endif // ALGORITHMS_H