import tornado.web

from extern import order_controller


class OrderController:
    class PreOrderHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(order_controller.pre_order())
