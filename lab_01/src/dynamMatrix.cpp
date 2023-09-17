#include <dynamMatrix.hpp>
#include <return_codes.hpp>

#include <cstdlib>


int **allocateMatrix(const std::size_t rows, const std::size_t columns)
{
    std::size_t flag = OK;

    int **data = (int **)calloc(rows, sizeof(int *));

    if (data)
    {
        for (std::size_t index = 0; flag == 0 && index < columns; index++)
        {
            data[index] = (int *)calloc(columns, sizeof(int));
            
            if (data[index] == NULL)
            {
                flag = ERROR;
                freeMatrix(data, rows);
                data = NULL;
            }
        }
        
    }
    return data;
}

void freeMatrix(int **matrix, const std::size_t rows)
{
    for (std::size_t index = 0; index < rows; index++)
        free(matrix[index]);

    free(matrix);        
}