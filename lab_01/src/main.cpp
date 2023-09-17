#include <iostream>
#include <string>

#include <io_funcs.hpp>
#include <return_codes.hpp>
#include <algorithms.hpp>

#define MAX_LEN_ANSWER 3
#define FIRST_WORD "первое"
#define SECOND_WORD "второе"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string firstWord, secondWord;
    std::string answerChar;
    int choice = -1;
    int rc = OK;

    std::cout << std::endl;
    firstWord = inputWord(FIRST_WORD);
    secondWord = inputWord(SECOND_WORD);

    while (choice != 0)
    {
        menu();
        
        std::cout << "\tВыберите действие: ";
        std::cin >> answerChar;
        choice = std::stoi(answerChar);

        while (!choice)
        {
            if (answerChar == "0")
                break;

            std::cout << "\tНеправильный ввод!" << std::endl;
            std::cout << "\tВыберите действие!" << std::endl;
            std::cin >> answerChar;
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
            default:
                std::cout << "Ошибка: Неправильный ввод!" << std::endl;
                break;

        }
    }

    return rc;
}