import tornado.web

from extern import order


class OrderController:
    class PreOrderHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(order.pre_order())
