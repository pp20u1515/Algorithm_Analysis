#include <iostream>
#include <string>
#include <locale>
#include <vector>

#include "io_funcs.h"
#include "algorithms.h"
#include "return_codes.h"

#define MAX_LEN_ANSWER 3

int main()
{
    vector<vector<int>> firstMatrix, secondMatrix, resultMatrix;
    string answerChar;
    int choice = -1;
    int rc = OK;

    callReadMatrices(firstMatrix, secondMatrix);
    while (choice != 0)
    {
        menu();
        while (true)
        {
            cout << "\tВыберите действие: ";
            cin >> answerChar;

            try
            {
                choice = stoi(answerChar);
                break; 
            }
            catch(const invalid_argument &e)
            {
                if (answerChar == "0")
                {
                    choice = 0;
                    break;
                }
            
            cout << "\tНеправильный ввод!" << endl;
            }
        }
        switch (choice)
        {
            case (0):
                std::cout << "\tПрограмма завершена!" << std::endl;
                return OK;
            case (1):
                resultMatrix = mulMatrices(firstMatrix, secondMatrix);
                printMatrix(resultMatrix, resultMatrix.size(), resultMatrix[0].size()); 
                rc = OK;
                break;    
            case (2):
                resultMatrix = mulVinogradAlg(firstMatrix, secondMatrix);
                printMatrix(resultMatrix, resultMatrix.size(), resultMatrix[0].size());
                rc = OK;
                break;  
            case (3):
                resultMatrix = optVinogradAlg(firstMatrix, secondMatrix);
                printMatrix(resultMatrix, resultMatrix.size(), resultMatrix[0].size());
                rc = OK;
                break; 
            case (4):
            	// Если матрицы имеют размер 1х1, выполняется прямое умножение
    		if (firstMatrix.size() == 1) {
        		vector<vector<int>> result(1, vector<int>(1));
        		result[0][0] = A[0][0] * B[0][0];
        		printMatrix(resultMatrix, resultMatrix.size(), resultMatrix[0].size());
    		}
    		else{
                	resultMatrix = strassenMultiply(firstMatrix, secondMatrix);
                	printMatrix(resultMatrix, resultMatrix.size(), resultMatrix[0].size());
                }
                rc = OK;
                break;    
            case (5):
                callCompareAlg();
                rc = OK;
                break;     
            default:
                cout << "Ошибка: Неправильный ввод!" << endl;
                break;
        }
    }

    return rc;
}
