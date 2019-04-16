import web
from extern import aircraft
from helpers import comma_separated_to_float_tuple


class BaseAircraftHandler(web.BaseHandlerWithExternModule):
    def get_extern_module(self):
        return aircraft


class LoadInCircleHandler(BaseAircraftHandler):
    def get(self):
        center = comma_separated_to_float_tuple(self.get_query_argument('center'))
        radius = int(self.get_query_argument('radius'))
        self.write(self.extern_wrapper.load_aircraft_in_circle(center, radius))


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
