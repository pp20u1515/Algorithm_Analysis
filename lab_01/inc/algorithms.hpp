#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include <iostream>
#include <vector>

/**
 * @brief normalLevenAlgorithm - Нерекурсивный алгоритм поиска расстояния Левенштейна 
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @param key Ключ
 * @return Количество шагов
 */
int normalLevenAlgorithm(const std::wstring &firstWord, const std::wstring &secondWord, bool key);

/**
 * @brief initMatrix - Функция, которая инициализирует первый столбец и первую строку матрицы
 * 
 * @param matrix Матрица
 * @param firstLength Количество строк матрицы
 * @param secondLength Количество столбцов матрицы
 */
void initMatrix(std::vector<std::vector<int>> &matrix, const std::size_t &rows, const std::size_t &columns);

/**
 * @brief checkEquality - Функция, которая проверяет равны ли две буквы
 * 
 * @param firstLetter Первая буква
 * @param secondLetter Вторая буква
 * @return True/False
 */
int checkEquality(const char &firstLetter, const char &secondLetter);

/**
 * @brief normalDamerauLevenAlgorithm - Обычный алгоритм поиска расстояния Дамерау-Левеншейна 
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @param key Ключ/флаг(вывести результат или проигнорировать)
 * @return Количество шагов
 */
int normalDamerauLevenAlgorithm(const std::wstring &firstWord, const std::wstring &secondWord, bool key);

/**
 * @brief recursiveDamerauLeven - Вспомагательная функция, которая рекурсивно находит расстояние 
 * Дамерау-Левенштейна без кэша
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @param firstLenght Длина первого слова
 * @param secondLength Длина второго слова
 * @return Количество шагов
 */
int recursiveDamerauLeven(const std::wstring firstWord, const std::wstring secondWord,
                        std::size_t firstLenght, std::size_t secondLength);

/**
 * @brief recursiveDamerauLevenAlgorithm - Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна без кэша
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @return Количество шагов
 */
int recursiveDamerauLevenAlgorithm(const std::wstring firstWord, const std::wstring secondWord);

/**
 * @brief recursiveDamerauLevenCache - Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна с кэшом
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @param key Ключ/флаг(вывести результат или проигнорировать)
 * @return Количество шагов
 */
int recursiveDamerauLevenCache(const std::wstring firstWord, const std::wstring secondWord, bool key);

/**
 * @brief cacheDamerauLeven - Вспомагательная функция, которая рекурсивно находит расстояние 
 * Дамерау-Левенштейна с кэшом
 * 
 * @param matrix Матрица
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @param firstLenght Длина первого слова
 * @param secondLength Длина второго слова
 * @return Количество шагов
 */
int cacheDamerauLeven(std::vector<std::vector<int>> &matrix, const std::wstring firstWord, const std::wstring secondWord,
                        const std::size_t &firstLenght, const std::size_t &secondLength);

/**
 * @brief callCompareAlgorithms - Функция, которая вызывает функцию compare, которая 
 * сравнивает процессорное время алгоритмов
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 */
void callCompareAlgorithms(const std::wstring &firstWord, const std::wstring &secondWord);   

/**
 * @brief compare - Вспомагательная функция, которая измеряет скорость работы программы в секундах, 
 * и память в байтах 
 * 
 * @param firstString Первое слово  
 * @param secondString Второе слово
 */
void compare(const std::wstring firstString, const std::wstring secondString);

std::size_t getSizeLev(const std::size_t &length);

std::size_t getSizeDamLev(const std::size_t &length);

std::size_t getSizeDamLevRec(const std::size_t &length);

std::size_t getSizeDamLevCache(const std::size_t &length);

#endif // ALGORITHMS_H
