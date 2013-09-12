#include <stdlib.h>
#include <iostream>
#include <armadillo>
#include <math.h>
#include <time.h>
#include "lib.h"
using namespace std;
using namespace arma;

int main(int argc, char** argv)
  {
    int N = 1000;
    int i, j, k;
    double **A,  **B,  **C;
    clock_t t;
  mat D = randu<mat>(N,N);
  mat E = randu<mat>(N,N);
  mat F = randu<mat>(N,N);
  t = clock();
  F = D*E;
  t = clock() -t;
  fprintf(stdout, "Execution time armadillo: %f, N = %d\n",  (float) t/CLOCKS_PER_SEC, N);


  A = (double **) matrix(N, N, sizeof(double));
  B = (double **) matrix(N, N, sizeof(double));
  C = (double **) matrix(N, N, sizeof(double));

// Initialize array
for(i = 0; i < N; i++)
  for(j = 0; j < N; j++)  A[i][j] = rand();

  for(i = 0; i < N; i++)
     for(j = 0; j < N; j++)  B[i][j] = rand();

  for(i = 0; i < N; i++)
     for(j = 0; j < N; j++)  B[i][j] = rand();

  // Do a multiplication A=B*C

  t = clock();
for(i = 0; i < N; i++)
 for(j = 0; j < N; j++)
    for(k = 0; k < N; k++)
          A[i][j]+=B[i][k]*C[k][j];
t = clock() -t;
fprintf(stdout, "Execution time library: %f\n", (float) t/CLOCKS_PER_SEC);
//free_matrix((void) A);
//free_matrix((void) B);
//free_matrix((void)C);

return 0;


}
