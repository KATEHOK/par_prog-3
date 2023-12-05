#ifndef SHELL_SORT
#include "shell_sort.h"
#endif

double shell_sort(unsigned int* arr, int count, int threads)
{
	double start, end;
	start = omp_get_wtime();

	for (int d = count / 2; d > 0; d /= 2) {
		for (int i = d; i < count; i += d) {
			for (int j = i - d; j >= 0; j -= d) {
				if (arr[j] <= arr[j + d]) break;
				unsigned int tmp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = tmp;
			}
		}
	}

	end = omp_get_wtime();
	return end - start;
}
