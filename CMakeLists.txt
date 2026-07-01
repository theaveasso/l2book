cmake_minimum_required(VERSION 3.23)

project(L2Book)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(L2B_BUILD_TESTS 	"Build the test suite" 	ON)
option(L2B_BUILD_BENCH 	"Build the benchmark" 	OFF)
option(L2B_SANITIZE 	"Enable ASan+UBSan"		OFF)

add_library(l2b src/order_book.cpp)
target_include_directories(l2b PUBLIC include)

target_compile_options(l2b PRIVATE -Wall -Wextra -Wpedantic)

if (L2B_SANITIZE)
	target_compile_options(l2b 	PUBLIC -fsanitize=address,undefined -g)
	target_link_options(l2b  	PUBLIC -fsanitize=address,undefined)
endif()

if (L2B_BUILD_TESTS)
	enable_testing()
	add_executable(tests tests/test_order_book.cpp)
	target_link_libraries(tests PRIVATE l2b)

	add_test(NAME unit COMMAND tests)
endif()

if (L2B_BUILD_BENCH)
endif()
