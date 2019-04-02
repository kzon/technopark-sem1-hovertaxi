import tornado.web

from extern import order

class OrderController:
    class GetOrderInfoHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(order.get_order_info('5'))
