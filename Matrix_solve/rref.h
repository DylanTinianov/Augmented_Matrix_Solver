//
//  rref.h
//  matrix_sort
//
//  Created by Dylan Tinianov on 2016-11-10.
//  Copyright © 2016 Dylan Tinianov. All rights reserved.
//

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

void rref(int m, int n, double matrix[m][n]);
int consistent(int m, int n, double matrix[m][n]);
int check_unique(int m, int n, double matrix[m][n]);
double* get_solution(int m, int n, double matrix[m][n]);
void get_infinite(int m, int n, double matrix[m][n], double sln[m][n]);


#ifdef __cplusplus
}
#endif

#endif /* rref_h */
