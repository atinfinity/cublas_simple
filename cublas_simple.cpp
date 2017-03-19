#include <cstdio>
#include <cstdlib>
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <iostream>
#include "utility.hpp"

#define M 6
#define N 5
#define IDX2C(i,j,ld) (((j)*(ld))+(i))

int main(int argc, const char* argv[])
{
	float* a = 0;
	a = (float*)malloc(M * N * sizeof (float));

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			a[IDX2C(i,j,M)] = i;
		}
	}

	float* devPtrA = 0;
	cudaSafeCall(cudaMalloc((void**)&devPtrA, M*N*sizeof(*a)));

	cublasHandle_t handle;
	cublasSafeCall(cublasCreate(&handle));
	cublasSafeCall(cublasSetMatrix(M, N, sizeof(*a), a, M, devPtrA, M));
	cublasSafeCall(cublasGetMatrix(M, N, sizeof(*a), devPtrA, M, a, M));
	cublasSafeCall(cublasDestroy(handle));

	cudaSafeCall(cudaFree(devPtrA));	
	free(a);

	return 0;
}
