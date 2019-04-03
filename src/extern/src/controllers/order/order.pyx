from libcpp.string cimport string

cdef extern from "Order.h" namespace "controllers":
    cdef cppclass Order:
        @ staticmethod
        string PreOrder()

def pre_order() -> str:
    return Order.PreOrder().decode()
