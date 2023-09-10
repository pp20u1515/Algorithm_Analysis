#include "io_funcs.hpp"
#include "struct.hpp"
#include "return_codes.hpp"

#include <iostream>

void menu()
{
    std::cout << "\t\t\tМеню" << std::endl;
    std::cout << "\t1) Нерекурсивный алгоритм поиска расстояния Левенштейна." << std::endl;
    std::cout << "\t2) Нерекурсивный алгоритм поиска расстояния Дамерау-Левенштейна." << std::endl;
    std::cout << "\t3) Рекурсивный алгоритм поиска расстояния \
                        Дамерау-Левенштейна без кэша." << std::endl;
    std::cout << "\t4) Рекурсивный алгоритм поиска расстояния \
                        Дамерау-Левенштейна с кэшом." << std::endl;
    std::cout << "\t5) Замерить память и время работы реализации алгоритмов \ 
                        поиска расстояния." << std::endl;  
    std::cout << "\t0) Завершить программу." << std::endl;                                             
}

void printMatrix(const int **matrix, const std::size_t rows, const std::size_t columns)
{
    for (std::size_t indexI = 0; indexI < rows; indexI++)
    {
        for (std::size_t indexJ = 0; indexJ < columns; indexJ++)
            std::cout << matrix[indexI][indexJ] << std::endl;

        std::cout << std::endl;    
    }
}