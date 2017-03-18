#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <iostream>
#include "utility.hpp"

int main(int argc, const char* argv[])
{
	cublasHandle_t handle;
	cublasSafeCall(cublasCreate(&handle));

	int version = 0;
	cublasSafeCall(cublasGetVersion(handle, &version));
	std::cout << "cuBLAS version = " << version << std::endl;

	cublasSafeCall(cublasDestroy(handle));

	return 0;
}
