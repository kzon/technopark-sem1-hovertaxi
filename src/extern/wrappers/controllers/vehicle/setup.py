from distutils.core import setup, Extension
from Cython.Build import cythonize

compile_args = ['-std=c++11']

vehicle_module = Extension(
    'vehicle',
    sources=['vehicle.pyx'],
    extra_compile_args=compile_args,
    language='c++',
)

setup(
    name='vehicle',
    packages=['vehicle'],
    ext_modules=cythonize(vehicle_module),
)
