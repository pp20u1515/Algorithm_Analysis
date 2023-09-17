#include <algorithms.hpp>
#include <return_codes.hpp>
#include <dynamMatrix.hpp>
#include <io_funcs.hpp>

#define EQUAL 0
#define NOT_EQUAL 1

int normalLevenAlgorithm(std::string firstWord, std::string secondWord, bool key)
{
    std::size_t firstLength = firstWord.length(); // длина первого слова
    std::size_t secondLength = secondWord.length(); // длина второго слова
    int answer = 0; // результат(количество сравнений в алгоритме Левенштейна)
    int change = 0;

    int **matrix = allocateMatrix(firstLength + 1, secondLength + 1);

    if (matrix)
    {
        // инициализируем первый столбец матрицы
        for (std::size_t indexI = 0; indexI < firstLength; indexI++)
            matrix[indexI][0] = indexI;

        // инициализируем первую строку матрицы
        for (std::size_t indexI = 0; indexI < secondLength; indexI++)
            matrix[0][indexI] = indexI;

        // заполняем матрицу
        for (std::size_t indexI = 1; indexI < firstLength + 1; indexI++)
            for (std::size_t indexJ = 1; indexJ < secondLength + 1; indexJ++)
            {
                change = checkEquality(firstWord[indexI - 1], secondWord[indexJ - 1]);

                matrix[indexI][indexJ] = std::min(matrix[indexI][indexJ - 1] + 1,
                                        std::min(matrix[indexI - 1][indexJ] + 1,
                                        matrix[indexI - 1][indexJ - 1] + change));
            }

        if (key)
            printMatrix(matrix, firstLength, secondLength);

        answer = matrix[firstLength][secondLength];

        freeMatrix(matrix, firstLength + 1);        
    }

    return answer;
}

int checkEquality(const char firstLetter, const char secondLetter)
{
    int rc = NOT_EQUAL;

    if (firstLetter == secondLetter)
        rc = EQUAL;

    return rc;
}