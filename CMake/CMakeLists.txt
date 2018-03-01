# CMake minimum version required
cmake_minimum_required (VERSION 2.6)

# Project name
# No whitespace
project (CMakeDemo)

set(HEADER_SEARCH_PATH C:/opencv3/build/include C:/some/other/search/path)
include_directories(${HEADER_SEARCH_PATH})

set(LIB_SEARCH_PATH C:/opencv3/build/x64/vc15/lib C:/some/other/search/path)
link_directories(${LIB_SEARCH_PATH})

set(LIBS opencv_world340d)
link_libraries(${LIBS})

# Executable name and source files
add_executable(cmake_demo cmake_demo.cpp)
