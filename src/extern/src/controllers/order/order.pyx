import web
from libcpp.string cimport string


cdef extern from "../base/base_controller.h" namespace "hovertaxi":
    cdef cppclass Context:
        string user_id


cdef extern from "../base/base_controller.h" namespace "hovertaxi":
    cdef cppclass BaseController:
        pass


cdef extern from "order_controller.h" namespace "hovertaxi":
    cdef cppclass OrderController:
        OrderController(Context & context) except +
        string PreOrder(string & from_pad_id, string & to_pad_id, string & aircraft_class_id)
        string CreateOrder(string & from_pad_id, string & to_pad_id, string & aircraft_class_id)
        string GetOrderInfo()
        string CancelOrder()


cdef class OrderControllerWrapper:
    cdef OrderController *controller

    def __cinit__(self, string user_id):
        cdef Context context
        context.user_id = user_id
        self.controller = new OrderController(context)

    def __dealloc__(self):
        del self.controller

    def pre_order(self, from_pad_id: str, to_pad_id: str, aircraft_class_id: str) -> str:
        return self.controller.PreOrder(from_pad_id.encode(), to_pad_id.encode(), aircraft_class_id.encode()).decode()

    def create_order(self, from_pad_id: str, to_pad_id: str, aircraft_class_id: str) -> str:
        return self.controller.CreateOrder(from_pad_id.encode(), to_pad_id.encode(), aircraft_class_id.encode()).decode()

    def get_order_info(self) -> str:
        return self.controller.GetOrderInfo().decode()

    def cancel_order(self) -> str:
        return self.controller.CancelOrder().decode()

def get_wrapper(context: web.Context) -> OrderControllerWrapper:
    return OrderControllerWrapper(context.user_id.encode())
