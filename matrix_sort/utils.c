#include <stdio.h>
#include "utils.h"


// Useful Functions
void matrix_print(int m, int n, double matrix[m][n]) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%g\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int row_of_zero(int m, int n, double matrix[m][n]) {
    for (int j = 0; j < n-1; j++) {
        if (matrix[m][j] != 0) return 0;
        
    }
    return 1;
}
