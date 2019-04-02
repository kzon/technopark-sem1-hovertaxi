from libcpp.string cimport string

cdef extern from "Aircraft.h" namespace "controllers":
    cdef cppclass Aircraft:
        @ staticmethod
        string LoadAircraftInCircle()
        @ staticmethod
        string LoadAircraftClasses()

def load_aircraft_in_circle() -> str:
    return Aircraft.LoadAircraftInCircle().decode()

def load_aircraft_classes() -> str:
    return Aircraft.LoadAircraftClasses().decode()
