#include <omp.h>
#include <stdio.h>

int N;
static int steps;
double step;

int main (int count, char* cli[]) {
      steps = atoi(cli[2]); N = atoi(cli[1]);
      int i,j;
      //    double x;
      double pi, sum = 0.0, start,end;
      step = 1.0/(double) steps;
      for (j=1; j<= N; j++) {
            printf(" running on %d thread(s): ", j);
            omp_set_num_threads(j);
            sum = 0.0;
            double start = omp_get_wtime();

            //#pragma omp parallel for reduction(+:sum) private(x)
            #pragma omp parallel for reduction(+:sum)
            for (i=0; i < steps; i++) {
            double x;
            x = (i+0.5)*step;
            sum += 4.0 / (1.0+x*x);
            }
            pi = step * sum;
            end = omp_get_wtime() - start;
            printf("PI = %.16g computed in %.4g seconds\n", pi, end);
      }
}
