#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"


int main(void) {
    
    double matrix1[6][5] = {
        {0, 0, 9, 0, 0},
        {0, 1, 9, 4, 0},
        {1, 0, 1, 0, 4},
        {0, 0, 0, 2, 6},
        {0, 0, 0, 4, 9},
        {0, 3, 0, 4, 9}
    };
    
    matrix_sort(6, 5, matrix1);
    matrix_print(6, 5, matrix1);
    
    return 0;
}
