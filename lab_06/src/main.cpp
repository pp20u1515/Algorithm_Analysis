#include "return_codes.h"
#include "io_funcs.h"
#include "algorithms.h"

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
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
                run_brute_force_alg();
                rc = OK;
                break; 
            }   
            case (2):
            {
                run_ant_algorithm();
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
