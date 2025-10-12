cmake_minimum_required(VERSION 3.16)
project(arlogix-calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(
  calculator
  main.cpp lib/fraction.cpp lib/fraction.hpp lib/string.cpp lib/string.hpp
  lib/calculator/arlogix_calculator.cpp lib/calculator/arlogix_calculator.hpp
  lib/ui/ui.cpp lib/ui/ui.hpp)

target_link_libraries(calculator PRIVATE Qt6::Widgets)
target_include_directories(calculator PRIVATE lib)

set_source_files_properties(lib/ui/ui.hpp PROPERTIES SKIP_AUTOUIC ON)

include(FetchContent)
FetchContent_Declare(catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                                GIT_TAG v3.4.0)
FetchContent_MakeAvailable(catch2)

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(run_tests ${TEST_SOURCES} lib/string.cpp
                                        lib/calculator/arlogix_calculator.cpp)
target_link_libraries(run_tests PRIVATE Qt6::Widgets Catch2::Catch2WithMain)
target_include_directories(run_tests PRIVATE lib)
