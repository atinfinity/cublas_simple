#pragma once

#include <cuda_runtime.h>
#include <cublas_v2.h>

static inline void ___cublasSafeCall(cublasStatus_t status, const char* file, const int line, const char* func)
{
	if (CUBLAS_STATUS_SUCCESS != status)
	{
		std::cerr << "[cuBLAS] failure, status = " << status << ", " << "in function " << func << ". file " << file << ", line " << line << std::endl;
	}
}

#if defined __GNUC__
#define cublasSafeCall(expr)  ___cublasSafeCall(expr, __FILE__, __LINE__, __func__)
#else
#define cublasSafeCall(expr)  ___cublasSafeCall(expr, __FILE__, __LINE__, __FUNCTION__)
#endif
