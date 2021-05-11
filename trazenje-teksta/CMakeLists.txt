project(trazenje-teksta)

set(LIBSRCS "src/lib/boyer-moore.cpp")
set(EXESRCS "src/bin/main.cpp")

add_executable(main ${EXESRCS})

add_library(trazenje-teksta STATIC ${LIBSRCS})

target_link_libraries(main PRIVATE trazenje-teksta)
target_include_directories(main PRIVATE "${PROJECT_SOURCE_DIR}/src/include/")
