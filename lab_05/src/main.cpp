#include <iostream>
#include <thread>
#include <fstream>
#include "conveyor.h"

#define TEST_CNT 100

void time_mes(void);


void print_menu()
{
    printf("\n\nStep-by-step processing of reports \
        \n\t1. Conveyor linear processing \
        \n\t2. Conveyor parallel processing \
        \n\t3. Measure the time \
        \n\t4. Display information about the processing stages \
        \n\t0. Exit\n\n");
}

void info_stages(void)
{
    printf("\n\nSequential processing of files with reports by AA: \
            \n\tStep 1. Extract the string (text) from the file. \
            \n\tStep 2. Search for all occurrences of a substring in a string by Boyer-Moore. \
            \n\tStep 3. Dump to a separate search results file.");
}

void run()
{
    int option = -1;

    while (option != 0)
    {
        print_menu();

        std::cout << "Choice: ";
        std::cin >> option;

        if (option == 1)
        {   
            int size = 0;

            std::cout << "\n\nCount: ";
            std::cin >> size;
            Conveyor *conveyor_obj = new Conveyor();
            conveyor_obj->run_linear(size);
            delete conveyor_obj;
        }
        else if (option == 2)
        {
            int size = 0;

            std::cout << "\n\nCount: ";
            std::cin >> size;

            Conveyor *conveyor_obj = new Conveyor();
            conveyor_obj->run_parallel(size);
            delete conveyor_obj;
        }
        else if (option == 3)
        {
            time_mes();
        }
        else if (option == 4)
        {
            info_stages();
        }
        else
        {
            printf("\nError: The menu item is entered incorrectly. Repeat\n");
        }
    }
}


int main(void)
{
    run();

    return 0;
}


void time_mes(void)
{
    size_t size_b = 10, size_e = 100, size_s = 10;

    bool flag_save = true;
    std::ofstream f_par("../data/parallel.csv"),
        f_lin("../data/linear.csv");
        f_par.close();
        f_lin.close();
    f_par.open("./data/parallel_time.csv"); 
    f_lin.open("./data/linear_time.csv");
    if (!f_par || !f_lin)
    {
        flag_save = false;
        std::cout << "Measurement results cannot be saved to a file.\n";
    }

    printf("+--------+-----------------------------------+\n");
    printf( "|%7s | %33s |\n", "Count", "Time, ms");
    printf("|        |-----------------+-----------------|\n");
    printf("| %6s | %15s | %15s |\n","" , "Parallel",  "Linear");
    printf("|--------|-----------------|-----------------|\n");

    auto time_b = chrono::steady_clock::now(), time_e = chrono::steady_clock::now();
    int st1 = 0, st2 = 0;

    for (size_t i_size = size_b; i_size <= size_e; i_size += size_s)
    {   
        for (size_t j = 0; j < TEST_CNT; j ++) 
        {
            Conveyor *conveyor_obj = new Conveyor();
            time_b = chrono::steady_clock::now();

            conveyor_obj->run_linear(i_size, 0);

            time_e = chrono::steady_clock::now();
            delete conveyor_obj;
            st1 += chrono::duration_cast<chrono::milliseconds>(time_e - time_b).count();

            Conveyor *conveyor_obj1 = new Conveyor();
            time_b = chrono::steady_clock::now();

            conveyor_obj1->run_parallel(i_size, 0);

            time_e = chrono::steady_clock::now();
            delete conveyor_obj1;
            st2 += chrono::duration_cast<chrono::milliseconds>(time_e - time_b).count();
         }
        if (st1) st1 /= TEST_CNT;
        if (st2) st2 /= TEST_CNT;

        
        f_par << st1 << std::endl;
        f_lin << st2 << std::endl;
        printf("| %6ld | %15.5d | %15.5d|\n", i_size, st1, st2);
    }
        printf("+--------+-----------------------------------+\n");

}
