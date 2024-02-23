#include "algorithms.h"
#include "io_funcs.h"
#include "return_codes.h"

#include <fstream>
#include <algorithm> 
#include <climits>
#include <limits>
#include <cmath>
#include <numeric>
#include <random>

const double MIN_PHER = 0.1; // Минимальное значение феромона

pair<int, vector<int>> brute_force_alg(const vector<vector<int>> &matrix, const unsigned int &amount_node) 
{
    // Создание списка всех перестановок городов
    vector<int> permutation(amount_node);
    for (unsigned int i = 0; i < amount_node; i++)
        permutation[i] = i;

    int best_dist = INT_MAX; // Начальное значение лучшего расстояния
    vector<int> best_route;

    // Перебор всех перестановок городов
    do 
    {
        int cur_dist = 0;
        // Вычисление расстояния текущего маршрута
        for (unsigned int i = 0; i < amount_node - 1; ++i)
            cur_dist += matrix[permutation[i]][permutation[i + 1]];

        // Обновляем лучший маршрут и расстояние, если текущее лучше
        if (cur_dist < best_dist) 
        {
            best_dist = cur_dist;
            best_route = permutation;
        }
    } while (next_permutation(permutation.begin(), permutation.end())); // Генерация всех перестановок

    return make_pair(best_dist, best_route); // Возвращаем лучшее расстояние
}

void run_brute_force_alg()
{
    unsigned int amount_node = 0;
    vector<vector<int>> matrix;
    int rc = OK;
    ifstream f_open("./data/text2.txt");

    if (f_open.is_open())
    {
        f_open >> amount_node;

        if (amount_node > 0)
        {
            rc = read_matrix(matrix, amount_node, f_open);

            if (rc == OK)
            {
                pair<int, vector<int>> result = brute_force_alg(matrix, amount_node);
                print_result(result);
            }
        }
        f_open.close();
    }
}

double AntAlgorithm::calcQ(const vector<vector<int>>& matrix) 
{
    double sum = 0.0;
    int count = 0;

    for (const auto& row : matrix)
        for (int dist : row)
            if (dist != 0) 
            {
                sum += dist;
                count++;
            }
    return sum / count;
}

int AntAlgorithm::chooseNextLoc(const vector<double> &P) 
{
    double posibility = static_cast<double>(rand()) / RAND_MAX;
    double cur_posibility = 0.0;
    int to = 0;

    while (cur_posibility < posibility && to < P.size()) 
    {
        cur_posibility += P[to];
        to++;
    }

    return to - 1;
}    

double AntAlgorithm::calcLen(const vector<vector<int>> &matrix, const vector<int> &ant_route) 
{
    double ant_dist = 0.0;

    for (size_t i = 0; i < ant_route.size() - 1; ++i) 
    {
        int city_from = ant_route[i];
        int city_to = ant_route[i + 1];
        ant_dist += matrix[city_from][city_to];
    }
    return ant_dist;
}

pair<double, vector<int>> AntAlgorithm::fit(const vector<vector<int>> &matrix, const int &ants) 
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int cities = matrix.size();
    vector<vector<double>> tao(cities, vector<double>(cities, 1.0)); // Феромон на пути между городами

    vector<vector<int>> ant_routes(ants, vector<int>(cities, 0)); // Маршруты муравьев
    vector<double> ant_dist(ants, 0.0); // Расстояния, пройденные муравьями

    vector<int> best_route; // Лучший маршрут
    double best_dist = numeric_limits<double>::infinity(); // Лучшее расстояние

    Q = calcQ(matrix);

    for (int day = 0; day < days; ++day) 
    {
        for (int ant = 0; ant < ants; ++ant) 
        {
            ant_routes[ant][0] = rand() % cities;

            for (int i = 1; i < cities; ++i) 
            {
                int from_city = ant_routes[ant][i - 1];

                vector<double> P(cities, 0.0); // Вероятности перехода в следующий город
                double sum_prob = 0.0;

                for (int j = 0; j < cities; ++j) 
                {
                    if (find(ant_routes[ant].begin(), ant_routes[ant].begin() + i, j) == ant_routes[ant].begin() + i) 
                    {
                        double pher = pow(tao[from_city][j], a);
                        double dist = pow(1.0 / matrix[from_city][j], b);
                        P[j] = pher * dist;
                        sum_prob += P[j];
                    }
                }

                for (int j = 0; j < cities; ++j)
                    P[j] /= sum_prob;

                int next_city = chooseNextLoc(P);
                ant_routes[ant][i] = next_city;
            }

            ant_dist[ant] = calcLen(matrix, ant_routes[ant]);

            if (ant_dist[ant] < best_dist) 
            {
                best_dist = ant_dist[ant];
                best_route = ant_routes[ant];
            }
        }

        // Обновление феромонов
        for (int ant = 0; ant < ants; ++ant) 
        {
            double delta_tao = Q / ant_dist[ant];

            for (int i = 0; i < cities - 1; ++i) 
            {
                int city_from = ant_routes[ant][i];
                int city_to = ant_routes[ant][i + 1];
                tao[city_from][city_to] += delta_tao;

                if (tao[city_from][city_to] < MIN_PHER) {
                    tao[city_from][city_to] = MIN_PHER;
                }
            }
        }

        // Испарение феромонов
        for (int i = 0; i < cities; ++i)
            for (int j = 0; j < cities; ++j)
                tao[i][j] *= (1.0 - rho);
    }

    return make_pair(best_dist, best_route);
}

void run_ant_algorithm()
{
    unsigned int amount_node = 0;
    vector<vector<int>> matrix;
    int days; // = 100; // Количество дней
    double a; // = 1.0; // Коэффициент влияния феромона
    double b; // = 2.0; // Коэффициент влияния расстояния
    double rho; //= 0.5; // Коэффициент испарения феромона
    int rc = OK;
    ifstream f_open("./data/text2.txt");
    
    if (f_open.is_open())
    {
        f_open >> amount_node;

        input_coefs(days, a, b, rho);

        if (amount_node > 0)
        {
            rc = read_matrix(matrix, amount_node, f_open);
            
            if (rc == OK)
            {
                AntAlgorithm ant_algo(a, b, rho, days);
                pair<int, vector<int>> result = ant_algo.fit(matrix, amount_node);
                print_result(result);
            }
        }
        f_open.close();
    }
}

vector<vector<int>> generateMatrix(const int &size) 
{
    vector<vector<int>> matrix(size, vector<int>(size));
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10); // Генерация чисел от 1 до 100
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = dist(gen);
        }
    }
    
    return matrix;
}

void compare_algorithms()
{
    int days = 100; // Количество дней
    double a = 5.0; // Коэффициент влияния феромона
    double b = 5.0; // Коэффициент влияния расстояния
    double rho = 1.0; // Коэффициент испарения феромона
    int rc = OK;
    time_t start, finish;
    pair<int, vector<int>> result;
    AntAlgorithm ant_algo(a, b, rho, days);
    vector<vector<int>> matrix = generateMatrix(2);

    start = clock();
    result = ant_algo.fit(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));

    start = clock();
    result = brute_force_alg(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));
    cout << endl;

    matrix = generateMatrix(4);

    start = clock();
    result = ant_algo.fit(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));

    start = clock();
    result = brute_force_alg(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));
    cout << endl;

    matrix = generateMatrix(6);

    start = clock();
    result = ant_algo.fit(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));

    start = clock();
    result = brute_force_alg(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));
    cout << endl;

    matrix = generateMatrix(9);

    start = clock();
    result = ant_algo.fit(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));

    start = clock();
    result = brute_force_alg(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));
    cout << endl;

    matrix = generateMatrix(10);

    start = clock();
    result = ant_algo.fit(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));

    start = clock();
    result = brute_force_alg(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));
    cout << endl;

    matrix = generateMatrix(11);

    start = clock();
    result = ant_algo.fit(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));

    start = clock();
    result = brute_force_alg(matrix, matrix.size());
    finish = clock();
    printf("Скорость: %.8f\n", (finish - start) / (CLOCKS_PER_SEC * 1.0));
    cout << endl;
}