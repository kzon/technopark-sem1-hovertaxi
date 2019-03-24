from libcpp.string cimport string

cdef extern from "../../../src/controllers/vehicle/Vehicle.cpp" namespace "controllers":
    cdef cppclass Vehicle:
        @ staticmethod
        string LoadVehicles()

def loadVehicles():
    return Vehicle.LoadVehicles()
