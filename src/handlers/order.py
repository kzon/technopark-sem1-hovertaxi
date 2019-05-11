import sys
import json
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
    def post(self):
        try:
            data = json.loads(self.request.body)
            from_pad_id = data.get('from_pad_id')
            to_pad_id = data.get('to_pad_id')
            aircraft_class_id = data.get('aircraft_class_id')
            self.write(self.extern_wrapper.create_order(from_pad_id, to_pad_id, aircraft_class_id))
        except Exception:
            sys.stderr.write(str(Exception))


class LoadCurrentOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.load_current_order())


class CancelOrderHandler(BaseOrderHandler):
    def get(self):
        self.write(self.extern_wrapper.cancel_order())
