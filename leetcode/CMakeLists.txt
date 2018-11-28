cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

include_directories(".")
include_directories("utils")

#001
add_executable(0001_ 001/two_sum.cpp)

#007
add_executable(0007_ 007/reverse_integer.cpp)

#009
add_executable(0009_ 009/palindrone_number.cpp)

#014
add_executable(0014_ 014/longest_common_prefix.cpp)


#067
add_executable(0067_ 067/add_binary.cpp)


#069
add_executable(0069_ 069/sqrt.cpp)


#112
add_executable(0112_ 112/path_sum.cpp)


#278
add_executable(0278_ 278/first_bad_version.cpp)

add_subdirectory(string)
add_subdirectory(array)
add_subdirectory(matrix)
add_subdirectory(dynamic_programming)
add_subdirectory(math)
add_subdirectory(link_list)