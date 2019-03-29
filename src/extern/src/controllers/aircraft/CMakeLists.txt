set_source_files_properties(aircraft.pyx PROPERTIES CYTHON_IS_CXX TRUE)
cython_add_module(aircraft aircraft.pyx Aircraft.cpp ../../components/aircraft/Aircraft.cpp)
include_directories(.)