#include <iostream>
#include <string>
#include <locale>

#include <io_funcs.hpp>
#include <return_codes.hpp>
#include <algorithms.hpp>

#define MAX_LEN_ANSWER 3
#define FIRST_WORD "первое"
#define SECOND_WORD "второе"

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8"); // set the locale to Russian UTF-8

    std::wstring firstWord, secondWord;
    std::wstring answerChar;
    int choice = -1;
    int rc = OK;
    
    std::cout << std::endl;
    
    firstWord = inputWord(FIRST_WORD);
    secondWord = inputWord(SECOND_WORD);

    while (choice != 0)
    {
        menu();
        
        std::cout << "\tВыберите действие: ";
        std::wcin >> answerChar;
        choice = std::stoi(answerChar);

        while (!choice)
        {
            if (answerChar == L"0")
                break;

            std::cout << "\tНеправильный ввод!" << std::endl;
            std::cout << "\tВыберите действие!" << std::endl;
            std::wcin >> answerChar;
            choice = std::stoi(answerChar);
        }
        switch (choice)
        {
            case (0):
                std::cout << "\tПрограмма завершена!" << std::endl;
                return OK;
            case (1):
                rc = normalLevenAlgorithm(firstWord, secondWord, 1);
                std::cout << "Нерекурсивный алгоритм поиска расстояния Левенштейна: " << rc << std::endl;
                rc = OK;
                break;    
            case (2):
                rc = normalDamerauLevenAlgorithm(firstWord, secondWord, 1);
                std::cout << "Нерекурсивный алгоритм поиска расстояния Дамерау-Левенштейна: " << rc << std::endl;
                rc = OK;
                break;  
            case (3):
                rc = recursiveDamerauLevenAlgorithm(firstWord, secondWord);
                std::cout << "Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна без кэша: " << rc << std::endl;
                rc = OK;
                break; 
            case (4):
                rc = recursiveDamerauLevenCache(firstWord, secondWord, 1);
                std::cout << "Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна с кэшом: " << rc << std::endl;
                rc = OK;
                break; 
            case (5):
                callCompareAlgorithms(firstWord, secondWord);
                rc = OK;
                break;    
            default:
                std::cout << "Ошибка: Неправильный ввод!" << std::endl;
                break;
        }
    }

    return rc;
}