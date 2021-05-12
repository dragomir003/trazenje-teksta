project(tests)

add_executable(boyer-moore "src/boyer-moore.cpp")
target_link_libraries(boyer-moore PRIVATE trazenje-teksta criterion)

add_executable(knuth-morris-pratt "src/knuth-morris-pratt.cpp")
target_link_libraries(knuth-morris-pratt PRIVATE trazenje-teksta criterion)

add_executable(bad-character-rule "src/boyer-moore/bad-character-rule.cpp")
target_link_libraries(bad-character-rule PRIVATE trazenje-teksta criterion)

add_executable(bcr-table-creation "src/boyer-moore/bcr-table-creation.cpp")
target_link_libraries(bcr-table-creation PRIVATE trazenje-teksta criterion)

add_executable(gsr-table-creation "src/boyer-moore/gsr-table-creation.cpp")
target_link_libraries(gsr-table-creation PRIVATE trazenje-teksta criterion)

add_executable(good-suffix-rule "src/boyer-moore/good-suffix-rule.cpp")
target_link_libraries(good-suffix-rule PRIVATE trazenje-teksta criterion)

add_executable(kmp-table-creation "src/knuth-morris-pratt/kmp-table-creation.cpp")
target_link_libraries(kmp-table-creation PRIVATE trazenje-teksta criterion)
target_include_directories(kmp-table-creation PRIVATE "${PROJECT_SOURCE_DIR}/../trazenje-teksta/src/include/")

add_test(NAME boyer-moore        COMMAND boyer-moore)
add_test(NAME knuth-morris-pratt COMMAND knuth-morris-pratt)

add_test(NAME bad-character-rule COMMAND bad-character-rule)
add_test(NAME bcr-table-creation COMMAND bcr-table-creation)
add_test(NAME gsr-table-creation COMMAND gsr-table-creation)
add_test(NAME good-suffix-rule   COMMAND good-suffix-rule)

add_test(NAME kmp-table-creation COMMAND kmp-table-creation)