cmake_minimum_required(VERSION 3.5.0)
project(xtac VERSION 0.1.0 LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
add_library(xtac SHARED src/list/list.c)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
