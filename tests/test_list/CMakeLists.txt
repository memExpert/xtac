add_executable(test_create_base
    test_LL_create_base.c
)

target_link_libraries(test_create_base
    list
    unity
)

add_executable(test_deln
    test_LL_deln.c
)

target_link_libraries(test_deln
    list
    unity
)
add_executable(test_free
    test_LL_free.c
)

target_link_libraries(test_free
    list
    unity
)
add_executable(test_getn
    test_LL_getn.c
)

target_link_libraries(test_getn
    list
    unity
)
add_executable(test_insn
    test_LL_insn.c
)

target_link_libraries(test_insn
    list
    unity
)
add_executable(test_popb
    test_LL_popb.c
)

target_link_libraries(test_popb
    list
    unity
)
add_executable(test_popf
    test_LL_popf.c
)

target_link_libraries(test_popf
    list
    unity
)
add_executable(test_pushb
    test_LL_pushb.c
)

target_link_libraries(test_pushb
    list
    unity
)
add_executable(test_pushf
    test_LL_pushf.c
)

target_link_libraries(test_pushf
    list
    unity
)







add_test(exec_test_create_base test_create_base)
add_test(exec_test_deln  test_deln)
add_test(exec_test_free  test_free)
add_test(exec_test_getn  test_getn)
add_test(exec_test_insn  test_insn)
add_test(exec_test_popb  test_popb)
add_test(exec_test_popf  test_popf)
add_test(exec_test_pushb test_pushb)
add_test(exec_test_pushf test_pushf)
