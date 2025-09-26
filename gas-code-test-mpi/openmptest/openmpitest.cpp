// sanity check to make sure openmp works and takes the correct argument, i.e., omp_get_num_threads().
// 
// compile with:
// g++ -O3 -std=c++11 -fopenmp -o gastestopenmp openmpitest.cpp
// 
// Run with:
// 
// ./gastestopenmp <numthreads>

#include <omp.h>
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    int num_threads = 4;
    if (argc > 1) {
        num_threads = std::atoi(argv[1]);
    }

    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        #pragma omp critical
        {
            std::cerr << "Hello from thread " << tid
                      << " out of " << nthreads << std::endl;
        }
    }

    return 0;
}




