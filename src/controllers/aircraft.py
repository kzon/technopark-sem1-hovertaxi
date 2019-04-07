import tornado.web

from extern import aircraft_controller


class AircraftController:
    class LoadInCircleHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(aircraft_controller.load_aircraft_in_circle())

    class LoadAircraftClassesHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(aircraft_controller.load_aircraft_classes())
