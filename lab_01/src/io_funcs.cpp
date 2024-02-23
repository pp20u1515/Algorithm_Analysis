#include "io_funcs.hpp"

#include <dlfcn.h>

void menu()
{
    std::cout << "\t\t\tМеню" << std::endl;
    std::cout << "\t1) Нерекурсивный алгоритм поиска расстояния Левенштейна." << std::endl;
    std::cout << "\t2) Нерекурсивный алгоритм поиска расстояния Дамерау-Левенштейна." << std::endl;
    std::cout << "\t3) Рекурсивный алгоритм поиска расстояния ";
    std::cout << "Дамерау-Левенштейна без кэша." << std::endl;
    std::cout << "\t4) Рекурсивный алгоритм поиска расстояния";
    std::cout << " Дамерау-Левенштейна с кэшом." << std::endl;
    std::cout << "\t5) Замерить память и время работы реализации алгоритмов";
    std::cout << " поиска расстояния." << std::endl;  
    std::cout << "\t0) Завершить программу." << std::endl;                                             
}

void printMatrix(const std::vector<std::vector<int>> &matrix, const std::size_t &rows, const std::size_t &columns)
{
    for (std::size_t indexI = 0; indexI < rows; indexI++)
    {
        for (std::size_t indexJ = 0; indexJ < columns; indexJ++)
            std::cout << matrix[indexI][indexJ] << " ";

        std::cout << std::endl;    
    }
}

std::wstring inputWord(const std::string chooseWord)
{
    std::wstring word;

    while (word.empty())
    {       
        std::cout << "\tВведите " << chooseWord << " слово: ";
        std::wcin >> word;
    }
    return word;
}
