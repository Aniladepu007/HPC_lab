#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#include <time.h>
#define ll long long
static int steps;
int N;

int32_t main(int count, char* cli[]) {
      N = atoi(cli[1]); steps = atoi(cli[2]);
      int i;
      double increment = 1.0/steps;
      double sum =0.0,x,pi=0.0,avg1=0.0,avg2=0.0;

      for(i=1;i<=100;i++) {
            //printf("running on %d thread(s): ",i);
            //cout<<"running on "<<i<<" threads!\t";
            omp_set_num_threads(4);
            clock_t b,e;
            b = clock();
            double start = omp_get_wtime();
            sum = 0.0;

            //#pragma omp parallel for reduction(+:sum) private(x)
            #pragma omp parallel for reduction(+:sum)
            for(ll j=0;j<steps;j++) {
                  double x;
                  x = (j + 0.5) * increment;
                  sum += 4.0 / (1.0+x*x);
            }
            pi += sum*increment;
            e = clock();
            avg2 += (e-b);
            double en = omp_get_wtime() - start;
            avg1 += en;
      }
      printf("PI = %.16g computed in %.4g secs(Wall_clock).....%.4g secs(time.h)\n", pi/N, avg1/N, (double)(avg2)/(N*CLOCKS_PER_SEC));
      //            cout<<"Pi value is :  "<<pi<<" calculated in "<<end<<" secs"<<endl;
}
