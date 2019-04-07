from libcpp.string cimport string

cdef extern from "order_controller.h" namespace "hovertaxi":
    cdef cppclass OrderController:
        @ staticmethod
        string PreOrder()

def pre_order() -> str:
    return OrderController.PreOrder().decode()
