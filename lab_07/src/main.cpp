#include "return_codes.h"
#include "io_funcs.h"
#include "algorithms.h"

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    vector<int> array; // массив
    int target = 0; // элемент, который нужно найти в массиве
    string answerChar; // действие выбора меню
    int choice = -1;
    int rc = OK; // код возврата

    while (choice != 0)
    {
        menu();
        while (true)
        {
            cout << "\tВыберите действие: ";
            cin >> answerChar;

            try
            {
                choice = stoi(answerChar);
                break; 
            }
            catch(const invalid_argument &e)
            {
                if (answerChar == "0")
                {
                    choice = 0;
                    break;
                }
            
            cout << "\tНеправильный ввод!" << endl;
            }
        }
        switch (choice)
        {
            case (0):
                std::cout << "\tПрограмма завершена!" << std::endl;
                return OK;
            case (1):
            {
                //fill_array(array);
                //input_num(target);
                generate_unique_array(array, 1027);
                target = array[0];
                time_t start = clock();
                int result = standard_search(array, target);
                time_t finish = clock();
                print_result(result, target, start, finish);
                rc = OK;
                break; 
            }   
            case (2):
            {
                //fill_array(array);
                //input_num(target);
                generate_unique_array(array, 1027 / 2);
                target = array[0];
                sort(array.begin(), array.end());
                time_t start = clock();
                int result = binary_search(array, target);
                time_t finish = clock();
                print_result(result, target, start, finish);
                rc = OK;
                break;   
            }   
            case (3):
            {
                compare_algorithms();
                rc = OK;
                break;
            }  
            default:
                cout << "Ошибка: Неправильный ввод!" << endl;
                break;
        }
    }
    return rc;        
}
