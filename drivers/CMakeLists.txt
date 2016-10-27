include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB bit2xml_src
    "application/bit2xml/*.cpp"
)
add_executable(bit2xml ${bit2xml_src})
target_link_libraries(bit2xml bil)
add_dependencies(bit2xml bil)

file(GLOB bitextract_src
    "application/bitextract/*.cpp"
    )
add_executable(bitextract ${bitextract_src})
target_link_libraries(bitextract bil)
add_dependencies(bitextract bil)

file(GLOB bitreverse_src
    "application/bitreverse/*.cpp"
    )
add_executable(bitreverse ${bitreverse_src})
target_link_libraries(bitreverse bil)
add_dependencies(bitreverse bil)

install(TARGETS bit2xml bitextract bitreverse
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)
