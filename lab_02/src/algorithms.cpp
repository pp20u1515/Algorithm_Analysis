#include "algorithms.h"
#include "return_codes.h"
#include "io_funcs.h"

#include <ctime>
#include <cstdio>

vector<vector<int>> mulMatrices(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix)
{
    size_t n = firstMatrix.size(); // количество строк первой матрицы
    size_t m = secondMatrix[0].size(); // количество столбцов второй матрицы
    size_t q = firstMatrix[0].size(); // количество столбцов первой матрицы

    // Создание матрица для хранения результата умножения
    vector<vector<int>> resultMatrix(n, vector<int>(m, 0));

    // Выполнение уможения матриц
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            for (size_t k = 0; k < q; k++)
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];

    // Возвращение результата в виде новой матрицы 
    return resultMatrix;
}

vector<vector<int>> mulVinogradAlg(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix)
{
    size_t n = firstMatrix.size(); // количество строк первой матрицы
    size_t m = secondMatrix[0].size(); // количество столбцов второй матрицы
    size_t p = secondMatrix.size(); // количество строк второй матрицы
    size_t q = firstMatrix[0].size(); // количество столбцов первой матрицы

    // Создание матрица для хранения результата умножения
    vector<vector<int>> resultMatrix(n, vector<int>(m, 0));
    vector<int> sumRow(n), sumColumn(m); // вспомогательные массивы для предварительного вычисления
                                        //  элементов строк и столбцов в матрице

    // Рассчитываем сумму произведений пар элементов в каждой строке из первой матрицы
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < q / 2; j++)
            sumRow[i] = sumRow[i] + firstMatrix[i][2 * j] * firstMatrix[i][2 * j + 1]; 

    // Рассчитываем сумму произведений пар элементов в каждом столбце из второй матрицы
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < p / 2; j++)
            sumColumn[i] = sumColumn[i] + secondMatrix[2 * j][i] * secondMatrix[2 * j + 1][i];             
    
    // Вычисляем элементы результирующей матрицы
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            resultMatrix[i][j] = resultMatrix[i][j] - sumRow[i] - sumColumn[j];
            for (size_t k = 0; k < q / 2; k++)
                resultMatrix[i][j] = resultMatrix[i][j] + (firstMatrix[i][2 * k + 1] + secondMatrix[2 * k][j]) * (firstMatrix[i][2 * k] + secondMatrix[2 * k + 1][j]);
        }

    // проверка на нечетность
    if (q % 2 == 1)
    {
        // Если количество столбцов было нечетное, выполняем дополнительное умножение
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                resultMatrix[i][j] += firstMatrix[i][q - 1] * secondMatrix[q - 1][j];
    }
    
    return resultMatrix;
}

vector<vector<int>> optVinogradAlg(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix)
{
    size_t n = firstMatrix.size(); // количество строк первой матрицы
    size_t m = secondMatrix[0].size(); // количество столбцов второй матрицы
    size_t p = secondMatrix.size(); // количество строк второй матрицы
    size_t q = firstMatrix[0].size(); // количество столбцов первой матрицы

    // Создание матрица для хранения результата умножения
    vector<vector<int>> resultMatrix(n, vector<int>(m, 0)); 
    vector<int> sumRow(n), sumColumn(m); // вспомогательные массивы для предварительного вычисления
                                        //  элементов строк и столбцов в матрице

    // Рассчитываем сумму произведений пар элементов в каждой строке из первой матрицы
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < q / 2; j++)
            sumRow[i] += firstMatrix[i][j << 1] * firstMatrix[i][(j << 1) + 1]; 

    // Рассчитываем сумму произведений пар элементов в каждом столбце из второй матрицы
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < p / 2; j++)
            sumColumn[i] += secondMatrix[j << 1][i] * secondMatrix[(j << 1) + 1][i];             
    
    // Вычисляем элементы результирующей матрицы
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            resultMatrix[i][j] = resultMatrix[i][j] - sumRow[i] - sumColumn[j];
            for (size_t k = 0; k < q / 2; k++)
                resultMatrix[i][j] += (firstMatrix[i][(k << 1) + 1] + secondMatrix[k << 1][j]) * (firstMatrix[i][k << 1] + secondMatrix[(k << 1) + 1][j]);
        }

    // проверка на нечетность
    if (q % 2 == 1)
    {
        // Если количество столбцов было нечетное, выполняем дополнительное умножение
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                resultMatrix[i][j] += firstMatrix[i][q - 1] * secondMatrix[q - 1][j];
    }

    return resultMatrix;
}

vector<vector<int>> matrixAdd(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix) {
    size_t n = firstMatrix.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrixSubtract(const vector<vector<int>> &firstMatrix, const vector<vector<int>> &secondMatrix) 
{
    size_t n = firstMatrix.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            result[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }

    return result;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>>& B) 
{
    size_t n = A.size();

    // Разбиваем матрицы на четыре подматрицы
    size_t halfSize = n / 2;
    vector<vector<int>> A11(halfSize, vector<int>(halfSize));
    vector<vector<int>> A12(halfSize, vector<int>(halfSize));
    vector<vector<int>> A21(halfSize, vector<int>(halfSize));
    vector<vector<int>> A22(halfSize, vector<int>(halfSize));
    vector<vector<int>> B11(halfSize, vector<int>(halfSize));
    vector<vector<int>> B12(halfSize, vector<int>(halfSize));
    vector<vector<int>> B21(halfSize, vector<int>(halfSize));
    vector<vector<int>> B22(halfSize, vector<int>(halfSize));

    // Заполняем подматрицы значениями из исходных матриц
    for (size_t i = 0; i < halfSize; i++) {
        for (size_t j = 0; j < halfSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

    // Рекурсивно вычисляем 7 произведений
    vector<vector<int>> P1 = strassenMultiply(matrixAdd(A11, A22), matrixAdd(B11, B22));
    vector<vector<int>> P2 = strassenMultiply(matrixAdd(A21, A22), B11);
    vector<vector<int>> P3 = strassenMultiply(A11, matrixSubtract(B12, B22));
    vector<vector<int>> P4 = strassenMultiply(A22, matrixSubtract(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(matrixAdd(A11, A12), B22);
    vector<vector<int>> P6 = strassenMultiply(matrixSubtract(A21, A11), matrixAdd(B11, B12));
    vector<vector<int>> P7 = strassenMultiply(matrixSubtract(A12, A22), matrixAdd(B21, B22));

    // Вычисляем результат на основе 7 произведений
    vector<vector<int>> C11 = matrixAdd(matrixSubtract(matrixAdd(P1, P4), P5), P7);
    vector<vector<int>> C12 = matrixAdd(P3, P5);
    vector<vector<int>> C21 = matrixAdd(P2, P4);
    vector<vector<int>> C22 = matrixAdd(matrixAdd(matrixSubtract(P1, P2), P3), P6);

    // Собираем результат обратно в одну матрицу
    vector<vector<int>> result(n, vector<int>(n));

    // Собыраем результатов из четырех подматриц в одну общую
    for (size_t i = 0; i < halfSize; i++) {
        for (size_t j = 0; j < halfSize; j++) {
            result[i][j] = C11[i][j];
            result[i][j + halfSize] = C12[i][j];
            result[i + halfSize][j] = C21[i][j];
            result[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    return result;
}

void compareAlgorithms(vector<vector<int>> &firstMatrix, vector<vector<int>> &secondMatrix)
{
    clock_t start, end;

    inputAutoMatrix(firstMatrix, firstMatrix.size(), firstMatrix[0].size());
    inputAutoMatrix(secondMatrix, secondMatrix.size(), secondMatrix[0].size());

    cout << "Скорость работы алгоритмов измеряется в секундах, памянь в байтах." << endl;
    cout << "Матрицы имеют размер: " <<  firstMatrix.size() << "x" << firstMatrix[0].size() << endl;
    
    cout << "Стандартный алгоритм умножения матрицы: ";
    start = clock();
    mulMatrices(firstMatrix, secondMatrix);
    end = clock();
    printf("%.8lf сек.\n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    cout << "Размер стандартного алгоритма умножения матрицы: " << 3 * sizeof(size_t) + firstMatrix.size() *
    firstMatrix[0].size() * sizeof(int) + sizeof(vector<vector<int>>) + secondMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + firstMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>)<< " байт." << endl << endl;

    cout << "Алгоритм Винограда умножения матрицы: ";
    start = clock();
    mulVinogradAlg(firstMatrix, secondMatrix);
    end = clock();
    printf("%.8lf сек.* \n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    cout << "Размер алгоритмa Винограда умножения матрицы: "<< 4 * sizeof(size_t) + firstMatrix.size() *
    firstMatrix[0].size() * sizeof(int) + sizeof(vector<vector<int>>) + secondMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + firstMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + firstMatrix.size() * sizeof(vector<int>) + 
    secondMatrix[0].size() * sizeof(vector<int>)<< " байт." << endl << endl;

    cout << "Оптимизированый алгоритм Винограда умножения матрицы: ";
    start = clock();
    optVinogradAlg(firstMatrix, secondMatrix);
    end = clock();
    printf("%.8lf сек.\n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    cout << "Размер оптимизированного алгоритмa Винограда умножения матрицы: "<< 4 * sizeof(size_t) + firstMatrix.size() *
    firstMatrix[0].size() * sizeof(int) + sizeof(vector<vector<int>>) + secondMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + firstMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + firstMatrix.size() * sizeof(vector<int>) + 
    secondMatrix[0].size() * sizeof(vector<int>)<< " байт." << endl;

    cout << "Aлгоритм Штрассена умножения матрицы: ";
    start = clock();
    strassenMultiply(firstMatrix, secondMatrix);
    end = clock();
    printf("%.8lf сек.\n", (end - start) / (CLOCKS_PER_SEC * 100.0));
    cout << "Размер aлгоритмa Штрассена умножения матрицы: "<<  firstMatrix.size() * firstMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + secondMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + firstMatrix.size() * secondMatrix[0].size() * 
    sizeof(int) + sizeof(vector<vector<int>>) + 2 * sizeof(size_t) +  8 * ((firstMatrix.size() / 2) *
    (firstMatrix.size() / 2)) * sizeof(int) + 19 * sizeof(vector<vector<int>>)<< " байт." << endl;
    cout << "--------------------------------------------------------------------------------" << endl << endl;
}

void callCompareAlg()
{
    vector<vector<int>> firstMatrix(2, vector<int>(2, 0)), secondMatrix(10, vector<int>(10, 0));

    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(4);
    firstMatrix[0].resize(4);
    secondMatrix.resize(4);
    secondMatrix[0].resize(4);
    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(8);
    firstMatrix[0].resize(8);
    secondMatrix.resize(8);
    secondMatrix[0].resize(8);
    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(16);
    firstMatrix[0].resize(16);
    secondMatrix.resize(16);
    secondMatrix[0].resize(16);
    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(32);
    firstMatrix[0].resize(32);
    secondMatrix.resize(32);
    secondMatrix[0].resize(32);
    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(64);
    firstMatrix[0].resize(64);
    secondMatrix.resize(64);
    secondMatrix[0].resize(64);
    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(128);
    firstMatrix[0].resize(128);
    secondMatrix.resize(128);
    secondMatrix[0].resize(128);
    compareAlgorithms(firstMatrix, secondMatrix);

    firstMatrix.resize(256);
    firstMatrix[0].resize(256);
    secondMatrix.resize(256);
    secondMatrix[0].resize(256);
    compareAlgorithms(firstMatrix, secondMatrix);
}
