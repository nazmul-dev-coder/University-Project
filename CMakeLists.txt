cmake_minimum_required(VERSION 3.10)
project(PCA_Assignment)

set(CMAKE_CXX_STANDARD 17)

# Add source files
set(SOURCES
    main.cpp
)

# Include directories for headers
include_directories(${PROJECT_SOURCE_DIR})

# Find Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# matplotlib-cpp (assumes it's cloned/copied inside the project folder)
include_directories(${PROJECT_SOURCE_DIR}/matplotlib-cpp)

# Python for matplotlib-cpp
find_package(Python3 COMPONENTS Interpreter NumPy REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})
link_directories(${Python3_LIBRARY_DIRS})

# Add executable
add_executable(PCA_Assignment ${SOURCES})

# Link Python libraries for matplotlib-cpp
target_link_libraries(PCA_Assignment Python3::Python Python3::NumPy)
