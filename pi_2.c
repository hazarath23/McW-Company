#include<stdio.h>
#include<time.h>
#include<omp.h>
static long num_steps=100000;
double step;
#define NUM_THREADS 2
int main()
{
  int i;double pi,sum=0.0;
  step=1.0/(double)num_steps;
  clock_t start_time = clock();
  double x;
  #pragma omp for 
  for(i=0;i<num_steps;i++)
  {
    x=(i+0.5)*step;
    sum+=(4.0/(1.0+x*x));
  }
  #pragma omp critical
  pi=sum*step;
  printf("%f\n",pi);
  clock_t end_time = clock();
  double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; 
  printf("Execution time: %f seconds\n", time_taken);
  return 0;
}