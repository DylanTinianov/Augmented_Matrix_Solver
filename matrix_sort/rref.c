//RREF
//Make every coefficient below the current row to a zero
//Make each leading coefficient a 1 by dividing the row
//by first coefficient
//Subtract from the top row
//Repeat this until you reach the second last column

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"


void rref(int m, int n, double* *matrix) {
    int start_row = 0;
    matrix_sort(m, n, matrix);
    
    for (int i=0; i < n-1; i++) {
        //Add check if the number isnt zero ?
        
        //Upper Triagnular Matrix
        for (int j=start_row; j < m; j++){
            if (fabs(matrix[j][i]) != 0){
                scalar_mult_ero(m, n, matrix, j, 1.0 / matrix[j][i]);
            }
        }
        
        for (int j=start_row+1; j < m; j++){
            if (fabs(matrix[j][i]) != 0){
                subtract_ero(m, n, matrix, start_row, j);
            }
        }
        matrix_sort(m, n, matrix);
        start_row ++;
    }
    
    int num_zero_rows = 0;
    for (int i=0; i < m; i++) {
        num_zero_rows += row_of_zero(m, n, matrix, i);
    }
    
    
    // get main diagonal
    start_row = m-1-num_zero_rows;
    for (int i=n-2; i > 0; i--) {
        for (int j = start_row-1; j >= 0; j--) {
            if (fabs(matrix[j][i]) != 0) {
                double temp = matrix[j][i];
                scalar_mult_ero(m, n, matrix, start_row, matrix[j][i]);
                subtract_ero(m, n, matrix, start_row, j);
                scalar_mult_ero(m, n, matrix, start_row, 1.0/ temp);
            }
        }
        start_row --;
    }
}

int consistent(int m, int n, double* *matrix) {
    // return 1 if consistent, else 0
    for (int i=0; i < m; i++) {
        if(row_of_zero(m, n, matrix, i)){
            if (matrix[i][n-1] != fabs(0.0)) return 0;
        }
    }
    return 1;
}

int check_unique(int m, int n, double* *matrix){
    int num_count = 0;
    for (int i = 0; i < n-1; i++){
        
        for (int j = 0; j < m; j++){
            if (matrix[j][i] != 0) num_count++;
        }
        if (num_count != 1) return 0;
        
        num_count = 0;
    }
    return 1;
}


void get_infinite(int m, int n, double* *matrix, double* *sln) {
    int coef_count = 0;
    for (int j=0; j < n; j++) {
        for (int i=0; i < m; i++) {
            if (matrix[i][j] != 0) coef_count ++;
        }
        if (coef_count != 1 || j == n-1) {
            for (int i=0; i < m; i++) {
                sln[i][j] = matrix[i][j];
            }
            if (j != n-1) sln[j][j] = 1;
        }
        coef_count = 0;
    }
}

double* get_solution(int m, int n, double* *matrix) {
    // check for unique solution in square matrix (m == n-1)
        // Check that it's consistant
        // Check that only main diagonal has coefficients and = 1
    
    // Pull out solution
    
    
    if (consistent(m, n, matrix)){
        double *solution = malloc((n-1)*sizeof(double));
        assert(solution);
        
        if (check_unique(m, n, matrix)){
            for (int i = 0; i < m; i++){
                solution[i] = matrix[i][n-1];
            }
            return solution;
        }
    }
    return NULL;
}
