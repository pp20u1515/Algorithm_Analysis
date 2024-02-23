#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <iostream>
using namespace std;

/**
 * @brief menu() - Меню программы
 * 
 */
void menu();

void print_result(const string &input_text, const string &output_text);

void input_num_threads(size_t &threads);

#endif
