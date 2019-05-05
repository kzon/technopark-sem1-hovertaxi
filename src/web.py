from abc import ABC, abstractmethod
import http.cookies
from typing import Dict, Optional, Awaitable
import tornado.web
import tornado.httputil


class Context:
    def __init__(self, cookies: Dict[str, http.cookies.Morsel]):
        if 'user_id' in cookies:
            self.user_id = cookies['user_id'].value
        else:
            self.user_id = ''


class BaseJSONHandler(tornado.web.RequestHandler):
    def set_default_headers(self, *args, **kwargs):
        self.set_header("Content-Type", "application/json")


class BaseHandlerWithExternModule(BaseJSONHandler, ABC):
    def __init__(self, application, request: tornado.httputil.HTTPServerRequest, **kwargs):
        super().__init__(application, request, **kwargs)
        self.extern_wrapper = self.get_extern_module().get_wrapper(Context(self.cookies))

    def data_received(self, chunk: bytes) -> Optional[Awaitable[None]]:
        pass

    @abstractmethod
    def get_extern_module(self):
        ...
