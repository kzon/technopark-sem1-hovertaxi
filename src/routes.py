from controllers import *

routes = [
    (r"/", main.MainController.IndexHandler),

    (r"/api/order/preOrder", order.OrderController.PreOrderHandler),

    (r"/api/aircraft/loadInCircle", aircraft.AircraftController.LoadInCircleHandler),
    (r"/api/aircraft/loadAircraftClasses", aircraft.AircraftController.LoadAircraftClassesHandler),
]
