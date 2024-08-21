set(LIST_SOURCES list.c)
set(HTAB_SOURCES htab.c)

add_library(list STATIC ${LIST_SOURCES})
add_library(list_d SHARED ${LIST_SOURCES})

add_library(htab STATIC ${HTAB_SOURCES})
add_library(htab_d SHARED ${HTAB_SOURCES})

if(TARGET_GROUP STREQUAL test)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic ")
elseif(TARGET_GROUP STREQUAL production)

  install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/)

  install(TARGETS list
    LIBRARY DESTINATION lib/)

  install(TARGETS list_d
    LIBRARY DESTINATION lib/)

    install(TARGETS htab
    LIBRARY DESTINATION lib/)

  install(TARGETS htab_d
    LIBRARY DESTINATION lib/)

endif()


target_include_directories(list PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_include_directories(htab PUBLIC
  ${CMAKE_CURRENT_LIST_DIR})