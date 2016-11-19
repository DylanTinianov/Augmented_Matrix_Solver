#ifndef matrix_sort_h
#define matrix_sort_h

#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"


int check_sorted(int m, int n, double* *matrix, int start_row, int col);
void implement_sort(int m, int n, double* *matrix, int start_row, int col);
int num_ceofficients(int m, int n, double* *matrix, int start_row, int col);
void matrix_sort(int m, int n, double* *matrix);



#endif /* matrix_sort_h */
