cmake_minimum_required(VERSION 2.8)
project(cublas_simple)

find_package(CUDA REQUIRED)
file(GLOB SOURCES "*.cpp" "*.c" "*.h" "*.hpp")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native")
endif()

if(CUDA_FOUND)
	CUDA_INCLUDE_DIRECTORIES(${CUDA_INCLUDE_DIRS})
	include_directories(${CUDA_INCLUDE_DIRS})

	CUDA_ADD_EXECUTABLE(cublas_simple ${SOURCES})

	target_link_libraries(cublas_simple ${CUDA_LIBRARIES} ${CUDA_cublas_LIBRARY})
endif(CUDA_FOUND)
