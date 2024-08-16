set(SOURCES list.c)
add_library(list_a STATIC ${SOURCES} )

target_include_directories(list_a PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)