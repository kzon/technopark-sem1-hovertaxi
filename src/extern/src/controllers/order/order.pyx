import models
from libcpp.string cimport string


cdef extern from "order_controller.h" namespace "hovertaxi":
    cdef cppclass Context:
        string user_id


cdef extern from "order_controller.h" namespace "hovertaxi":
    cdef cppclass OrderController:
        OrderController(Context & context) except +
        string GetPreOrderInfo(string & from_pad_id, string & to_pad_id, string & aircraft_class_id) except +
        string CreateOrder(string & from_pad_id, string & to_pad_id, string & aircraft_class_id) except +
        string ProcessOrders() except +
        string LoadCurrentOrder() except +
        string CancelOrder() except +


cdef class OrderControllerWrapper:
    cdef OrderController *controller

    def __cinit__(self, string user_id):
        cdef Context context
        context.user_id = user_id
        self.controller = new OrderController(context)

    def __dealloc__(self):
        del self.controller

    def get_pre_order_info(self, from_pad_id: str, to_pad_id: str, aircraft_class_id: str) -> str:
        return self.controller.GetPreOrderInfo(from_pad_id.encode(), to_pad_id.encode(), aircraft_class_id.encode()).decode()

    def create_order(self, from_pad_id: str, to_pad_id: str, aircraft_class_id: str) -> str:
        return self.controller.CreateOrder(from_pad_id.encode(), to_pad_id.encode(), aircraft_class_id.encode()).decode()

    def process_orders(self) -> str:
        return self.controller.ProcessOrders().decode()

    def load_current_order(self) -> str:
        return self.controller.LoadCurrentOrder().decode()

    def cancel_order(self) -> str:
        return self.controller.CancelOrder().decode()

def get_wrapper(context: models.Context) -> OrderControllerWrapper:
    return OrderControllerWrapper(context.user_id.encode())
