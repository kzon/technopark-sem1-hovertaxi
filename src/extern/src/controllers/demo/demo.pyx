from libcpp.string cimport string

cdef extern from "Demo.h" namespace "controllers":
    cdef cppclass Demo:
        @ staticmethod
        string TestDemo()

def test_demo() -> str:
    return Demo.TestDemo().decode()
