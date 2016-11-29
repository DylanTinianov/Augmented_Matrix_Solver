#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include "rref.h"

#define EPSILON 0.000000001


void matrix_print(int m, int n, double* *matrix) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            Serial.print(matrix[i][j], 5);
            Serial.print("  ");
        }
        Serial.println("");
    }
}

int print_infinite(int m, int n, double* *matrix, int col, int first_print) {
    double temp[n];
    int zero_col = 1;
    for (int j=0; j < m; j++) {
        temp[j] = matrix[j][col];
        if (temp[j]) zero_col = 0;
    }


    if (!zero_col) {
        int col_print = 0;
        int first_col = 1;
        
        if (!first_print) {
            Serial.print(" + "); 
        }
        
        if (col != n-1) {         
            Serial.print("x");
            Serial.print(col); 
        }
        Serial.print(" ( ");
        
        for (int i=0; i < m; i++) {   
            if (fabs(temp[i]) < EPSILON) temp[i] = fabs(temp[i]);      
            Serial.print(temp[i], 3);
            Serial.print(" ");
        }
        Serial.print(") ");
        return 0;// has printed
    }
    return 1;
}



void setup() {
    Serial.begin(9600);
}


double readInput(void) {
    double user_input = 0.0;
    while (Serial.available() == 0) {
    // pass
    }
    user_input = (Serial.readString()).toFloat();
    Serial.println(user_input);
    return user_input;
}

void loop() {
    int m = 0, n = 0;

    
    Serial.println("Augmented Matrix Solver");
    Serial.println("Enter the number of rows: ");
        m = (int)readInput();

    Serial.println("Enter the number of columns: ");
        n = (int)readInput();

    double* *matrix = (double**)malloc(sizeof(double*)*m);
    for (int i=0; i < m; i++) {
        matrix[i] = (double*)calloc(n, sizeof(double));
    }
    
    for (int i=0; i < m; i++) {
        for(int j=0; j < n; j++) {
            double user_input = 0.0;
            
            Serial.print("Row ");
            Serial.print(i);
            Serial.print(" Col ");
            Serial.print(j);
            Serial.println(": ");
            
            user_input = readInput();        
            set_matrix(matrix, i, j, user_input);
        }
    }

    Serial.println("Your augmented matrix:");
    matrix_print(m, n, matrix);
    Serial.println("");
    
    
    rref(m, n, matrix);
    double *solution = (double*)malloc(sizeof(double)*(n-1));

    int got_solution = get_solution(m, n, matrix, solution);

    
    if (!consistent(m, n, matrix)) Serial.println("NO SOLUTION");
    
    else if (got_solution) {
        for (int i= 0; i < n-1; i++) {
            Serial.print("x"); Serial.print(i); Serial.print(" = ");
            Serial.println(solution[i]);
        }
    }
    else {
        double* *sln = (double**)malloc(sizeof(double*)*m);
        for (int i=0; i < m; i++) {
            sln[i] = (double*)calloc(n, sizeof(double));
        }
      
        // print infinite sln.
        get_infinite(m, n, matrix, sln);

        int first_print = 1;
        for (int i= n-1; i >= 0; i--) {
            first_print = print_infinite(m, n, sln, i, first_print);
        }
        
        /* testing end matrix
        Serial.println("");
        matrix_print(m, n, matrix);
        Serial.println("");
        matrix_print(m, n, sln);
        */
        
        delete_matrix(m, sln);
    }
    
    delete_matrix(m, matrix);
    free(solution);   
}

