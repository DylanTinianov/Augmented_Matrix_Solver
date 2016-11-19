#ifndef utils_h
#define utils_h

#include <stdio.h>

void matrix_print(int m, int n, double* *matrix);
int row_of_zero(int m, int n, double* *matrix, int check_row);
void set_matrix(double* *matrix, int val_row, int val_col, int val);

#endif /* utils_h */
