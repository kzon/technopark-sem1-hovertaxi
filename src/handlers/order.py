import web
from extern import order


class BaseOrderHandler(web.BaseHandlerWithExternModule):
    def get_extern_module(self):
        return order


class PreOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.pre_order(
            self.get_query_argument('from_pad_id'),
            self.get_query_argument('to_pad_id'),
            self.get_query_argument('aircraft_class_id'),
        ))


class CreateOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.create_order(
            self.get_query_argument('from_pad_id'),
            self.get_query_argument('to_pad_id'),
            self.get_query_argument('aircraft_class_id'),
        ))


class GetOrderInfoHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.get_order_info())


class CancelOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.cancel_order())
