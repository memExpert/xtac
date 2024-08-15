cmake_minimum_required(VERSION 3.5.0)
project(xtac VERSION 0.1.0 LANGUAGES C)

set(TARGET_GROUP production CACHE STRING "Group to build")
include_directories(include)
add_subdirectory(src)

if(TARGET_GROUP STREQUAL production)
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
elseif(TARGET_GROUP  STREQUAL test)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(tests)
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()