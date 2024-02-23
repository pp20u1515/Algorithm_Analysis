#ifndef __CAR_H__
#define __CAR_H__

#include <memory>
#include <cmath>
#include <vector>

#include "logger.h"

using namespace std;

int GoodSuffix(int j, string& pat);
int BadChar(int j,char temp,string str);
vector<int> BM(string source, string target);

class Report
{
public:
    Report() = default;
    Report(std::string filename):Filename(filename) {};

    ~Report() = default;

    void get_text(size_t);
    void find_subst(size_t);
    void output_res(size_t);

    void get_text_meassure(size_t);
    void find_subst_meassure(size_t);
    void output_res_meassure(size_t);

    void substring_rename(std::string new_substr)
    {
        Substring = new_substr;
    }

private:
    std::string Text;
    std::string Filename;
    std::string Substring = "ан";
    std::vector<int> Answer;
};

#endif
