#include <omp.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
int i=11;
      #pragma omp parallel
      {
            cout<<"Hi..I am "<<i++<<" thread "<<" -"<<(omp_get_thread_num())<<" of "<<omp_get_num_threads()<<'\n';
      }
      return 0;
}
