#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include "rref.h"

//B vecotr is always the last colum of the coefficeitn matrix
//So the matrix should always have 1 more column than there are rows

int main(void) {
    
    double matrix1[6][6] = {
        {9, 0, 9, 0, 0, 1},
        {8, 1, 9, 4, 0, 2},
        {7, 0, 1, 0, 4, 3},
        {0, 6, 0, 2, 6, 4},
        {0, 5, 0, 4, 9, 5},
        {0, 4, 0, 4, 9, 6}
    };
    
    rref(6, 6, matrix1);
    matrix_print(6, 6, matrix1);
    
    return 0;
}
