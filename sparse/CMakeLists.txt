project(SparseSolver CXX CUDA)
cmake_minimum_required(VERSION 2.6)

add_definitions(-std=c++14)
find_package(CUDA REQUIRED)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(HYPRE_ROOT "/home/hpjeon/sw_local/hypre/2.18.2_bigint")
set(AMGX_ROOT "/home/hpjeon/sw_local/amgx")
set(CUDA_ROOT "/usr/local/cuda")
set(GTEST_HOME  /home/hpjeon/sw_local/gtest)
set(CMAKE_CXX_COMPILER "mpicxx")
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
enable_testing()
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -g -O0")  
else()
  set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -O2")  
endif()
#
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++11" )
include_directories(${CUDA_INCLUDE_DIRS})
#set(ALL_CUDA_LIBS ${CUDA_LIBRARIES} ${CUDA_cusparse_LIBRARY} ${CUDA_cublas_LIBRARY})
set(LIBS ${LIBS}) # ${ALL_CUDA_LIBS})
set(CUDA_SEPARABLE_COMPILATION OFF)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS})
add_subdirectory(src/cpu)
add_subdirectory(src/gpu)
add_subdirectory(src/main)
# Ref: https://stackoverflow.com/questions/6352123/multiple-directories-under-cmake
#https://gitlab.com/CLIUtils/modern-cmake/tree/master/examples/extended-project
# data file copy
file(COPY ${CMAKE_SOURCE_DIR}/data/simple.mtx ${CMAKE_SOURCE_DIR}/data/simple.mtx
     DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/data/685_bus.mtx ${CMAKE_SOURCE_DIR}/data/1138_bus.mtx
     DESTINATION ${CMAKE_BINARY_DIR})
     