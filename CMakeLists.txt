cmake_minimum_required(VERSION 3.15)
# 3.15: $ cmake --install .

# Set the project name and version
project(Canny VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20) # 98
set(CMAKE_CXX_STANDARD_REQUIRED True)
message(STATUS "Compiler used: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER_ID}")

# Add the main executable
add_executable(${PROJECT_NAME} main.cpp)


# # Config mode: CONFIG
# find_package(TensorX REQUIRED
#     PATHS "${CMAKE_SOURCE_DIR}/TensorX/build"
# )
# # Dependency links of other targets, be it static.a or shared.so linking libraries
# target_link_libraries(${PROJECT_NAME} PRIVATE TensorX::TensorX)
add_subdirectory(Tensor-library)
target_link_libraries(${PROJECT_NAME} PRIVATE TensorX)


find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})


# Include paths - add dirs to the list of paths to search for .h include files
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}")
