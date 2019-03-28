from libcpp.string cimport string

cdef extern from "../../../src/controllers/vehicle/Aircraft.cpp" namespace "controllers":
    cdef cppclass Aircraft:
        @ staticmethod
        string LoadVehicles()

def loadVehicles():
    return Aircraft.LoadAircraftInCircle()
