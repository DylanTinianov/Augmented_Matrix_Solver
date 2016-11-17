#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include "rref.h"

//B vecotr is always the last colum of the coefficeitn matrix
//So the matrix should always have 1 more column than there are rows

int main(void) {
    
    double matrix1[5][6] = {
        {1, 0, 0, 0, 0, 4},
        {0, 1, 0, 0, 0, 4},
        {0, 0, 1, 0, 0, 3},
        {0, 0, 0, 1, 0, 3},
        {0, 0, 0, 0, 1, 0},
    };
    
    rref(5, 6, matrix1);
    matrix_print(5, 6, matrix1);
    
    double *solution = get_solution(5, 6, matrix1);
    
    for (int i= 0; i < 5; i++){
        printf("%g\n", solution[i]);
    }
    free(solution);
    
    return 0;
}
