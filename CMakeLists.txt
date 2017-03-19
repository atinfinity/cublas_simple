cmake_minimum_required(VERSION 2.8)
project(cublas_simple)

find_package(CUDA REQUIRED)
file(GLOB SOURCES "*.cpp" "*.c" "*.h" "*.hpp")

if(CUDA_FOUND)
	add_executable(cublas_simple ${SOURCES})
	include_directories(${CUDA_INCLUDE_DIRS})
	target_link_libraries(cublas_simple ${CUDA_LIBRARIES} ${CUDA_cublas_LIBRARY})
endif(CUDA_FOUND)
