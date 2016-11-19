#ifndef eros_h
#define eros_h

#include <stdio.h>


void addition_ero(int m, int n, double* *matrix, int add, int add_to);
void subtract_ero(int m, int n, double* *matrix, int sub, int sub_to);
void scalar_mult_ero(int m, int n, double* *matrix, int row, double scalar);
void row_swap_ero(int m, int n, double* *matrix, int row1, int row2);

#endif /* eros_h */
