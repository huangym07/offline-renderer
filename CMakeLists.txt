cmake_minimum_required(VERSION 3.22.1)

project(offline-renderer)
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})

# message("PROJECT_ROOT_DIR: " ${PROJECT_ROOT_DIR})

configure_file(${PROJECT_ROOT_DIR}/cmake_configs/paths.h.in ${PROJECT_ROOT_DIR}/include/paths.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG       "-DDEBUG -g")
set(CMAKE_CXX_FLAGS_RELEASE     "-O3")
set(CMAKE_BUILD_TYPE "Debug")

file(GLOB_RECURSE   SRC_FILES     ${PROJECT_ROOT_DIR}/src/*.cpp)
file(GLOB_RECURSE   HEADER_FILES  ${PROJECT_ROOT_DIR}/include/*.h)

# message("SRC_FILES: "       "${SRC_FILES}")
# message("HEADER_FILES: "    "${HEADER_FILES}")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_ROOT_DIR}/include)
