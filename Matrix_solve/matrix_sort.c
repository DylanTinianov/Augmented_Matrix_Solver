// Matrix Sorting

#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"


int check_sorted(int m, int n, double* *matrix, int start_row, int col) {
    double prev_val = matrix[start_row][col];
    
    for (int i=start_row+1; i<m; i++) {
        if (matrix[i][col] <= prev_val) {
            prev_val = matrix[i][col];
        }
        else return 0;
    }
    return 1;
}

void implement_sort(int m, int n, double* *matrix, int start_row, int col) {
    double largest = matrix[start_row][col];
    double largest_index = start_row;
    
    for (int i=start_row+1; i<m; i++) {
        if (matrix[i][col] > largest) {
            largest_index = i;
            largest = matrix[i][col];
        }
    }
    if (start_row != largest_index) {
        row_swap_ero(m, n, matrix, start_row, largest_index);
    }
}

int num_ceofficients(int m, int n, double* *matrix, int start_row, int col) {
    int coef_count = 0;
    for (int i=start_row; i<m; i++) {
        if (matrix[i][col]) coef_count ++;
    }
    return coef_count;
}


void matrix_sort(int m, int n, double* *matrix) {
    int count = 0;
    int num_coef = 0;
    for (int j=0; j<n-1; j++) {
        num_coef += num_ceofficients(m, n, matrix, count, j);
        while (!check_sorted(m, n, matrix, count, j)) {
            implement_sort(m, n, matrix, count, j);
            count ++;
        }
        count = num_coef;
        if (count >= m) return;
    }
}
