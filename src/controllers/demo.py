import tornado.web

from components.demo import DemoComponent


class DemoController:
    class IndexHandler(tornado.web.RequestHandler):
        def get(self):
            s = self.get_query_argument('s')
            self.write(DemoComponent.demo(s))
