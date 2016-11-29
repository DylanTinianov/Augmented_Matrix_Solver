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

#define EPSILON 0.000000001


void rref(int m, int n, double* *matrix) {
    int start_row = 0;
    matrix_sort(m, n, matrix);
    
    for (int i=0; i < n-1; i++) {
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
    
    start_row = (m-1) - num_zero_rows;
    for (int j = start_row-1; j >= 0; j--) {
        for (int i=n-2; i > 0; i--) {
            for (int k = j; k >= 0; k--) {
                if (fabs(matrix[start_row][i]) > EPSILON) {
                double temp = matrix[k][i];
                scalar_mult_ero(m, n, matrix, start_row, matrix[k][i]);
                subtract_ero(m, n, matrix, start_row, k);
                scalar_mult_ero(m, n, matrix, start_row, 1.0/ temp);
                }

            }
        }
        start_row --;
    }
}

int consistent(int m, int n, double* *matrix) {
    // return 1 if consistent, else 0
    for (int i=0; i < m; i++) {
        if(row_of_zero(m, n, matrix, i)){
            if (fabs(matrix[i][n-1]) >= EPSILON) return 0;
        }
    }
    return 1;
}

int check_unique(int m, int n, double* *matrix){
    int num_count = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m; j++){
            if (i != j && fabs(matrix[j][i]) > EPSILON) return 0; 
            else if (fabs(matrix[j][i]) > EPSILON) num_count++;
        }
        if (num_count != 1) return 0;
        num_count = 0;
    }
    return 1;
}


int col_free(int m, int n, double* *matrix, int col) {
    for (int i=m-1; i >= 0; i--) {
        if (matrix[i][col]) {
            for (int j=col-1; j >= 0; j--) {
                if (matrix[i][j] > EPSILON) return 1;
            }

            for (int j=i-1; j >= 0; j--) {
                if (matrix[i][j] > EPSILON) return 1;
            }
        }
    }
    return 0;
}


void get_infinite(int m, int n, double* *matrix, double* *sln) {
    if (!consistent(m, n, matrix)) return;
    
    for (int j=n-1; j >= 0; j--) {
        if (col_free(m, n, matrix, j) || j == n-1) {
            for (int i=0; i < m; i++) {
                if (j == n-1) sln[i][j] = matrix[i][j];
                else sln[i][j] = -matrix[i][j];   
            }
            if (j != n-1) sln[j][j] = 1;
        }
    }
}

int get_solution(int m, int n, double* *matrix, double *solution) {
    if (consistent(m, n, matrix)){
        if (check_unique(m, n, matrix)){
            for (int i = 0; i < m; i++){
                solution[i] = matrix[i][n-1];
            }
            return 1;
        }
    }
    return 0;
}

