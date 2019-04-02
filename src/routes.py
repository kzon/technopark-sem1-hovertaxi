from controllers import *

routes = [
    (r"/", main.MainController.IndexHandler),

    (r"/order/getOrderInfo", order.OrderController.GetOrderInfoHandler),

    (r"/aircraft/loadInCircle", aircraft.AircraftController.LoadInCircleHandler),
    (r"/aircraft/loadAircraftClasses", aircraft.AircraftController.LoadAircraftClassesHandler),
]
