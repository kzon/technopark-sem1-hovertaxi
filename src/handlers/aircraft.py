import web
from extern import aircraft
from helpers import comma_separated_to_float_tuple

import sys
import json

class BaseAircraftHandler(web.BaseHandlerWithExternModule):
    def get_extern_module(self):
        return aircraft


class LoadInCircleHandler(BaseAircraftHandler):
    def post(self):
        try:
            data = json.loads(self.request.body)
            center = tuple(data.get("center"))
            radius = int(data.get("radius"))
            self.write(self.extern_wrapper.load_aircraft_in_circle(center, radius))
        except Exception:
            sys.stderr.write(Exception)
    def options(self):
        pass
    def get(self):
        pass

class LoadCurrentOrderAircraftHandler(BaseAircraftHandler):
    def get(self):
        self.write(self.extern_wrapper.load_current_order_aircraft())


class LoadAircraftClassesHandler(BaseAircraftHandler):
    def get(self):
        self.write(self.extern_wrapper.load_aircraft_classes())


class LoadNearestPadsHandler(BaseAircraftHandler):
    def get(self):
        position = comma_separated_to_float_tuple(self.get_query_argument('position'))
        self.write(self.extern_wrapper.load_nearest_pads(position))
