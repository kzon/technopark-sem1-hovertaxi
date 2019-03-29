include(glob_sources)
add_headers_and_sources(hovertaxi_controllers .)
add_library(hovertaxi_controllers ${hovertaxi_controllers_headers} ${hovertaxi_controllers_sources})
target_include_directories(hovertaxi_controllers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(aircraft)
add_subdirectory(demo)