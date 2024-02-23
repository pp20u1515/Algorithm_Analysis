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

void multi_thread(const string &input_text, const vector<string> &dictionary, int num_threads, const bool &flag);

#endif // ALGORITHMS_H
