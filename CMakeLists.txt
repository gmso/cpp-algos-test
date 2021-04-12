cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

#Project and executable
project(proj_cpp_algos_test)

#Set output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out")

#Private sources and headers
set(SOURCE_FILES
    ./src/main.cpp
    ./src/utils.cpp
	./src/binary_search.cpp
	./src/selection_sort.cpp)
	
set(HEADER_FILES 
    ./inc/utils.h
    ./inc/binary_search.h
    ./inc/selection_sort.h)

#Main executable
add_executable(algo_test 
	${SOURCE_FILES}
	${HEADER_FILES})

target_include_directories(algo_test
    PRIVATE ./inc)

target_compile_features(algo_test
    PUBLIC
        cxx_std_17
)