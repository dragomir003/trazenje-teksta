cmake_minimum_required(VERSION 3.10)

project(trazenje-teksta)

include(CTest)

add_subdirectory(trazenje-teksta)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif ()

enable_testing()
