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
        {9, 0, 9, 0, 0, 4},
        {9, 0, 9, 0, 0, 4},
        {7, 0, 3, 0, 3, 3},
        {0, 6, 0, 2, 6, 3},
        {9, 0, 9, 0, 0, 3},
    };
    
    rref(5, 6, matrix1);
    matrix_print(5, 6, matrix1);
    
    return 0;
}
