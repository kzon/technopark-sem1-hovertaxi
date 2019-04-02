import tornado.web

from extern import aircraft


class AircraftController:
    class LoadInCircleHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(aircraft.load_aircraft_in_circle())

    class LoadAircraftClassesHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(aircraft.load_aircraft_classes())
