from libcpp.string cimport string

cdef extern from "aircraft_controller.h" namespace "hovertaxi":
    cdef cppclass AircraftController:
        @ staticmethod
        string LoadAircraftInCircle()
        @ staticmethod
        string LoadAircraftClasses()

def load_aircraft_in_circle() -> str:
    return AircraftController.LoadAircraftInCircle().decode()

def load_aircraft_classes() -> str:
    return AircraftController.LoadAircraftClasses().decode()
