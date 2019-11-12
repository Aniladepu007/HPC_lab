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
      double sum =0.0,x;

      for(i=1;i<=N;i++) {
//            double x;
            printf("running on %d thread(s): ",i);
            //cout<<"running on "<<i<<" threads!\t";
            omp_set_num_threads(i);
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
            double pi = sum*increment;
            e = clock();
            double end = omp_get_wtime() - start;
            printf("PI = %.16g computed in %.4g secs(Wall_clock).....%.4g secs(time.h)\n", pi, end, (double)(e-b)/CLOCKS_PER_SEC);
//            cout<<"Pi value is :  "<<pi<<" calculated in "<<end<<" secs"<<endl;
      }
}
