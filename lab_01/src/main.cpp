#include <iostream>
#include <cstring>
#include <string>

#include <struct.hpp>
#include <io_funcs.hpp>

#define MAX_LEN_ANSWER 3
#define WORD_LEN 20

int main()
{
    char firstWord[WORD_LEN], secondWord[WORD_LEN];
    int rc = OK;
    int choice = -1;
    char answerChar[MAX_LEN_ANSWER];

    while (choice != 0)
    {
        std::cout << "Введите первое слово: ";
        std::cin >> firstWord;
        std::cout << std::endl;
        std::cout << "Введите второе слово: ";
        std::cout << std::endl;

        menu();
        
        std::cout << "\tВыберите действие: ";
        std::cin >> answerChar;
        choice = std::atoi(answerChar);

        while (!choice)
        {
            if (std::strcmp(answerChar, "0") == 0)
                break;

            std::cout << "\tНеправильный ввод!" << std::endl;
            std::cout << "\tВыберите действие!" << std::endl;
            std::cin >> answerChar;
            choice = std::atoi(answerChar);
        }
        switch (choice)
        {
            case (0):
                std::cout << "\tПрограмма завершена!" << std::endl;
                return OK;
            case (1):
                break;    
        }
    }

    return rc;
}