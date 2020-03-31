#include <iostream>

class Helper;

class Matrix
{
    int *matrix;
    size_t columns;
    size_t rows;
    size_t size;
public:
    Matrix(size_t row_num = 5, size_t column_num = 5);
    size_t get_rows() const;
    size_t get_columns() const;
    int* get_matrix() const;
    const Helper operator[](size_t row) const;
    Matrix&  operator*=(int number);
    bool operator==(const Matrix& second) const;
    bool operator!=(const Matrix& second) const;
    void print_matrix() const;
    ~Matrix();
};

class Helper
{
    const Matrix& m;
    size_t row;
public:
    Helper(const Matrix& matrix, size_t row_num) : m(matrix), row(row_num) {};
    int& operator[](size_t column) const;
};

