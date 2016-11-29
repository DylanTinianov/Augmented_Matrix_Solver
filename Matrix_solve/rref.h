#ifndef rref_h
#define rref_h

#ifdef __cplusplus
extern "C"
{  
#endif

#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include <math.h>

void rref(int m, int n, double* *matrix);
int consistent(int m, int n, double* *matrix);
int check_unique(int m, int n, double* *matrix);
int get_solution(int m, int n, double* *matrix, double *solution);
void get_infinite(int m, int n, double* *matrix, double* *sln);
int col_free(int m, int n, double* *matrix, int col);

#ifdef __cplusplus
}
#endif

#endif /* rref_h */

