cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

#Project and executable
project(proj_cpp_algos_test)

#Set output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out")

#Private sources and headers
set(SOURCE_FILES_MAIN
    ./src/main.cpp)

set(SOURCE_FILES
    ./src/utils.cpp
	./src/binary_search.cpp
	./src/selection_sort.cpp
	./src/quicksort.cpp)
	
set(HEADER_FILES 
    ./inc/utils.h
    ./inc/binary_search.h
    ./inc/selection_sort.h
    ./inc/quicksort.h)

#Main executable
add_executable(algo_test 
    ${SOURCE_FILES_MAIN}
	${SOURCE_FILES}
	${HEADER_FILES})

target_include_directories(algo_test
    PRIVATE ./inc)

target_compile_features(algo_test
    PUBLIC
        cxx_std_17
)

#Test sources and headers
set(TEST_SOURCE_FILES
    ./test/src/doctest_main.cpp
    ./test/src/test_utils.cpp
    ./test/src/test_binary_search.cpp
    ./test/src/test_selection_sort.cpp
    ./test/src/test_quicksort.cpp)
	
set(TEST_HEADER_FILES 
    ./test/inc/doctest.h)

#Test runner executable
add_executable(algo_test_tests
	${TEST_SOURCE_FILES}
	${TEST_HEADER_FILES}
	${HEADER_FILES})

target_include_directories(algo_test_tests
    PRIVATE ./test/inc
	PRIVATE ./inc
    PRIVATE ./src)

target_compile_features(algo_test_tests
    PUBLIC
        cxx_std_17
)