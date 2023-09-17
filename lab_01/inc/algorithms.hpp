#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include <iostream>

/**
 * @brief normalLevenAlgorithm - Нерекурсивный алгоритм поиска расстояния Левенштейна 
 * 
 * @param firstWord Первое слово
 * @param secondWord Второе слово
 * @param key Ключ
 * @return Количество сравнивании в алгоритме 
 */
int normalLevenAlgorithm(std::string firstWord, std::string secondWord, bool key);


int checkEquality(const char firstLetter, const char secondLetter);

#endif // ALGORITHMS_H