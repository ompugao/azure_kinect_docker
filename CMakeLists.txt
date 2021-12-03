project(azure_kinect_sandbox)
cmake_minimum_required(VERSION 3.10)

# find k4a
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_LIST_DIR}/cmake)
unset(k4a_DIR CACHE)
set(K4A_LIBS k4a::k4a;k4a::k4arecord)
find_package(k4a 1.4.1 MODULE REQUIRED)

add_executable(check_intrinsics check_intrinsics.cpp)
target_link_libraries(check_intrinsics ${K4A_LIBS})

