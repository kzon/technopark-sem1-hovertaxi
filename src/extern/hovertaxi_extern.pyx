from libcpp.string cimport string

cdef extern from "src/hovertaxi.cpp":
    pass

cdef extern from "src/hovertaxi.h":
    string demo(string s)

def extern_demo(s):
    return demo(str.encode(s)).decode()
