cmake_minimum_required(VERSION 3.28)
project(refalgo)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.4 # Use the latest stable tag or desired version
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(refalgo STATIC
    src/binary_search.cpp
    include/refalgo.hpp
    include/refalgo/list.hpp
    src/dec_to_bin.cpp
    src/bubble_sort.cpp
    src/insertion_sort.cpp
)

target_include_directories(refalgo PUBLIC include)

add_subdirectory(examples)
