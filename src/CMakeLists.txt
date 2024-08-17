set(LIST_SOURCES list.c)

if(TARGET_GROUP STREQUAL test)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic ")
endif()

add_library(list STATIC ${LIST_SOURCES})

target_include_directories(list PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)