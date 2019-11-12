#include <omp.h>
#include <stdio.h>

int main() {
      #pragma omp parallel
      //private(tnum)
      {
            int tnum, n;
            n = omp_get_num_threads();
            tnum = omp_get_thread_num();
            for(int i=0; i<1000000; i++);
            printf("I am thread ..... %d of %d\n",tnum,n);
      }
      return 0;
}
