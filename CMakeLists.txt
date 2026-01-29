cmake_minimum_required(VERSION 3.14)

project(OctoConverter
        VERSION 1.0.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Build converters library
add_subdirectory(src/converters)

# Build CLI executable
add_executable(OctoConverter src/main.cpp)
target_link_libraries(OctoConverter PRIVATE converters)
set_target_properties(OctoConverter PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Build tests
add_subdirectory(test)
