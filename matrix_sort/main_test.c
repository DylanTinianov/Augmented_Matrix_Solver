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
    double matrix1[5][6] = {
        {1, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 3},
        {0, 0, 0, 1, 0, 3},
        {0, 0, 0, 0, 1, 0},
    };
    
    // initialize solution array to all 0
    double sln[m][n];
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            sln[i][j] = 0;
        }
    }
    
    
    
    rref(m, n, matrix1);
    matrix_print(m, n, matrix1);
    printf("__________________\n");
    
    
    
    double *solution = get_solution(m, n, matrix1);
    if (solution != NULL) {
        for (int i= 0; i < m; i++){
            printf("%g\n", solution[i]);
        }
        free(solution);
    }
    else if (consistent(m, n, matrix1)) {
        // print infinite sln.
        get_infinite(m, n, matrix1, sln);
        matrix_print(m, n, sln);
    }
    else printf("NO SOLUTION");
    
    
    return 0;
}
