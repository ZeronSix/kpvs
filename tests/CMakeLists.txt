add_executable(porttest porttest.cpp)
add_executable(bustest bustest.cpp)
add_executable(terminaltest terminaltest.cpp)

target_link_libraries(porttest kpvs)
target_link_libraries(bustest kpvs)
target_link_libraries(terminaltest kpvs)
