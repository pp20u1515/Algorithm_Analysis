#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief run_brute_force_alg - Функция, вызывающая алгоритм полного перебора
 */
void run_brute_force_alg();

/**
 * @brief brute_force_alg - Алгоритм полного перебора
 * 
 * @param matrix Матрица
 * @param n Количество вершин
 * @return Минимальная сумма пути и путь 
 */
pair<int, vector<int>> brute_force_alg(const std::vector<std::vector<int>> &matrix, const unsigned int &amount_node);

/**
 * @brief ant_algorithm - Функция для запуска муравьиного алгоритма
 * 
 * @param distances 
 * @param numAnts 
 * @param numIterations 
 * @return vector<int> 
 */
pair<double, vector<int>> ant_algorithm(const vector<vector<int>> &matrix, int places, 
                                                 double alpha, double beta, double k_evaporation, int days);

/**
 * @brief run_ant_algorithm - Функция для запуска муравьиного алгоритма
 */
void run_ant_algorithm();

void compare_algorithms();

class AntAlgorithm {
public:
    AntAlgorithm(double a, double b, double rho, int days, double elite = 0) : a(a), b(b), rho(rho), days(days), Q(0) {}

    pair<double, vector<int>> fit(const vector<vector<int>> &matrix, const int &ants);

private:
    double a;
    double b;
    double rho;
    int days;
    double Q;

    double calcQ(const vector<vector<int>> &matrix);
    int chooseNextLoc(const vector<double> &P);
    double calcLen(const vector<vector<int>> &matrix, const vector<int> &ant_route);
};

#endif // ALGORITHMS_H