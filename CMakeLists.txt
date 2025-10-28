cmake_minimum_required(VERSION 3.16)
project(
  arlogix-calculator
  VERSION 1.0
  DESCRIPTION "A calculator application using Qt6"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)

find_package(
  Qt6
  COMPONENTS Widgets
  REQUIRED)

file(GLOB_RECURSE INL_FILES "${CMAKE_SOURCE_DIR}/lib/structures/*.inl")
if(INL_FILES)
  add_library(inline_dummy OBJECT ${INL_FILES})
  set_target_properties(
    inline_dummy PROPERTIES EXCLUDE_FROM_ALL TRUE # não compila para o binário
                                                  # final
  )
endif()


add_library(arlogix_string lib/string/string.cpp)
target_include_directories(arlogix_string PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(arlogix_string PUBLIC arlogix_lexer)

add_library(arlogix_structures INTERFACE)
target_include_directories(arlogix_structures INTERFACE ${CMAKE_SOURCE_DIR}/lib)

add_library(arlogix_lexer lib/lexer/lexer.cpp)
target_include_directories(arlogix_lexer PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(arlogix_lexer PUBLIC arlogix_string)

add_library(arlogix_sy lib/shunting_yard/shunting_yard.cpp)
target_include_directories(arlogix_sy PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(arlogix_sy PUBLIC arlogix_lexer arlogix_structures)

add_library(arlogix_core lib/calculator/arlogix_calculator.cpp)
target_include_directories(arlogix_core PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(arlogix_core PUBLIC arlogix_string arlogix_sy arlogix_lexer arlogix_structures)

add_library(arlogix_ui lib/ui/ui.cpp lib/ui)
target_include_directories(arlogix_ui PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(arlogix_ui PUBLIC Qt6::Widgets arlogix_core)

add_executable(arlogix_calculator ${CMAKE_SOURCE_DIR}/main.cpp)
target_link_libraries(arlogix_calculator PRIVATE arlogix_ui)


include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0)
FetchContent_MakeAvailable(catch2)

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(
  run_tests
  ${TEST_SOURCES}
)
target_link_libraries(run_tests PRIVATE Catch2::Catch2WithMain arlogix_core)
