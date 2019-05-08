import web
from extern import order


class BaseOrderHandler(web.BaseHandlerWithExternModule):
    def get_extern_module(self):
        return order


class GetPreOrderInfoHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.get_pre_order_info(
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


class LoadCurrentOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.load_current_order())


class CancelOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.cancel_order())
