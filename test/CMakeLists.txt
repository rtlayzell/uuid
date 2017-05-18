cmake_minimum_required(VERSION 3.0)
project(uuid-test-runner)

include_directories("../include")

# Configure Catch library.
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})


file(GLOB_RECURSE SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Catch)