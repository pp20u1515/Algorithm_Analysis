#include "io_funcs.h"
#include "return_codes.h"

#include <limits>
#include <algorithm>

void menu()
{
    cout << ("\t\t\tМеню") << endl;
    cout << ("1) Стандартный алгоритм поиска элемента в массиве.") << endl;
    cout << ("2) Алгоритм бинарного поиска элемента в массиве.") << endl;
    cout << ("3) Сравнить оба алгоритма.") << endl;
}

void input_num(int &target)
{
    int rc = INPUT_ERROR;
    cout << "Введите элемент, который хотите найти в массиве: ";
    
    while (rc != OK)
    {
    	cin >> target;
    	
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
}

void input_elems(vector<int> &array, const size_t &size)
{
    cout << "Введите элементы массива: ";

    for (size_t index = 0; index < size; index++)
    {
        while (true)
        {
            int element = 0;
            cin >> element;

            if (cin.fail()) {
                cout << "Ошибка ввода. Пожалуйста, введите целое число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                array.push_back(element);
                break;
            }
        }
    }
}

void fill_array(vector<int> &array)
{
    int rc = INPUT_ERROR;
    size_t size = 0;

    cout << "Введите количество элементов массива: ";

    while (rc != OK)
    {
    	cin >> size;
    	
    	if (cin && size)
        {
            input_elems(array, size);
    	    rc = OK;
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

void print_result(const int &result, const int &target, const time_t &start, const time_t &finish)
{
    if (result >= 0)
        cout << "Элемент " << target << " был найден в массиве под индексом " << result << endl;
    else
        cout << "Элемент не был найден." <<endl;
    
    printf("Время поиска: %.8f сек.\n", (finish - start) / (CLOCKS_PER_SEC * 100.0));
}

void generate_unique_array(vector<int>& array, const size_t& size) 
{
    srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел

    for (size_t index = 0; index < size; ++index) 
    {
        int element;
        
        do {
            element = rand() % (size * 10) + 1; // Генерация числа от 1 до size * 10
        } while (find(array.begin(), array.end(), element) != array.end()); // Проверка уникальности числа

        array.push_back(element);
    }
}
