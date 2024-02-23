#include "algorithms.h"
#include "return_codes.h"
#include "io_funcs.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <limits>
#include <thread>

#define EQUAL 0
#define NOT_EQUAL 1

void init_matrix(vector<vector<int>> &matrix, const size_t &rows, const size_t &columns)
{
    // инициализируем первый столбец матрицы
    for (size_t index = 0; index < rows; index++)
        matrix[index][0] = index;

    // инициализируем первую строку матрицы
    for (size_t index = 0; index < columns; index++)
        matrix[0][index] = index;  
}

int alg_lev(const string &word1, const string &word2)
{
    const size_t n = word1.length();
    const size_t m = word2.length();
    int change = 0; // штраф
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));

    init_matrix(matrix, n + 1, m + 1);

    for (size_t index_i = 1; index_i < n + 1; index_i++)
        for (size_t index_j = 1; index_j < m + 1; index_j++)
        {
            change = word1[index_i - 1] == word2[index_j - 1] ? EQUAL : NOT_EQUAL;
            matrix[index_i][index_j] = min(matrix[index_i][index_j - 1] + 1,
                                    min(matrix[index_i - 1][index_j] + 1,
                                    matrix[index_i - 1][index_j - 1] + change));
        }
    return matrix[n][m];
}

int alg_lev_optimized(const string &word1, const string &word2) {
    const size_t n = word1.length();
    const size_t m = word2.length();
    
    // Используем одномерный массив вместо матрицы
    vector<int> dp(m + 1, 0);

    for (size_t j = 1; j <= m; ++j)
        dp[j] = j;

    for (size_t i = 1; i <= n; ++i) 
    {
        int prev = i;  // Значение в предыдущей ячейке (dp[j-1])
        dp[0] = i;     // Значение в текущей ячейке (dp[j])

        for (size_t j = 1; j <= m; ++j) 
        {
            int change = (word1[i - 1] == word2[j - 1]) ? EQUAL : NOT_EQUAL;
            int insertion = dp[j] + 1;
            int deletion = dp[j - 1] + 1;
            int substitution = prev + change;

            // Находим минимальное из трех значений
            dp[j] = min({insertion, deletion, substitution});

            // Сохраняем текущее значение для следующей итерации
            prev = dp[j];
        }
    }

    // Расстояние Левенштейна находится в последней ячейке
    return dp[m];
}

void single_thread(const string &input_text, const vector<string> &dictionary)
{
    string temp_text = input_text; // 1

    // Разбиваем входной текст на слова
    istringstream iss(temp_text); // 2
    vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>{}); // 3

    for (auto &word : words) // 4
    {
        int min_distance = numeric_limits<int>::max(); // 5
        string best_match = word; // 6

        for (auto &dict_word : dictionary) // 7
        {
            int distance = alg_lev(word, dict_word); // 8
            
            if (distance < min_distance) // 9
            {
                min_distance = distance; // 10
                best_match = dict_word; // 11
            }
        }
        // Заменяем слово на наилучший вариант из словаря
        size_t pos = temp_text.find(word); // 12
        
        while (pos != string::npos) // 13
        {
            temp_text.replace(pos, word.length(), best_match); // 14
            pos = temp_text.find(word, pos + best_match.length()); // 15
        }
    }
    print_result(input_text, temp_text);
}

// Функция исправления слова на основе словаря
string correctWord(const string& word, const vector<string>& dictionary) {
    string correctedWord = word;
    int minDistance = numeric_limits<int>::max();

    for (const string& dictWord : dictionary) {
        int distance = alg_lev(word, dictWord);
        if (distance < minDistance) {
            minDistance = distance;
            correctedWord = dictWord;
        }
    }

    return correctedWord;
}

// Функция для обработки слов в заданном диапазоне
void processWords(const vector<string>::iterator& begin,
                   const vector<string>::iterator& end,
                   const vector<string>& dictionary,
                   vector<string>& result,
                   mutex& resultMutex) {
    for (auto it = begin; it != end; ++it) {
        string correctedWord = correctWord(*it, dictionary);

        // Критическая секция для обновления результата
        lock_guard<mutex> lock(resultMutex);
        result.push_back(correctedWord);
    }
}

// Главная функция многопоточной обработки текста
void multi_thread(const string &input_text, const vector<string> &dictionary, int num_threads) 
{
    vector<string> words;
    istringstream iss(input_text);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));

    vector<thread> threads;
    vector<string> correctedWords;
    mutex resultMutex;

    int wordsPerThread = words.size() / num_threads;
    int remainder = words.size() % num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * wordsPerThread;
        int end = start + wordsPerThread + (i == num_threads - 1 ? remainder : 0);

        threads.emplace_back(processWords, words.begin() + start, words.begin() + end,
                             ref(dictionary), ref(correctedWords), ref(resultMutex));
    }

    for (auto& thread : threads) {
        thread.join();
    }
    cout << "Входной текст: " << input_text << endl;
    cout << "Выходной текст: ";
    for (const string& correctedWord : correctedWords) {
        cout << correctedWord << " ";
    }
    cout << endl;
}
