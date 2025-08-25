file(GLOB headers *.h)
file(GLOB sources *.cpp)


add_library(Page ${sources} ${headers})

target_link_libraries(Page PUBLIC Dialog)
target_link_libraries(Page PUBLIC common)

target_include_directories(Page PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:${include_dest}/Page>)
target_include_directories(Page PUBLIC  $<BUILD_INTERFACE:${CONSOLE_SOURCE_DIR}>/src/Console $<INSTALL_INTERFACE:${include_dest}>)


install(TARGETS Page EXPORT Page DESTINATION ${main_lib_dest})
install(FILES ${headers} DESTINATION ${include_dest}/Page)
