add_executable(porttest porttest.cpp)
add_executable(bustest bustest.cpp)
target_link_libraries(porttest kpvs)
target_link_libraries(bustest kpvs)
