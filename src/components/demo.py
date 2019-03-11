from extern import hovertaxi_extern


class DemoComponent:
    @staticmethod
    def demo(s: str) -> str:
        return hovertaxi_extern.extern_demo(s)
