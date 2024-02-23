#ifndef __CONVEYOR_H__
#define __CONVEYOR_H__

#include <thread>
#include <queue>
#include <mutex>

#include "report.h"

#define THRD_CNT 3

class Conveyor
{
public:
    Conveyor() = default;
    ~Conveyor() = default;

    void run_parallel(size_t reports_cnt, bool log_fl = 1);
    void run_linear(size_t reports_cnt, bool log_fl = 1);

    void get_text();
    void find_subst();
    void output_res();

    void get_text_meassure();
    void find_subst_meassure();
    void output_res_meassure();
    std::vector<std::string> names = {"in_out_data\\1.txt", "in_out_data\\2.txt", "in_out_data\\3.txt",
    "in_out_data\\4.txt", "in_out_data\\5.txt", "in_out_data\\6.txt", "in_out_data\\7.txt", "in_out_data\\8.txt",
    "in_out_data\\10.txt"};

private:
    std::thread threads[THRD_CNT];
    std::vector<std::shared_ptr<Report>> reports;

    std::queue<std::shared_ptr<Report>> q1;
    std::queue<std::shared_ptr<Report>> q2;
    std::queue<std::shared_ptr<Report>> q3;
};

#endif