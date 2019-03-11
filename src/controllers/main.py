import tornado.web


class MainController:
    class IndexHandler(tornado.web.RequestHandler):
        def get(self):
            self.write("This is main controller")
