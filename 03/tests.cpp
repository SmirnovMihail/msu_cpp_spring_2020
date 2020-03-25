#include <iostream>
#include "tests.h"

void compare_test(const Matrix &a, const Matrix &b)
{
    printf("Compare a with b using a==b\n\n");
    if (a == b)
        printf("Matrix a IS EQUAL to matrix b\n\n");
    else
        printf("Matrix a IS NOT EQUAL to matrix b\n\n");
}

void test()
{
    Matrix a;
    a[2][3] = 1;
    a[4][4] = 1;
    printf("Matrix a\n");
    a.print_matrix();
    printf("\n");

    Matrix b;
    b[2][3] = 1;
    b[4][4] = 1;
    printf("Matrix b\n");
    b.print_matrix();
    printf("\n");

    compare_test(a, b);

    b[1][1] = 2;
    b[3][0] = 1;
    b[0][3] = 525;
    printf("Matrix b\n");
    b.print_matrix();
    printf("\n");

    compare_test(a, b);
    
    printf("Multiply b on 3 using b *= 3\n\n");
    b *= 3;
    printf("Matrix b\n");
    b.print_matrix();
    printf("\n");

    printf("Taking fofth elem of the first row\n\n");
    int elem = b[0][3];
    printf("b[0][3] = %d\n\n", elem);

    Matrix c(3, 3);
    for (int i=0; i < c.get_rows(); i++)
        c[1][i] = i*i*i;
    printf("Matrix c\n");
    c.print_matrix();
    printf("\n");
}

