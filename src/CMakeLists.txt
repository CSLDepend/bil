include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB bil_src_files
    "serialization/*.cpp"
    "bitstream/*.cpp"
    "mappingdb/*.cpp"
    "deviceinfo/*.cpp"
    "packetprocessor/*.cpp"
    "cfgdecode/*.cpp"
    "correlation/*.cpp"
    "correlation/xdlextraction/*.cpp"
    "correlation/cfgextraction/*.cpp"
    "exception/*.cpp"
    "xdl/*.cpp"
    "xdl/parser/*.cpp"
    "xdl/model/*.cpp"
    "xdl/writer/*.cpp"
    "bitfile/*.cpp"
    "xdlrc/parser/*.cpp"
    "xdlrc/model/*.cpp"
    "xdlrc/util/*.cpp"
    "util/*.cpp"
    "configuration/*.cpp"
)

set_property(GLOBAL PROPERTY CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14")
add_library(bil SHARED ${bil_src_files})

install(TARGETS bil
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)
