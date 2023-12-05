#ifndef SHELL_SORT
#include "shell_sort.h"
#endif

#include <stdio.h>



int main(int argc, char** argv)
{
	int available_threads = omp_get_num_procs();
	printf("OpenMP: %d; Threads: %d\n", _OPENMP, available_threads);

	int count = 10, times = 1;
	unsigned int* arr;
	arr = (unsigned int*)malloc(sizeof(unsigned int) * count * times * available_threads);
	for (int i = 0; i < count * times * available_threads; ++i) rand_s(arr + i);

	for (int threads = 0; threads < available_threads; ++threads)
		for (int i = 0; i < times; ++i) {
			double duration = shell_sort(arr + (threads + i) * count, count, threads + 1);
			printf("%f\t", duration);
		}

	return 0;
}