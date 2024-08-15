add_executable(test_create_base_exec
    test_LL_create_base.c
)

target_link_libraries(test_create_base_exec
    list_a
    Unity
)

add_test(test_create_base test_create_base_exec)
