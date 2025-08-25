cmake_minimum_required(VERSION 3.29.0)

include(${CMAKE_PREFIX_PATH}/toolchain.cmake)
set(SOURCES "C:/Users/filippar/sharedVbox")

include_directories(${CMAKE_PREFIX_PATH})
include_directories(${SOURCES})
add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    # -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
    -Wno-missing-field-initializers
)

option(BUILD_TESTS "Enable building of tests" OFF)

find_package(comport)
find_package(logger)
find_package(common)
find_package(connected_execution)

set(BOOST_ROOT ${CMAKE_PREFIX_PATH}/boost)
set(BOOST_INCLUDEDIR ${BOOST_ROOT}/include)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/libs)

find_package(Boost 1.82 REQUIRED COMPONENTS fiber context)

if(Boost_FOUND)
    message(STATUS "Boost found!")
    message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found!")
endif()


set(FIBER_SOURCE_DIR ${BOOST_SOURCES}/libs/fiber)

# Укажите пути к заголовочным файлам и библиотекам
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

project(CONSOLE CXX)


set(GTest_ROOT ${CMAKE_PREFIX_PATH}/gtest)
find_package(GTest REQUIRED)


set(include_dest "console")
set(main_lib_dest "console/lib/console")

add_subdirectory(src/Console)

add_subdirectory(src/Test)


install(FILES console-config.cmake DESTINATION ${main_lib_dest})
install(EXPORT console DESTINATION ${main_lib_dest})

