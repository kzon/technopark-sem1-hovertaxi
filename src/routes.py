from controllers import *

routes = [
    (r"/", main.MainController.IndexHandler),
    (r"/demo", demo.DemoController.IndexHandler),
]
