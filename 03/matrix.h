#include <iostream>

class Helper;

class Matrix
{
    int *matrix;
    const size_t columns;
    const size_t rows;
    const size_t size;
public:
    Matrix(size_t row_num = 5, size_t column_num = 5);
    size_t get_rows() const;
    size_t get_columns() const;
    const Helper operator[](size_t row) const;
    Matrix&  operator*=(int number);
    bool operator==(const Matrix& second) const;
    bool operator!=(const Matrix& second) const;
    void print_matrix() const;
    ~Matrix();
};

class Helper
{
    int *row;
    size_t max_columns;
public:
    Helper(int *current_row, size_t max_c) : row(current_row), max_columns(max_c) {};
    int& operator[](size_t column) const;
};

