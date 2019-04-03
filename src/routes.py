from controllers import *

routes = [
    (r"/", main.MainController.IndexHandler),

    (r"/order/preOrder", order.OrderController.PreOrderHandler),

    (r"/aircraft/loadInCircle", aircraft.AircraftController.LoadInCircleHandler),
    (r"/aircraft/loadAircraftClasses", aircraft.AircraftController.LoadAircraftClassesHandler),
]
