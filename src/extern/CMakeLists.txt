cmake_minimum_required(VERSION 3.7)
project(hovertaxi)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake)

include_directories(src)

include(UseCython)
set(CYTHON_FLAGS ${CYTHON_FLAGS} -3)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)

# googletest
# Download and unpack googletest at configure time
configure_file(libs/CMakeLists.txt libs/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libs/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libs/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)


# Project sources
include(glob_sources)
add_headers_and_sources(hovertaxi src)
add_headers_and_sources(hovertaxi src/components)
add_headers_and_sources(hovertaxi src/controllers)
add_headers_and_sources(hovertaxi src/services)

# Test target
add_executable(hovertaxi_test ${hovertaxi_sources})
target_link_libraries(hovertaxi_test gtest_main)
add_test(NAME hovertaxi_test COMMAND hovertaxi_test)

# MongoDB drivers
include_directories(${LIBMONGOCXX_INCLUDE_DIRS})
include_directories(${LIBBSONCXX_INCLUDE_DIRS})
target_link_libraries(hovertaxi_test ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})

# Cython modules
add_subdirectory(src/controllers)