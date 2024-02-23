#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <string>
#include <mutex>

using namespace std;

struct Interval
{
    vector<string>::const_iterator begin;
    vector<string>::const_iterator end;
    const vector<string> &dictionary;
    vector<string> &result;
    mutex &result_mutex;
};

/**
 * @brief single_thread - Однопоточная  реализация 
 * 
 * @param input_text Входной текст
 * @param dictionary Словарь
 */
void single_thread(const string &input_text, const vector<string> &dictionary);

void multi_thread(const string &input_text, const vector<string> &dictionary, int num_threads);

void correctSpelling(const string& inputText, const vector<string>& dictionary, int numThreads);


#endif // ALGORITHMS_H
