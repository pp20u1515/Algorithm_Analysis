#include "io_funcs.h"
#include "return_codes.h"

#include <fstream>
#include <utility> // для std::pair
#include <algorithm> 
#include <limits>

void menu()
{
    cout << ("\t\t\tМеню") << endl;
    cout << ("1) Алгоритм полного перебора.") << endl;
    cout << ("2) Муравьиный алгоритм.") << endl;
    cout << ("3) Сравнить оба алгоритма.") << endl;
}

int read_matrix(vector<vector<int>> &matrix, const unsigned int &amount_node, ifstream &f_open)
{
    int rc = OK;

    matrix.resize(amount_node, vector<int>(amount_node));

    for (unsigned int i = 0; rc == OK && i < amount_node; i++)
        for (unsigned int j = 0; rc == OK && j < amount_node; j++)
            if (!(f_open >> matrix[i][j]))
                rc = READ_ERROR;

    return rc;
}

void print_result(pair<int, vector<int>> &result)
{
    cout << "Минимальная сумма пути: " << result.first << endl;
    cout << "Путь: ";
    for_each(result.second.begin(), result.second.end(), [](int city) { std::cout << city << " "; }); 
    cout << endl;
}

int input_extra_coefs(double &b, double &rho)
{
    int rc = INPUT_ERROR;
    cout << "Введите коэффициент влияния расстояния: ";

    while (rc != OK)
    {
        cin >> b;

        if (cin)
        {
            cout << "Введите коэффициент испарения феромона: ";
            cin >> rho;

            if (cin)
                rc = OK;
            else
            {
                cout << "Неверный ввод!" << endl;
                rc = INPUT_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Неверный ввод!" << endl;
    	    rc = INPUT_ERROR;
    	    cin.clear();
    	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return rc;
}

void input_coefs(int &days, double &a, double &b, double &rho)
{
    int rc = INPUT_ERROR;
    cout << "Введите количество дней: ";
    
    while (rc != OK)
    {
    	cin >> days;
    	
    	if (cin && days)
        {
            cout << "Введите коэффициент влияния феромона: ";
            cin >> a;

            if (cin)
                rc = input_extra_coefs(b, rho);
            else
            {
                cout << "Неверный ввод!" << endl;
                rc = INPUT_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    	else
    	{
    	    cout << "Неверный ввод!" << endl;
    	    rc = INPUT_ERROR;
    	    cin.clear();
    	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	}
    }
}
