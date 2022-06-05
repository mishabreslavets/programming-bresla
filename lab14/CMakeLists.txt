cmake_minimum_required(VERSION 3.10)
# set the project name
project(Lab)
add_library(LIB src/lib.c src/lib.h)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)
target_link_libraries(LIB PRIVATE m)
target_include_directories(LIB PUBLIC ${GLIB_INCLUDE_DIRS})
target_link_libraries(LIB PUBLIC ${GLIB_LDFLAGS})
add_executable(exec src/main.c)
target_link_libraries(exec LIB)
add_executable(testlib test/test.c)
target_link_libraries(testlib LIB)
target_include_directories(testlib PUBLIC src)
enable_testing()
add_test(FirstTest testlib -p /main)




