#include "return_codes.h"
#include "io_funcs.h"
#include "algorithms.h"

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    vector<string> dictionary = {"hello", "world", "spell", "check", "algorithm", "troller", "somewhere", "stupid", "crazy"};
    string input_text = "holla wrld, speel chec somewher, troler stup crzy";
    string answerChar;
    size_t threads = 0;
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
            {
                input_num_threads(threads);
                time_t start = clock();
                multi_thread(input_text, dictionary, threads, true);
                time_t finish = clock();
                printf("Скорость: %.8f сек.\n", (finish - start) / (CLOCKS_PER_SEC * 100.0));
                rc = OK;
                break; 
            }   
            case (2):
            {
            	input_num_threads(threads);
                time_t start = clock();
                multi_thread(input_text, dictionary, threads, false);
                time_t finish = clock();
                printf("Скорость: %.8f сек.\n", (finish - start) / (CLOCKS_PER_SEC * 100.0));
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
