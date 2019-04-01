add_headers_and_sources(hovertaxi_aircraft ../../../src/models)
add_headers_and_sources(hovertaxi_aircraft ../../../src/components)
add_headers_and_sources(hovertaxi_aircraft ../../../src/controllers)
add_headers_and_sources(hovertaxi_aircraft ../../../src/services)

cython_add_module(aircraft aircraft.pyx ${hovertaxi_aircraft_sources})
target_link_libraries(aircraft ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
include_directories(.)