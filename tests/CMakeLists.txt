project(tests)

add_executable(boyer-moore "src/boyer-moore.cpp")
target_link_libraries(boyer-moore PRIVATE trazenje-teksta criterion)

add_executable(bad-character-rule "src/bad-character-rule.cpp")
target_link_libraries(bad-character-rule PRIVATE trazenje-teksta criterion)

add_executable(bcr-table-creation "src/bcr-table-creation.cpp")
target_link_libraries(bcr-table-creation PRIVATE trazenje-teksta criterion)

add_test(NAME boyer-moore COMMAND boyer-moore)
add_test(NAME bad-character-rule COMMAND bad-character-rule)
add_test(NAME bcr-table-creation COMMAND bcr-table-creation)
