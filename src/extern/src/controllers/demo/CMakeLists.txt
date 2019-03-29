set_source_files_properties(demo.pyx PROPERTIES CYTHON_IS_CXX TRUE)
cython_add_module(demo demo.pyx Demo.cpp ../../components/demo/Demo.cpp)
include_directories(.)