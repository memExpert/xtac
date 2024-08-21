add_executable(test_HT_create
    test_HT_create.c
)

target_link_libraries(test_HT_create
    htab
    unity
)

add_executable(test_HT_free
    test_HT_free.c
)

target_link_libraries(test_HT_free
    htab
    unity
)


add_test(exec_test_HT_create test_HT_create)
add_test(exec_HT_free  test_HT_free)