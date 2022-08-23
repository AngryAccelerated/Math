
cmake_minimum_required (VERSION 3.8)


set(ALL_FILES)
file(GLOB_RECURSE ALL_FILES ./*.h ./*.cpp)

add_executable (Math "Math.cpp" ${ALL_FILES})

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(Math PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(Math PRIVATE benchmark::benchmark benchmark::benchmark_main)