#include "io_funcs.h"
#include "algorithms.h"
#include "return_codes.h"

#define MAX_LEN_ANSWER 3

int main()
{
    vector<int> array1, array2, array3;
    string answerChar;
    int choice = -1;
    int rc = OK;

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
                choose_input(array1);
                cout << "Исходный массив: ";
                print_array(array1);
                merge_sort(array1, 0, array1.size() - 1);
                cout << "Отсортированный массив: "; 
                print_array(array1);
                rc = OK;
                break;    
            case (2):
                choose_input(array2);
                cout << "Исходный массив: ";
                print_array(array2);
                array2 = bin_tree_sort(array2);
                cout << "Отсортированный массив: "; 
                print_array(array2);
                rc = OK;
                break;  
            case (3):
                choose_input(array3);
                cout << "Исходный массив: ";
                print_array(array3);
                coctail_sort(array3);
                cout << "Отсортированный массив: "; 
                print_array(array3);
                rc = OK;
                break; 
            case (4):
            	call_compare_alg();
                rc = OK;
                break;       
            default:
                cout << "Ошибка: Неправильный ввод!" << endl;
                break;
        }
    }

    return rc;
}
