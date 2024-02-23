#include "return_codes.h"
#include "io_funcs.h"

#include <cstdio>
#include <limits>
#include <random>

#define NOT_EQUAL 1

void menu()
{
    cout << "\t\t\tМеню" << endl;
    cout << "\t1) Сортировка слиянием." << endl;
    cout << "\t2) Сортировка бынарным деревом." << endl;
    cout << "\t3) Сортировка расчесткой." << endl;
    cout << "\t4) Провести анализ затрат работы алгоритмов по времени." << endl; 
    cout << "\t0) Завершить программу." << endl; 
}

vector<int> generate_array(const size_t &n)
{
    vector<int>array(n, 0);
    // инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(nullptr)));

    for (size_t index = 0; index < n; index++)
        array[index] = (rand() % 100);

    return array;
}

vector<int> gen_sorted_arr(const size_t &amount)
{
    vector<int> array(amount, 0);
    
    for (size_t index = 0; index < amount; index++)
        array[index] = index;
        
    return array;
}

vector<int> gen_unsorted_arr(const size_t &amount)
{
    vector<int> array(amount, 0);
    
    for (size_t index = 0, counter = amount; index < amount; index++, counter -= 1)
        array[index] = counter;
        
    return array;
}

vector<int> fill_manually_arr(const size_t &n)
{
    int rc = OK;
    vector<int>array(n, 0);

    do
    {
        for (size_t index = 0; rc == OK && index < n; index++)
            if (scanf("%d", &array[index]) != 1)
                rc = INPUT_ERROR;
    }
    while (rc != OK);

    return array;
}

void fill_array(vector<int> &array, const size_t &n, const size_t &key)
{
    if (key == 1)
        array = generate_array(n);
    else
        array = fill_manually_arr(n);
}

void choose_input(vector<int> &array)
{
    int rc = INPUT_ERROR; // код возврата
    size_t n = 0; // размер массива
    size_t choice = 0; // выбор

    while (rc != OK)
    {
        cout << "1) Сгенерировать массив." << endl;
        cout << "2) Ввести массив." << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        if (cin && choice > 0 && choice < 3)
        {
            cout << "Введите количество элементов массива: ";
            cin >> n;

            if (cin && n > 0)
            {
                fill_array(array, n, choice);
                rc = OK;
            }
            else
            {
                cout << "Неправильно ввели количество элементов массива!" << endl;
                rc = INPUT_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Неправильно выбрали действие!" << endl;
            rc = INPUT_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }   
}

void print_array(vector<int> &array)
{
    for (size_t index = 0; index < array.size(); index++)
        cout << array[index] << " ";
    cout << endl;    
}
