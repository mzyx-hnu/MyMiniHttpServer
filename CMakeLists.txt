cmake_minimum_required(VERSION 3.0.0)
project(MyMiniHttpServer)
# add_definitions(-std=c++11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")

# include(CTest)
# enable_testing()

# 配置一个头文件来传递一些CMake设置到源代码
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )
 
# 添加Config.h的路径到头文件的搜索路径
include_directories("${PROJECT_BINARY_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)

# link_directories(/usr/local/lib)
add_executable(MyMiniHttpServer main.cpp)
target_link_libraries(MyMiniHttpServer src)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
