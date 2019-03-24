import tornado.web

from extern import hovertaxi_extern

class DemoController:
    class IndexHandler(tornado.web.RequestHandler):
        def get(self):
            self.write(hovertaxi_extern.demo())
