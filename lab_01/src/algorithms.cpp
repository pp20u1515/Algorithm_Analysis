#include <algorithms.hpp>
#include <return_codes.hpp>
#include <io_funcs.hpp>
#include <time.h>
#include <cstdio>
#include <dlfcn.h>

#define EQUAL 0
#define NOT_EQUAL 1
#define ARR_LEN 4 // количество сравнения

void initMatrix(std::vector<std::vector<int>> &matrix, const std::size_t &rows, const std::size_t &columns)
{
    // инициализируем первый столбец матрицы
    for (std::size_t index = 0; index < rows; index++)
        matrix[index][0] = index;

    // инициализируем первую строку матрицы
    for (std::size_t index = 0; index < columns; index++)
        matrix[0][index] = index;    
}

int normalLevenAlgorithm(const std::wstring &firstWord, const std::wstring &secondWord, bool key)
{
    std::size_t firstLength = firstWord.length(); // длина первого слова
    std::size_t secondLength = secondWord.length(); // длина второго слова
    int answer = 0; // результат(количество шагов)
    int change = 0; // штраф
    
    std::vector<std::vector<int>> matrix(firstLength + 1, std::vector<int>(secondLength + 1, 0));
    
    initMatrix(matrix, firstLength + 1, secondLength + 1);

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
        printMatrix(matrix, firstLength + 1, secondLength + 1);

    answer = matrix[firstLength][secondLength];     

    return answer;
}

int checkEquality(const char &firstLetter, const char &secondLetter)
{
    int rc = NOT_EQUAL;
    
    if (firstLetter == secondLetter)
        rc = EQUAL;

    return rc;
}

int normalDamerauLevenAlgorithm(const std::wstring &firstWord, const std::wstring &secondWord, bool key)
{
    std::size_t firstLength = firstWord.length(); // длина первого слова
    std::size_t secondLength = secondWord.length(); // длина второго слова
    int answer = 0; // результат(количество шагов)
    int change = 0; // штраф
    
    std::vector<std::vector<int>> matrix(firstLength + 1, std::vector<int>(secondLength + 1, 0));
    
    initMatrix(matrix, firstLength + 1, secondLength + 1);

    // заполняем матрицу
    for (std::size_t indexI = 1; indexI < firstLength + 1; indexI++)
        for (std::size_t indexJ = 1; indexJ < secondLength + 1; indexJ++)
        {
            change = checkEquality(firstWord[indexI - 1], secondWord[indexJ - 1]);

            matrix[indexI][indexJ] = std::min(matrix[indexI][indexJ - 1] + 1,
                                    std::min(matrix[indexI - 1][indexJ] + 1,
                                    matrix[indexI - 1][indexJ - 1] + change));

            if (indexI > 1 && indexJ > 1 && firstWord[indexI - 1] == secondWord[indexJ - 2] &&
                firstWord[indexI - 2] == secondWord[indexJ - 1])
                matrix[indexI][indexJ] = std::min(matrix[indexI][indexJ], matrix[indexI - 2][indexJ - 2] + 1);                        
        }

    if (key)
        printMatrix(matrix, firstLength + 1, secondLength + 1);

    answer = matrix[firstLength][secondLength];

    return answer;
}

int recursiveDamerauLevenAlgorithm(const std::wstring firstWord, const std::wstring secondWord)
{
    std::size_t firstLength = firstWord.length(); // длина первого слова
    std::size_t secondLength = secondWord.length(); // длина второго слова
    
    return recursiveDamerauLeven(firstWord, secondWord, firstLength, secondLength);
}

int recursiveDamerauLeven(const std::wstring firstWord, const std::wstring secondWord,
                        std::size_t firstLenght, std::size_t secondLength)
{
    int rc = OK;

    if (firstLenght == 0)
    	rc = secondLength;
    else if (secondLength == 0)
        rc = firstLenght;
    else
    {
        int change = checkEquality(firstWord[firstLenght - 1], secondWord[secondLength - 1]);

        int insert = recursiveDamerauLeven(firstWord, secondWord, firstLenght, secondLength - 1) + 1;
        int del = recursiveDamerauLeven(firstWord, secondWord, firstLenght - 1, secondLength) + 1;
        int replace = recursiveDamerauLeven(firstWord, secondWord, firstLenght - 1, secondLength - 1) + change;

        rc = std::min(std::min(insert, del), replace);

        if (firstLenght > 1 && secondLength > 1 && firstWord[firstLenght - 1] == secondWord[secondLength - 2] &&
            firstWord[firstLenght - 2] == secondWord[secondLength - 1])
        {
            int transposition = recursiveDamerauLeven(firstWord, secondWord, firstLenght - 2, secondLength - 2) + 1;
            rc = std::min(rc, transposition);
        }
    }

    return rc;
}

int recursiveDamerauLevenCache(const std::wstring firstWord, const std::wstring secondWord, bool key)
{
    std::size_t firstLength = firstWord.length(); // длина первого слова
    std::size_t secondLength = secondWord.length(); // длина второго слова
    int answer = 0; // результат(количество шагов)
    
    std::vector<std::vector<int>> matrix(firstLength + 1, std::vector<int>(secondLength + 1, -1));

    answer = cacheDamerauLeven(matrix, firstWord, secondWord, firstLength, secondLength);

    if (key)
        printMatrix(matrix, firstLength + 1, secondLength + 1);

    return answer;
}

int cacheDamerauLeven(std::vector<std::vector<int>> &matrix, const std::wstring firstWord, const std::wstring secondWord,
                        const std::size_t &firstLenght, const std::size_t &secondLength)
{
    if (firstLenght != 0)
    {
        if (secondLength != 0)
        {
            int change = checkEquality(firstWord[firstLenght - 1], secondWord[secondLength - 1]);

            matrix[firstLenght][secondLength] = std::min(cacheDamerauLeven(matrix, 
            firstWord, secondWord, firstLenght, secondLength - 1) + 1,
            std::min(cacheDamerauLeven(matrix, firstWord, secondWord, firstLenght - 1, secondLength) + 1,
            cacheDamerauLeven(matrix, firstWord, secondWord, firstLenght - 1, secondLength - 1) + change));

            if (firstLenght > 1 && secondLength > 1 && firstWord[firstLenght - 1] == secondWord[secondLength - 2] &&
                firstWord[firstLenght - 2] == secondWord[secondLength - 1])
                matrix[firstLenght][secondLength] = std::min(matrix[firstLenght][secondLength], 
                            cacheDamerauLeven(matrix, firstWord, secondWord, firstLenght - 2, secondLength - 2) + 1);
        }
        else
            matrix[firstLenght][secondLength] = firstLenght;
    }
    else
        matrix[firstLenght][secondLength] = secondLength;

    return matrix[firstLenght][secondLength];
}

void callCompareAlgorithms(const std::wstring &firstWord, const std::wstring &secondWord)
{
    std::cout << "\n\nСкорость работы алгоритмов измеряется в секундах, память в байтах." << std::endl << std::endl;

    compare(firstWord, secondWord);
}

void compare(const std::wstring firstString, const std::wstring secondString)
{
    clock_t start, end;
    double arrTime = 0.0;

    start = clock();
    normalLevenAlgorithm(firstString, secondString, 0);
    end = clock();
    arrTime = (end - start) / (CLOCKS_PER_SEC * 1000.0);
    printf("Нерекурсивный алгоритм поиска расстояния Левенштейна = %.10f сек.\n", arrTime);
    printf("Размер нерекурсивного алгоритма поиска расстояния Левенштейна = %zu байт.\n\n", getSizeLev(firstString.length()));
    
    start = clock();
    normalDamerauLevenAlgorithm(firstString, secondString, 0);
    end = clock();
    arrTime = (end - start) / (CLOCKS_PER_SEC * 1000.0);
    printf("Нерекурсивный алгоритм поиска расстояния Дамерау-Левенштейн = %.10f сек.\n", arrTime);
    printf("Размер нерекурсивного алгоритма поиска расстояния Дамерау-Левенштейна = %zu байт.\n\n", getSizeDamLev(firstString.length()));

    if (firstString.length() > 12 || secondString.length() > 12)
    {
        printf("Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна = -\n");
        printf("Размер рекурсивного алгоритма поиска расстояния Дамерау-Левенштейна без кэша = %zu байт.\n\n", getSizeDamLevRec(firstString.length()));
    }
    else
    {
        start = clock();
        recursiveDamerauLevenAlgorithm(firstString, secondString);
        end = clock();
        arrTime = (end - start) / (CLOCKS_PER_SEC * 1000.0);
        printf("Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна без кэша = %.10f сек.\n", arrTime);
        printf("Размер рекурсивного алгоритма поиска расстояния Дамерау-Левенштейна без кэша = %zu байт.\n\n", getSizeDamLevRec(firstString.length()));
    }
    
    start = clock();
    recursiveDamerauLevenCache(firstString, secondString, 0);
    end = clock();
    arrTime = (end - start) / (CLOCKS_PER_SEC * 1000.0);
    printf("Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна с кэшом = %.10f сек.\n", arrTime);
    printf("Размер рекурсивного алгоритма поиска расстояния Дамерау-Левенштейна с кэшом = %zu байт.\n\n", getSizeDamLevCache(firstString.length()));
}

std::size_t getSizeLev(const std::size_t &length)
{
    return (length + 1) * (length + 1) * sizeof(int) +
            2 * sizeof(std::wstring) + 2 * sizeof(std::size_t) +
            2 * sizeof(int) + sizeof(std::vector<std::vector<int>>) + (length + 1) * sizeof(std::vector<int>);
}

std::size_t getSizeDamLev(const std::size_t &length)
{
    return (length + 1) * (length + 1) * sizeof(int) +
            2 * sizeof(std::wstring) + 2 * sizeof(std::size_t) +
            3 * sizeof(int) + sizeof(std::vector<std::vector<int>>) + (length + 1) * sizeof(std::vector<int>);
}

std::size_t getSizeDamLevRec(const std::size_t &length)
{
    return (length + length) * (2 * sizeof(std::size_t) + 3 * sizeof(int) + 2 * sizeof(std::wstring));
}

std::size_t getSizeDamLevCache(const std::size_t &length)
{
    return getSizeDamLevRec(length) + (length + 1) * (length + 1) * sizeof(int) +
            sizeof(std::vector<std::vector<int>>) + (length + 1) * sizeof(std::vector<int>);
}
