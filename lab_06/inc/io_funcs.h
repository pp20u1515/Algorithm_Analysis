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
 * @brief read_matrix - Функция, которая читает эелемнты матрицы из файла
 * 
 * @param matrix Матрица
 * @param amount_node Количество вершин
 * @param f_open Входной файл
 * @return Код успеха или код ошибки
 */
int read_matrix(vector<vector<int>> &matrix, const unsigned int &amount_node, ifstream &f_open);

/**
 * @brief 
 * 
 * @param result 
 */
void print_result(pair<int, vector<int>> &result);

/**
 * @brief 
 * 
 * @param b 
 * @param rho 
 * @return int 
 */
int input_extra_coefs(double &b, double &rho);

/**
 * @brief 
 * 
 * @param days 
 * @param a 
 * @param b 
 * @param rho 
 */
void input_coefs(int &days, double &a, double &b, double &rho);

#endif // IO_FUNCS_H