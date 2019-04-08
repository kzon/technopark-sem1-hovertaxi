add_headers_and_sources(hovertaxi_order ../../../src/models)
add_headers_and_sources(hovertaxi_order ../../../src/components)
add_headers_and_sources(hovertaxi_order ../../../src/controllers)
add_headers_and_sources(hovertaxi_order ../../../src/services)

cython_add_module(order_controller order_controller.pyx ${hovertaxi_order_sources})
target_link_libraries(order_controller ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
include_directories(.)
