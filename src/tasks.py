import threading
from extern import order
import models


def set_interval(func, sec):
    def func_wrapper():
        set_interval(func, sec)
        func()

    t = threading.Timer(sec, func_wrapper)
    t.start()
    return t


def setup_periodic_tasks():
    set_interval(process_orders, 5)


order_extern_wrapper = order.get_wrapper(models.Context(''))


def process_orders():
    return order_extern_wrapper.process_orders()
