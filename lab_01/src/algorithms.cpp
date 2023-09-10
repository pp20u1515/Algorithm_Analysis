#include <algorithms.hpp>
#include <return_codes.hpp>
#include <dynamMatrix.hpp>
#include <io_funcs.hpp>

#include <iostream>
#include <cstring>

#define TRUE 1
#define FALSE 0

int normalLevenAlgorithm(const char *firstWord, const char *secondWord, bool key)
{
    size_t firstLength = strlen(firstWord);
    size_t secondLength = strlen(secondWord);
    int answer = 0;

    int **matrix = allocateMatrix(firstLength + 1, secondLength + 1);

    if (matrix)
    {
        for (std::size_t indexI = 0; indexI < firstLength; indexI++)
            matrix[indexI][0] = indexI;

        for (std::size_t indexI = 0; indexI < secondLength; indexI++)
            matrix[0][indexI] = indexI;

        int insertion = 0, deletion = 0, replacement = 0;

        for (std::size_t indexI = 1; indexI < firstLength + 1; indexI++)
            for (std::size_t indexJ = 1; indexJ < secondLength + 1; indexJ++)
                if (firstWord[indexI - 1] == secondWord[indexJ - 1])
                    matrix[indexI][indexJ] = matrix[indexI - 1][indexJ - 1];
                else
                {
                    insertion = matrix[indexI][indexJ - 1];
                    deletion = matrix[indexI - 1][indexJ];
                    replacement = matrix[indexI - 1][indexJ - 1];

                    matrix[indexI][indexJ] = 1 + findMin(insertion, deletion, replacement);
                }

        if (key)
            printMatrix(matrix, firstLength, secondLength);

        answer = matrix[firstLength][secondLength];

        freeMatrix(matrix, firstLength);        
    }
    return answer;
}

int findMin(const int x, const int y, const int z)
{
    int answer = 0;

    if (x <= y && x <= z)
        answer = x;
    else if (y <= x && y <= z)
        answer = y;
    else
        answer = z;

    return answer;
}