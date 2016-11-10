#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"

//B vecotr is always the last colum of the coefficeitn matrix
//So the matrix should always have 1 more column than there are rows

int main(void) {
    
    double matrix1[6][6] = {
        {0, 0, 9, 0, 0, 1},
        {0, 1, 9, 4, 0, 2},
        {1, 0, 1, 0, 4, 3},
        {0, 0, 0, 2, 6, 4},
        {0, 0, 0, 4, 9, 5},
        {0, 3, 0, 4, 9, 6}
    };
    
    matrix_sort(6, 5, matrix1);
    matrix_print(6, 5, matrix1);
    
    return 0;
}
