from libcpp.string cimport string

cdef extern from "Aircraft.h" namespace "controllers":
    cdef cppclass Aircraft:
        @ staticmethod
        string LoadAircraftInCircle()

def load_aircraft_in_circle() -> str:
    return Aircraft.LoadAircraftInCircle().decode()
