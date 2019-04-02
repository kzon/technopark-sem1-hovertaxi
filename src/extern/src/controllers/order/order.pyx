from libcpp.string cimport string

cdef extern from "Order.h" namespace "controllers":
    cdef cppclass Order:
        @ staticmethod
        string GetOrderInfo(string order_id)

def get_order_info(order_id: str) -> str:
    return Order.GetOrderInfo(order_id.encode()).decode()
