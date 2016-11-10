//RREF
//Make every coefficient below the current row to a zero
//Make each leading coefficient a 1 by dividing the row
//by first coefficient
//Subtract from the top row
//Repeat this until you reach the second last column

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"


void rref(int m, int n, double matrix[m][n]) {
    int start_row = 0;
    matrix_sort(m, n, matrix);
    
    for (int i=0; i < n-1; i++) {
        //Add check if the number isnt zero
        
        
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
}