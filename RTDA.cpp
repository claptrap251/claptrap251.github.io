#include <iostream>
#include <omp.h>
#include <time.h>

clock_t stop, start= clock();
static long num_steps= 100000;
double step;
void main()
{    
    int i; double x, pi, sum=0.0;
    step = 1.0/(double)num_steps;
#pragma omp parallel for private(x) reduction(+:sum)
    for ( i=0; i< num_steps; i++)
    {
        x=(i+0.5)* step;
        sum=sum+4.0 / (1.0 + x*x);
    }
    pi = step*sum;
    stop=clock();
    std::cout<< "time = "<<stop<<" us\n";
    std::cout<< "pi = "<< pi<<std::endl; 
    getchar();
}