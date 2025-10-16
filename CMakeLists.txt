set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(
  Qt6
  COMPONENTS Widgets
  REQUIRED)
cmake_minimum_required(VERSION 3.16)
project(arlogix-calculator)

file(GLOB_RECURSE INL_FILES "${CMAKE_SOURCE_DIR}/lib/structures/*.inl")
if(INL_FILES)
  add_library(inline_dummy OBJECT ${INL_FILES})
  set_target_properties(
    inline_dummy PROPERTIES EXCLUDE_FROM_ALL TRUE # não compila para o binário
                                                  # final
  )
endif()

add_executable(
  calculator
  main.cpp
  lib/string/string.cpp
  lib/string/string.hpp
  lib/calculator/arlogix_calculator.cpp
  lib/calculator/arlogix_calculator.hpp
  lib/lexer/lexer.cpp
  lib/lexer/lexer.hpp
  lib/lexer/token.hpp
  lib/shunting_yard/shunting_yard.cpp
  lib/shunting_yard/shunting_yard.hpp
  lib/ui/ui.cpp
  lib/ui/ui.hpp)
target_link_libraries(calculator PRIVATE inline_dummy)
target_include_directories(calculator PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(calculator PRIVATE Qt6::Widgets)
target_include_directories(calculator PRIVATE lib)

set_source_files_properties(lib/ui/ui.hpp PROPERTIES SKIP_AUTOUIC ON)

include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0)
FetchContent_MakeAvailable(catch2)
# FetchContent_MakeAvailable(raylib)

add_library(arlogix_ui lib/ui/ui.cpp)
# target_link_libraries(arlogix_ui PUBLIC raylib)

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(
  run_tests
  ${TEST_SOURCES}
  lib/string/string.cpp
  lib/string/string.hpp
  lib/calculator/arlogix_calculator.cpp
  lib/calculator/arlogix_calculator.hpp
  lib/lexer/lexer.cpp
  lib/lexer/lexer.hpp
  lib/lexer/token.hpp
  lib/shunting_yard/shunting_yard.cpp
  lib/shunting_yard/shunting_yard.hpp)
target_link_libraries(run_tests PRIVATE Qt6::Widgets Catch2::Catch2WithMain)
target_include_directories(run_tests PRIVATE lib)
