#include "conveyor.h"

std::mutex mutex_q2;
std::mutex mutex_q3;

void Conveyor::run_parallel(size_t reports_cnt, bool log_fl)
{
    for (size_t i = 0; i < reports_cnt; i++)
    {
        std::string n = Conveyor::names[rand() % (names.size())];
        std::shared_ptr<Report> new_report(new Report(n));
        reports.push_back(new_report);
        q1.push(new_report);
    }

    if (log_fl)
    {
    this->threads[0] = std::thread(&Conveyor::get_text, this);
    this->threads[1] = std::thread(&Conveyor::find_subst, this);
    this->threads[2] = std::thread(&Conveyor::output_res, this);
    }
    else
    {
    this->threads[0] = std::thread(&Conveyor::get_text_meassure, this);
    this->threads[1] = std::thread(&Conveyor::find_subst_meassure, this);
    this->threads[2] = std::thread(&Conveyor::output_res_meassure, this);
    }

    for (int i = THRD_CNT-1; i >=0; i--)
    {
        this->threads[i].join();
    }
}

void Conveyor::run_linear(size_t reports_cnt, bool log_fl) 
{
    for (size_t i = 0; i < reports_cnt; i++)
    {
        std::string n = Conveyor::names[rand() % (names.size())];
        std::shared_ptr<Report> new_report(new Report(n));
        reports.push_back(new_report);
        q1.push(new_report);
    }
    for (size_t i = 0; i < reports_cnt; i++) 
    {
        std::shared_ptr<Report> report = q1.front();
        if (log_fl) report->get_text(i + 1);
        else report->get_text_meassure(i + 1);
        q2.push(report);
        q1.pop();

        report = q2.front();
        if (log_fl) report->find_subst(i + 1);
        else report->find_subst_meassure(i + 1);
        q3.push(report);
        q2.pop();

        report = q3.front();
        if (log_fl) report->output_res(i + 1);
        else report->output_res_meassure(i + 1);
        q3.pop();
    }
}

void Conveyor::get_text()
{
    size_t task_num = 0;

    while (!this->q1.empty())
    {
        std::shared_ptr<Report> report = q1.front();
        q1.pop();
        report->get_text(++task_num);

        mutex_q2.lock();
        q2.push(report);
        mutex_q2.unlock();
    }
}

void Conveyor::find_subst()
{
    size_t task_num = 0;

        do
    {
        if (!this->q2.empty())
        {
            mutex_q2.lock();
            std::shared_ptr<Report> report = q2.front();
            mutex_q2.unlock();
            
            report->find_subst(++task_num);

            mutex_q3.lock();
            q3.push(report);
            mutex_q3.unlock();
            mutex_q2.lock();
            q2.pop();
            mutex_q2.unlock();
        }
    } while(!q1.empty() || !q2.empty());
}

void Conveyor::output_res()
{
    size_t task_num = 0;
    do
    {
        if (!this->q3.empty())
        {
            mutex_q3.lock();
            std::shared_ptr<Report> report = q3.front();
            mutex_q3.unlock();

            report->output_res(++task_num);
            mutex_q3.lock();
            q3.pop();
            mutex_q3.unlock();
        }
    } while (!q1.empty() || !q2.empty() || !q3.empty());
}


void Conveyor::get_text_meassure()
{
    size_t task_num = 0;

    while (!this->q1.empty())
    {
        std::shared_ptr<Report> report = q1.front();
        q1.pop();
        report->get_text_meassure(++task_num);

        mutex_q2.lock();
        q2.push(report);
        mutex_q2.unlock();
    }
}

void Conveyor::find_subst_meassure()
{
    size_t task_num = 0;

    do
    {
        if (!this->q2.empty())
        {
            mutex_q2.lock();
            std::shared_ptr<Report> report = q2.front();
            mutex_q2.unlock();
            
            report->find_subst_meassure(++task_num);

            mutex_q3.lock();
            q3.push(report);
            mutex_q3.unlock();
            mutex_q2.lock();
            q2.pop();
            mutex_q2.unlock();
        }
    } while(!q1.empty() || !q2.empty());
}

void Conveyor::output_res_meassure()
{
    size_t task_num = 0;
    do
    {
        if (!this->q3.empty())
        {
            mutex_q3.lock();
            std::shared_ptr<Report> report = q3.front();
            mutex_q3.unlock();

            report->output_res_meassure(++task_num);
            mutex_q3.lock();
            q3.pop();
            mutex_q3.unlock();
        }
    } while (!q1.empty() || !q2.empty() || !q3.empty());
}
