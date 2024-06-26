cmake_minimum_required(VERSION 3.18)
project(CityBuilder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_PROFILING "Enable Tracy Profiling" OFF)

enable_testing()

find_package(GTest CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
if(ENABLE_PROFILING)
  find_package(Tracy CONFIG REQUIRED)
endif(ENABLE_PROFILING)


add_subdirectory(core/)
add_subdirectory(api/)
add_subdirectory(game/)

file(COPY ${CMAKE_SOURCE_DIR}/ressources DESTINATION ${CMAKE_BINARY_DIR})

add_executable(main main.cc)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/external/FastNoiseLite)

target_link_libraries(main PRIVATE core api game sfml-system sfml-network sfml-graphics sfml-window sfml-audio)
