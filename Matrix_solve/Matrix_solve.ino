#include <stdio.h>
#include <stdlib.h>
#include "eros.h"
#include "utils.h"
#include "matrix_sort.h"
#include "rref.h"

//B vecotr is always the last colum of the coefficeitn matrix
//So the matrix should always have 1 more column than there are rows

/*
double readInput(void) {
  double user_input;
  if (Serial.available() > 0) {
    user_input = double(Serial.read());
    //Serial.println(user_input);
  }
  return user_input;
}
*/

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


void setup() {
  Serial.begin(9600);
}


int run = 1;
void loop() {

  if (run) {
      int m = 5, n = 6;
      
      double* *matrix2 = (double**)malloc(sizeof(double*)*m);
      for (int i=0; i < m; i++) {
          matrix2[i] = (double*)calloc(n, sizeof(double));
      }
      
      double matrix_set[5][6] = {
          {1, 0, 0, 0, 0, 4},
          {0, 1, 0, 0, 0, 0},
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
      double* *sln = (double**)malloc(sizeof(double*)*m);
      for (int i=0; i < m; i++) {
          sln[i] = (double*)calloc(n, sizeof(double));
      }
      
      
      rref(m, n, matrix2);
      //matrix_print(m, n, matrix2);
      double *solution = (double*)malloc(sizeof(double)*(n-1));
      //assert(solution);

      int got_solution = get_solution(m, n, matrix2, solution);

      

      if (got_solution) {
          for (int i= 0; i < m; i++){
              //printf("%g\n", solution[i]);
              Serial.print("x"); Serial.print(i); Serial.print(" = ");
              Serial.println(solution[i]);
          }
          free(solution);
      }
      else if (consistent(m, n, matrix2)) {
          // print infinite sln.
          get_infinite(m, n, matrix2, sln);
          matrix_print(m, n, sln);
      }
      else Serial.println("NO SOLUTION");   //printf("NO SOLUTION");
  
      delete_matrix(m, matrix2);
      delete_matrix(m, sln);
      free(solution);
      
      run = 0;
  }  
 
}


