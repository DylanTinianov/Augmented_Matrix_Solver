#ifndef utils_h
#define utils_h

#ifdef __cplusplus
extern "C"
{  
#endif

#include <stdio.h>

void matrix_print(int m, int n, double* *matrix);
int row_of_zero(int m, int n, double* *matrix, int check_row);
void set_matrix(double* *matrix, int val_row, int val_col, int val);
void delete_matrix(int m, double* *matrix);

#ifdef __cplusplus
}
#endif

#endif /* utils_h */
