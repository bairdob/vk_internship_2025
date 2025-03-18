cmake_minimum_required(VERSION 3.10)
project(vk_internship)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(graph_app src/main.cpp src/graph.cpp src/utils.cpp)

add_custom_target(copy_data ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data ${CMAKE_BINARY_DIR}
)

add_dependencies(graph_app copy_data)
