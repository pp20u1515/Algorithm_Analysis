#include "algorithms.h"
#include "io_funcs.h"
#include "return_codes.h"

#include <cstdlib>
#include <algorithm>

int standard_search(const vector<int> &arr, const int target) 
{
    for (size_t i = 0; i < arr.size(); ++i)
        if (arr[i] == target)
            return i;

    return -1;
}

int binary_search(const vector<int>& arr, const int target) 
{
    int low = 0, high = arr.size() - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}


void compare_algorithms()
{
    vector<int> array;
    double time = 0.0;
    int count = 0;
    time_t start, finish;

    cout << "Массив содержит 259 элементов!" << endl;

    generate_unique_array(array, 259);
    
    while (count < 10)
    {
        start = clock();
        standard_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Стандартный алгоритм поиска: %.8f сек.\n", time / 10);

    time = 0.0;
    count = 0;
    sort(array.begin(), array.end());

    while (count < 10)
    {
        start = clock();
        binary_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Бинарный алгоритм поиска: %.8f сек.\n", time / 10);
    cout << endl;
    time = 0.0;
    count = 0;

    cout << "Массив содержит 1027 элементов!" << endl;

    generate_unique_array(array, 1027);
    
    while (count < 10)
    {
        start = clock();
        standard_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Стандартный алгоритм поиска: %.8f сек.\n", time / 10);

    time = 0.0;
    count = 0;
    sort(array.begin(), array.end());

    while (count < 10)
    {
        start = clock();
        binary_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Бинарный алгоритм поиска: %.8f сек.\n", time / 10);
    cout << endl;
    time = 0.0;
    count = 0;

    cout << "Массив содержит 4099 элементов!" << endl;

    generate_unique_array(array, 4099);
    
    while (count < 10)
    {
        start = clock();
        standard_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Стандартный алгоритм поиска: %.8f сек.\n", time / 10);

    time = 0.0;
    count = 0;
    sort(array.begin(), array.end());

    while (count < 10)
    {
        start = clock();
        binary_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Бинарный алгоритм поиска: %.8f сек.\n", time / 10);
    cout << endl;
    time = 0.0;
    count = 0;

    cout << "Массив содержит 16389 элементов!" << endl;

    generate_unique_array(array, 16389);
    
    while (count < 10)
    {
        start = clock();
        standard_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Стандартный алгоритм поиска: %.8f сек.\n", time / 10);

    time = 0.0;
    count = 0;
    sort(array.begin(), array.end());

    while (count < 10)
    {
        start = clock();
        binary_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Бинарный алгоритм поиска: %.8f сек.\n", time / 10);
    cout << endl;
    time = 0.0;
    count = 0;

    cout << "Массив содержит 65539 элементов!" << endl;

    generate_unique_array(array, 65539);
    
    while (count < 10)
    {
        start = clock();
        standard_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Стандартный алгоритм поиска: %.8f сек.\n", time / 10);

    time = 0.0;
    count = 0;
    sort(array.begin(), array.end());

    while (count < 10)
    {
        start = clock();
        binary_search(array, -10);
        finish = clock();
        time += (finish - start) / (CLOCKS_PER_SEC * 1.0);
        count++;
    }
    printf("Бинарный алгоритм поиска: %.8f сек.\n", time / 10);
    cout << endl;
}