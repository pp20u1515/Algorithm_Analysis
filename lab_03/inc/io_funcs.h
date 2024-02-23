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
 * @brief choice_input - Функция, которая помогает выбрать метод заполнения массива элементами
 * 
 * @param array Массив
 */
void choose_input(vector<int> &array);

/**
 * @brief fill_array - Вспомогательная функция для заполнения массива элементами
 * 
 * @param array Массив
 * @param n Количество элементов массива
 * @param key Ключ(Выбор действия)
 */
void fill_array(vector<int> &array, const size_t &n, const size_t &key);

/**
 * @brief fill_manually_arr - Функция, которая заполняет массив в ручную
 * 
 * @param n Количество элементов массива
 * @return Результирующий массив 
 */
vector<int> fill_manually_arr(const size_t &n);

/**
 * @brief generate_array - Функция, которая автоматически заполняет массив элементами
 * 
 * @param n Количество элементов массива
 * @return vector<int> 
 */
vector<int> generate_array(const size_t &n);

/**
 * @brief print_array - Функция, которая выводит массив на экран 
 * 
 * @param array Массив
 */
void print_array(vector<int> &array);

/**
 * @brief gen_sorted_arr - Функция, которая генерирует отсортированный массив
 * 
 * @param amount Количество элементов массива
 * @return Отсортированный массив
 */
vector<int> gen_sorted_arr(const size_t &amount);

/**
 * @brief gen_unsorted_arr - Функция, которая генерирует неотсортированный массив
 * 
 * @param amount Количество элементов массива
 * @return  Неотсортированный массив
 */
vector<int> gen_unsorted_arr(const size_t &amount);

#endif // IO_FUNCS_H