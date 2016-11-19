#include <stdio.h>
#include "utils.h"




// Useful Functions
void matrix_print(int m, int n, double* *matrix) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%g\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int row_of_zero(int m, int n, double* *matrix, int check_row) {
    for (int j = 0; j < n-1; j++) {
        if (matrix[check_row][j] != 0) return 0;
        
    }
    return 1;
}

void set_matrix(double* *matrix, int val_row, int val_col, int val) {
    matrix[val_row][val_col] = val;
}

void delete_matrix(int m, double* *matrix) {
    for (int i=0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

