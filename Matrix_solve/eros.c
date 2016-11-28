#include "eros.h"


void addition_ero(int m, int n, double* *matrix, int add, int add_to) {
    for (int i=0; i < n; i++) {
        matrix[add_to][i] += matrix[add][i];
    }
}

void subtract_ero(int m, int n, double* *matrix, int sub, int sub_to) {
    for (int i=0; i < n; i++) {
        matrix[sub_to][i] -= matrix[sub][i];
    }
}


void scalar_mult_ero(int m, int n, double* *matrix, int row, double scalar) {
    for (int i=0; i < n; i++) {
        matrix[row][i] *= scalar;
    }
}

void row_swap_ero(int m, int n, double* *matrix, int row1, int row2) {
    if (row1 != row2) {
        double temp[n];
        for (int i=0; i<n; i++) {
            temp[i] = matrix[row1][i];
        }
        
        // Swap row1 with the temp (row2), and then change row2 to temp (row1)
        for (int i=0; i<n; i++) {
            matrix[row1][i] = matrix[row2][i];
            matrix[row2][i] = temp[i];
        }
    }
}

