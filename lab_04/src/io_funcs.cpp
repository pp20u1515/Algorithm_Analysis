#include "io_funcs.h"
#include "return_codes.h"

#include <limits>

void menu()
{
    cout << ("\t\t\tМеню") << endl;
    cout << ("1) Однопоточная реализация.") << endl;
    cout << ("2) Многопоточная реализация.") << endl;
}

void print_result(const string &input_text, const string &output_text)
{
    cout << "Входной текст: " << input_text << endl;
    cout << "Выходной текст: " << output_text << endl;
}

void input_num_threads(size_t &threads)
{
    int rc = INPUT_ERROR;
    cout << "Введите количество потоков: ";
    
    while (rc != OK)
    {
    	cin >> threads;
    	
    	if (cin && threads)
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
