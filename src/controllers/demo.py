import tornado.web

from extern import hovertaxi_extern


class DemoController:
    class IndexHandler(tornado.web.RequestHandler):
        def get(self):
            s = self.get_query_argument('s')
            self.write(hovertaxi_extern.extern_demo(s))
