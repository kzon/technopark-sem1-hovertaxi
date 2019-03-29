include(glob_sources)
add_headers_and_sources(hovertaxi_components .)
add_library(hovertaxi_components ${hovertaxi_components_headers} ${hovertaxi_components_sources})
target_include_directories(hovertaxi_components PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})