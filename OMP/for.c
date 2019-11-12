#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define SIZE 500
#define N 1000

int main() {
      clock_t c1,c2;
      c1 = clock();
      double f,s;
      f = omp_get_wtime();
      int i;
      int chunk;

      float a[N], b[N], c[N];

      for(int i=0; i<N;i++)
      a[i] = b[i] = i*1.0;

      chunk = SIZE;

      #pragma omp parallel for shared(a,b,c,chunk) private(i) schedule(dynamic,chunk)
      for(i=0;i<N;i++) {
            //for(int i=0; i<100000;i++);
      //      printf("%f ",c[i] = a[i] + b[i]);
      c[i] = a[i] + b[i];
      }

      c2 = clock();
      printf("\n%lf\n",(double)(c2-c1)/CLOCKS_PER_SEC);
      s = omp_get_wtime();
      printf("\n%lf\n",s-f);
      return 0;
}
