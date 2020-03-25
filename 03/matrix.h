#include <iostream>

class Helper;

class Matrix
{
    friend class Helper;
    int *matrix;
    size_t columns;
    size_t rows;
    size_t size;
public:
    Matrix(size_t row_num = 5, size_t column_num = 5);
    size_t get_rows() const;
    size_t get_columns() const;
    const Helper operator[](int row) const;
    void operator*=(int number);
    bool operator==(const Matrix& second) const;
    bool operator!=(const Matrix& second) const;
    void print_matrix() const;
    ~Matrix();
};

class Helper
{
    const Matrix& m;
    int row;
public:
    Helper(const Matrix& matrix, int row_num) : m(matrix), row(row_num) {};
    int& operator[](int column) const;
};

