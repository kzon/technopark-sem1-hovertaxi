import uuid
from abc import ABC, abstractmethod
from typing import Dict, Optional, Awaitable
import tornado.web
import tornado.httputil
import models


class BaseJSONHandler(tornado.web.RequestHandler):
    def set_default_headers(self, *args, **kwargs):
        self.set_header("Content-Type", "application/json")


class BaseHandlerWithExternModule(BaseJSONHandler, ABC):
    def __init__(self, application, request: tornado.httputil.HTTPServerRequest, **kwargs):
        super().__init__(application, request, **kwargs)
        if 'user_id' not in self.cookies:
            user_id = str(uuid.uuid4())
            self.set_secure_cookie('user_id', user_id)
        else:
            user_id = self.get_secure_cookie('user_id').decode()
        self.extern_wrapper = self.get_extern_module().get_wrapper(models.Context(user_id))

    def data_received(self, chunk: bytes) -> Optional[Awaitable[None]]:
        pass

    @abstractmethod
    def get_extern_module(self):
        ...
