#include "matrix.h"

int& Helper :: operator[](int column) const
{
    if (column >= m.columns)
        throw std::out_of_range("");
    return m.matrix[row*m.columns + column];
}

Matrix :: Matrix(size_t row_num, size_t column_num)
{
    rows = row_num;
    columns = column_num;
    size = rows*columns;
    matrix = new int[size];
    for (int i=0; i < size; i++)
        matrix[i] = 0;
}

size_t Matrix :: get_rows() const
{
    return rows;
}

size_t Matrix :: get_columns() const
{
    return columns;
}

const Helper Matrix :: operator[](int row) const
{
    if (row >= rows)
        throw std::out_of_range("");
    return Helper(*this, row);
}

void Matrix :: operator*=(int number)
{
    for (int i=0; i < size; i++)
    {
        matrix[i] *= number;
    }
}

bool Matrix :: operator==(const Matrix& second) const
{
    bool res = true;
    if (rows != second.rows or columns != second.columns)
        res = false;
    else
    {
        for (int i=0; i < size; i++)
        {
            if (matrix[i] != second.matrix[i])
                res = false;
        }
    }
    return res;
}

bool Matrix :: operator!=(const Matrix& second) const
{
    return !(*this == second);
}

void Matrix :: print_matrix() const
{
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < columns; j++)
        {
            int elem = (*this)[i][j];
            printf("%d", elem);
            int p, x = elem==0 ? 1 : 0;
            for (p = x; elem; p++)
                elem /= 10;
            for (int k = 0; k <= 6 - p; k++)
                printf(" ");
        }
        printf("\n");
    }
}

Matrix :: ~Matrix()
{
    delete[] matrix;
}