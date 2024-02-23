#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "struct.h"

#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief merge_sort - Сортировка слиянием
 * 
 * @param array Исходный массив
 * @param start Начало массива
 * @param end Конец массива
 * @return Отсортированный массив
 */
void merge_sort(vector<int> &array, size_t start, size_t end);

/**
 * @brief merge - Функция, которая выполняет слияние двух отсортированных подмассивов в один
 * отсортированный массисв
 * 
 * @param array Массив
 * @param start Начало индекс элемента массива
 * @param middle Средный индекс элемента массива
 * @param end Конечный индекс элемента массива
 */
void merge(vector<int> &array, size_t start, size_t middle, size_t end);

/**
 * @brief insert - Вставка нового узла в дерево
 * 
 * @param root Корень дерева
 * @param data Элемент для добавления в дерево
 * @return Дерево с новым узлом
 */
node_t *insert(node_t *root, int data);

/**
 * @brief inorder_traversal - Функция, которая рекурсивно обходит дерева для сортированного вывода
 * 
 * @param root Структура дерева
 * @param array Результирующий массив
 */
void inorder_traversal(node_t *root, vector<int> &array);

/**
 * @brief bin_tree_sort - Сортировка с изпользованием бинарного дерева
 * 
 * @param array Массив
 * @return Результирующий массив 
 */
vector<int> bin_tree_sort(vector<int> &array);

/**
 * @brief coctail_sort - Сортировка расчеткой
 * 
 * @param array Массив
 */
void coctail_sort(vector<int> &array);

/**
 * @brief call_compare_alg - Функция, которая готовить данные к сравнению и вызывает функцию compare_alg
 *
 */
void call_compare_alg();

/**
 * @brief compare_alg - Функция, которая сравнивает алгоритмы сортировок
 *
 * @param аrr1 Первый массив
 * @param аrr1 Второй массив
 * @param аrr1 Третий массив
 */
void compare_alg(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3);

#endif // ALGORITHMS_H
