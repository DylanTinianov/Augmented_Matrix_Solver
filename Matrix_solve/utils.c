#include <stdio.h>
#include "utils.h"

#define EPSILON 0.000000001


int row_of_zero(int m, int n, double* *matrix, int check_row) {
    for (int j = 0; j < n-1; j++) {
        if (fabs(matrix[check_row][j]) >= EPSILON) return 0;
    }
    return 1;
}

void set_matrix(double* *matrix, int val_row, int val_col, double val) {
    matrix[val_row][val_col] = val;
}

void delete_matrix(int m, double* *matrix) {
    for (int i=0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

