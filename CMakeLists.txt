cmake_minimum_required(VERSION 3.2)
project(CIO)

# -----------------------------------------------------------------------------
# Set Variables
# 
set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "CIOt")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(CMAKE_C_FLAGS  "-Wall -fno-strict-aliasing")
 


# -----------------------------------------------------------------------------
# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})


# -----------------------------------------------------------------------------
# Create the final binary
# 
add_executable(${BIN_NAME} main.c "${PROJECT_SOURCE_DIR}/src/io.c")


# -----------------------------------------------------------------------------
# Build the Toml Parser Library
# 
set(CIO_LIB "CIO")

add_library(${CIO_LIB} STATIC
  "${SRC_DIR}/io.c"
)


# -----------------------------------------------------------------------------
# Link the libraries
# 
target_link_libraries(${BIN_NAME} ${CIO_LIB})

