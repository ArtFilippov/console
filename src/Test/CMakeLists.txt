file(GLOB headers **.h)
file(GLOB sources *.cpp)


add_executable(console_test ${sources} ${headers})

target_link_libraries(console_test PUBLIC pthread)
target_link_libraries(console_test PUBLIC common)
target_link_libraries(console_test PUBLIC console)
target_link_libraries(console_test PUBLIC Boost::fiber Boost::context)
target_link_libraries(console_test PUBLIC GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

target_include_directories(console_test PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR} )
target_include_directories(console_test PUBLIC ${CONSOLE_SOURCE_DIR})