#ifndef utils_h
#define utils_h

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

void matrix_print(int m, int n, double matrix[m][n]);
int row_of_zero(int m, int n, double matrix[m][n], int check_row);

#ifdef __cplusplus
}
#endif

#endif /* utils_h */
