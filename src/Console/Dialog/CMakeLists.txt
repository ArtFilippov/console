file(GLOB headers *.h)
file(GLOB sources *.cpp)


add_library(Dialog ${sources} ${headers})

target_link_libraries(Dialog PUBLIC common)

target_include_directories(Dialog PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:${include_dest}/Dialog>)
target_include_directories(Dialog PUBLIC  $<BUILD_INTERFACE:${CONSOLE_SOURCE_DIR}>/src/Console $<INSTALL_INTERFACE:${include_dest}>)


install(TARGETS Dialog EXPORT Dialog DESTINATION ${main_lib_dest})
install(FILES ${headers} DESTINATION ${include_dest}/Dialog)
