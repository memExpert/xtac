set(LIST_SOURCES list.c)

add_library(list STATIC ${LIST_SOURCES})
add_library(list_d SHARED ${LIST_SOURCES})


if(TARGET_GROUP STREQUAL test)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic ")
elseif(TARGET_GROUP STREQUAL production)

  install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/${PROJECT_NAME})

  install(TARGETS list
    LIBRARY DESTINATION lib/${PROJECT_NAME})

  install(TARGETS list_d
    LIBRARY DESTINATION lib/${PROJECT_NAME}/shared/)

endif()


target_include_directories(list PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)