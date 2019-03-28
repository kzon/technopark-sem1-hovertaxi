from controllers import *

routes = [
    (r"/", main.MainController.IndexHandler),
    (r"/aircraft/loadInCircle", aircraft.AircraftController.LoadInCircleHandler),
]
