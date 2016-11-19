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
double* get_solution(int m, int n, double* *matrix);
void get_infinite(int m, int n, double* *matrix, double* *sln);

#ifdef __cplusplus
}
#endif

#endif /* rref_h */
