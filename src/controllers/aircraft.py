import tornado.web

from extern.wrappers.controllers.vehicle import vehicle


class AircraftController:
    class LoadInCircleHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(vehicle.loadVehicles())
