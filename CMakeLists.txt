cmake_minimum_required(VERSION 3.15...4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
project(
  improved-fraction
  VERSION 0.5
  DESCRIPTION "A improved fraction class from my class"
  LANGUAGES CXX)

file(GLOB_RECURSE INL_FILES "${CMAKE_SOURCE_DIR}/lib/*.inl")
if(INL_FILES)
  add_library(inline_dummy OBJECT ${INL_FILES})
  set_target_properties(
    inline_dummy PROPERTIES EXCLUDE_FROM_ALL TRUE # não compila para o binário
                                                  # final
  )
endif()

add_executable(
  calculator
  main.cpp lib/fraction.cpp lib/fraction.hpp lib/string.cpp lib/string.hpp
  lib/calculator/arlogix_calculator.cpp lib/calculator/arlogix_calculator.hpp)
target_link_libraries(calculator PRIVATE inline_dummy)
target_include_directories(calculator PRIVATE lib)
# include(FetchContent)
#
# add_library(lib lib/fraction.cpp lib/fraction.hpp) add_executable(fraction
# main.cpp lib/fraction.cpp) FetchContent_Declare( catch2 GIT_REPOSITORY
# https://github.com/catchorg/Catch2.git GIT_TAG v3.4.0)
#
# FetchContent_MakeAvailable(catch2)

# file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp") add_executable(run_tests
# ${TEST_SOURCES} lib/fraction.cpp) target_link_libraries(run_tests PRIVATE
# Catch2::Catch2WithMain) target_include_directories(run_tests PRIVATE lib)
