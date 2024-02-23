#include "algorithms.h"
#include "io_funcs.h"

#include <ctime>

void merge(vector<int> &array, size_t start, size_t middle, size_t end)
{
    // вычисляем размеры левого и правого подмассивов
    size_t n1 = middle - start + 1;
    size_t n2 = end - middle;

    // создаем временные подмассивы
    vector<int> left_array(n1);
    vector<int> right_array(n2);

    // копируем данные из основного массива во временные подмассивы
    for (size_t index = 0; index < n1; index++)
        left_array[index] = array[start + index];

    for (size_t index = 0; index < n2; index++)
        right_array[index] = array[middle + 1 + index];

    // инициализируем индексы для левого, правого и основного массивов
    size_t i = 0, j = 0, k = start;

    // слийем левого и правого подмассивов в основной массив
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }       
    // копируем оставшиеся элементы из левого и правого подмассивов в основной массив
    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    } 
    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &array, size_t start, size_t end)
{
    if (start < end)
    {
        size_t middle = start + (end - start) / 2;
        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

node_t *insert(node_t *root, int data)
{
    if (root == nullptr)
        return new node_t(data);

    if (data < root->_data)
        root->left = insert(root->left, data);
    else if (data > root->_data)
        root->right = insert(root->right, data);

    return root;    
}

void inorder_traversal(node_t *root, vector<int> &array)
{
    if (root != nullptr)
    {
        inorder_traversal(root->left, array);
        array.push_back(root->_data);
        inorder_traversal(root->right, array);
    }
}

vector<int> bin_tree_sort(vector<int> &array)
{
    node_t *root = nullptr;

    for (int data : array)
        root = insert(root, data);

    vector<int> result; 
    inorder_traversal(root, result);
    return result;   
}

void coctail_sort(vector<int> &array)
{
    double factor = 1.2473309; // фактор уменьшения
    
    for (double step = array.size() - 1; step >= 1; step /= factor)
        for (int index = 0; index + step < (int)array.size(); index++)
            if (array[index] > array[index + step])
                swap(array[index], array[index + step]);
}

size_t get_size_merge(const size_t &size)
{
    return 8 * sizeof(size_t) + size * sizeof(int) + 3 * sizeof(vector<int>);
}

size_t get_size_binTree(const size_t &size)
{
    return sizeof(node_t) + 2 * size * sizeof(int) + 2 * sizeof(vector<int>);
}

size_t get_size_coctailSort(const size_t &size)
{
    return size * sizeof(int) + sizeof(vector<int>) + 2 * sizeof(size_t) + sizeof(bool);
}

void compare_alg(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    clock_t start, end;
    
    cout << "Скорость работы алгоритмов измеряется в секундах." << endl;
    cout << "Массивы состоят из " << arr1.size() << " элементов." << endl << endl;
    
    start = clock();
    merge_sort(arr1, 0, arr1.size() - 1);
    end = clock();
    printf("Сортировка слиянием: %.8lf сек.\n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    printf("Размер алгоритма сортировки слиянием = %zu байт.\n\n", get_size_merge(arr1.size()));
    
    start = clock();
    bin_tree_sort(arr2);
    end = clock();
    printf("Сортировка бинарным деревом: %.8lf сек.\n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    printf("Размер алгоритма сортировки бинарным деревом = %zu байт.\n\n", get_size_binTree(arr2.size()));
    //print_array(arr3);
    start = clock();
    coctail_sort(arr3);
    end = clock();
    //print_array(arr3);
    printf("Сортировка расчесткой: %.8lf сек.\n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    printf("Размер алгоритма сортировки расчесткой = %zu байт.\n\n", get_size_coctailSort(arr3.size()));
}

void call_compare_alg()
{
    vector<int> arr1, arr2, arr3;
    
    arr1 = gen_unsorted_arr(10);
    arr2 = gen_unsorted_arr(10);
    arr3 = gen_unsorted_arr(10);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(20);
    arr2 = gen_unsorted_arr(20);
    arr3 = gen_unsorted_arr(20);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(30);
    arr2 = gen_unsorted_arr(30);
    arr3 = gen_unsorted_arr(30);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(40);
    arr2 = gen_unsorted_arr(40);
    arr3 = gen_unsorted_arr(40);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(50);
    arr2 = gen_unsorted_arr(50);
    arr3 = gen_unsorted_arr(50);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(100);
    arr2 = gen_unsorted_arr(100);
    arr3 = gen_unsorted_arr(100);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(200);
    arr2 = gen_unsorted_arr(200);
    arr3 = gen_unsorted_arr(200);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(300);
    arr2 = gen_unsorted_arr(300);
    arr3 = gen_unsorted_arr(300);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(500);
    arr2 = gen_unsorted_arr(500);
    arr3 = gen_unsorted_arr(500);
    compare_alg(arr1, arr2, arr3);
    
    arr1 = gen_unsorted_arr(1000);
    arr2 = gen_unsorted_arr(1000);
    arr3 = gen_unsorted_arr(1000);
    compare_alg(arr1, arr2, arr3);
}
