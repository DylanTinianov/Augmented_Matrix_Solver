#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include "rref.h"


void matrix_print(int m, int n, double* *matrix) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            //printf("%g\t", matrix[i][j]);
            Serial.print(matrix[i][j]);
            Serial.print("  ");
        }
        //printf("\n");
        Serial.println("");
    }
}

void print_infinite(int m, int n, double* *matrix, int col) {
    int temp[n];
    int zero_col = 1;
    for (int j=0; j<m; j++) {
        temp[j] = matrix[j][col];
        if (temp[j]) zero_col = 0;
    }


    if (!zero_col) {
        int first_print = 1;
        int last_col = 0;
        for (int i=0; i < m; i++) {
            if (first_print) {
                if (col != n-1) {
                    Serial.print("x");
                    Serial.print(i);  
                }
                else { 
                    last_col = 1;
                }
                first_print = 0;
                Serial.print(" ( ");
            }
                
            
            Serial.print(temp[i]);
            Serial.print(" ");
        }
        Serial.print(") ");
        if (!last_col) Serial.print("+ ");
    }
}


void setup() {
  Serial.begin(9600);
}


double readInput(void) {
  double user_input = 0;
  while (1) {
    user_input = Serial.parseFloat();
    if (Serial.available() > 0) break;
  }
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
    
    Serial.println("Enter matrix values, and 'z' for 0");
    for (int i=0; i < m; i++) {
        for(int j=0; j < n; j++) {
            double user_input = 0;
            
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
    //assert(solution);

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
        for (int i=0; i < n; i++) {
            print_infinite(m, n, sln, i);
        }
Serial.println("");
matrix_print(m, n, matrix);
Serial.println("");
matrix_print(m, n, sln);
        
        delete_matrix(m, sln);
    }
    
    delete_matrix(m, matrix);
    free(solution);
}

