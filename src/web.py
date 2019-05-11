from abc import ABC, abstractmethod
import http.cookies
from typing import Dict, Optional, Awaitable
import tornado.web
import tornado.httputil


class Context:
    def __init__(self, user_id: str):
        self.user_id = user_id


class BaseJSONHandler(tornado.web.RequestHandler):
    def set_default_headers(self, *args, **kwargs):
        self.set_header("Content-Type", "application/json")

    def options(self):
        pass


class BaseHandlerWithExternModule(BaseJSONHandler, ABC):
    def __init__(self, application, request: tornado.httputil.HTTPServerRequest, **kwargs):
        super().__init__(application, request, **kwargs)
        if 'user_id' not in self.cookies:
            self.set_secure_cookie('user_id', '234234')
        user_id = self.get_secure_cookie('user_id').decode()
        self.extern_wrapper = self.get_extern_module().get_wrapper(Context(user_id))

    def data_received(self, chunk: bytes) -> Optional[Awaitable[None]]:
        pass

    @abstractmethod
    def get_extern_module(self):
        ...
