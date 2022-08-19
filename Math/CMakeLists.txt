
cmake_minimum_required (VERSION 3.8)


set(ALL_FILES)
file(GLOB_RECURSE ALL_FILES ./*.h ./*.cpp)

add_executable (Math "Math.cpp" ${ALL_FILES})


set_property(TARGET Math PROPERTY CXX_STANDARD 20)