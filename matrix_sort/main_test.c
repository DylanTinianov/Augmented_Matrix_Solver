#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include "rref.h"

//B vecotr is always the last colum of the coefficeitn matrix
//So the matrix should always have 1 more column than there are rows

int main(void) {
    int m = 5, n = 6;
    
    double* *matrix2 = malloc(sizeof(double*)*m);
    for (int i=0; i < m; i++) {
        matrix2[i] = calloc(n, sizeof(double));
    }
    
    double matrix_set[4][4] = {
        {0, 1.0, 0.75, -1.77},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 3},
        {0, 0, 0, 1, 0, 3},
        {0, 0, 0, 0, 1, 0},
    };
    
    for (int i=0; i < m; i++) {
        for(int j=0; j < n; j++) {
            set_matrix(matrix2, i, j, matrix_set[i][j]);
        }
    }


    // initialize solution array to all 0
    
    double* *sln = malloc(sizeof(double*)*m);
    for (int i=0; i < m; i++) {
        sln[i] = calloc(n, sizeof(double));
    }
    
    
    rref(m, n, matrix2);
    matrix_print(m, n, matrix2);
    printf("__________________\n");
    
    
    
    double *solution = get_solution(m, n, matrix2);
    if (solution != NULL) {
        for (int i= 0; i < m; i++){
            printf("%g\n", solution[i]);
        }
        free(solution);
    }
    else if (consistent(m, n, matrix2)) {
        // print infinite sln.
        get_infinite(m, n, matrix2, sln);
        matrix_print(m, n, sln);
    }
    else printf("NO SOLUTION");

    
    return 0;

}
