import tornado.ioloop
import tornado.web
import tornado.locks
from tornado.options import define, options

import routes
import tasks

define("port", default=8888, help="run on the given port", type=int)


def make_app():
    return tornado.web.Application(routes.routes, cookie_secret='f2fc990265c712c49d51a18a32b39f0c')


def main():
    tasks.setup_periodic_tasks()
    tornado.options.parse_command_line()
    app = make_app()
    app.listen(options.port)
    tornado.ioloop.IOLoop.current().start()


if __name__ == "__main__":
    main()
