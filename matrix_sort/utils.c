#include <stdio.h>
#include "utils.h"


// Useful Functions
void matrix_print(int m, int n, double matrix[m][n]) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%g ", matrix[i][j]);
        }
        printf("\n");
    }
}
