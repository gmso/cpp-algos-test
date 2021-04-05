cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

#Project and executable
project(proj-cpp-algos-test)

#Set output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out")

#Private sources and headers
set(SOURCE_FILES
    ./src/main.cpp
	./src/binary-search.cpp)

#Main executable
add_executable(cpp-algos-test 
	${SOURCE_FILES})

target_compile_features(cpp-algos-test
    PUBLIC
        cxx_std_17
)