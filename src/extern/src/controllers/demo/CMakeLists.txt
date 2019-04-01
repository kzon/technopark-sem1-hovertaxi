add_headers_and_sources(hovertaxi_demo ../../../src/models)
add_headers_and_sources(hovertaxi_demo ../../../src/components)
add_headers_and_sources(hovertaxi_demo ../../../src/controllers)
add_headers_and_sources(hovertaxi_demo ../../../src/services)

cython_add_module(demo demo.pyx ${hovertaxi_demo_sources})
target_link_libraries(demo ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
include_directories(.)