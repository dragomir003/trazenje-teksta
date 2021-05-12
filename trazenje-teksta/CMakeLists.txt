project(trazenje-teksta)

set(
    LIBSRCS 
    "src/lib/boyer-moore.cpp"
    "src/lib/boyer-moore/bcr.cpp"
    "src/lib/boyer-moore/gsr.cpp"
    "src/lib/knuth-morris-pratt/kmp_table.cpp"
    "src/lib/knuth-morris-pratt.cpp"
)

set(EXESRCS "src/bin/main.cpp")

add_executable(main ${EXESRCS})

add_library(trazenje-teksta STATIC ${LIBSRCS})

target_link_libraries(main PRIVATE trazenje-teksta)
target_include_directories(main PRIVATE "${PROJECT_SOURCE_DIR}/src/include/")
