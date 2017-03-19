#pragma once

#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <iostream>

static inline void ___cudaSafeCall(cudaError_t status, const char* file, const int line, const char* func)
{
	if (cudaSuccess != status)
	{
		std::cerr << "[CUDA] failure, " << cudaGetErrorString(status) << " (status = " << status << "), " << "in function " << func << ". file " << file << ", line " << line << std::endl;
	}
}

static inline void ___cublasSafeCall(cublasStatus_t status, const char* file, const int line, const char* func)
{
	if (CUBLAS_STATUS_SUCCESS != status)
	{
		std::cerr << "[cuBLAS] failure, (status = " << status << "), " << "in function " << func << ". file " << file << ", line " << line << std::endl;
	}
}

#if defined(__GNUC__)
#define cudaSafeCall(expr)    ___cudaSafeCall(expr, __FILE__, __LINE__, __func__)
#define cublasSafeCall(expr)  ___cublasSafeCall(expr, __FILE__, __LINE__, __func__)
#else
#define cudaSafeCall(expr)    ___cudaSafeCall(expr, __FILE__, __LINE__, __FUNCTION__)
#define cublasSafeCall(expr)  ___cublasSafeCall(expr, __FILE__, __LINE__, __FUNCTION__)
#endif
