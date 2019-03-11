from distutils.core import setup, Extension
from Cython.Build import cythonize

compile_args = ['-std=c++11']

hovertaxi_extern_module = Extension(
    'hovertaxi_extern',
    sources=['hovertaxi_extern.pyx'],
    extra_compile_args=compile_args,
    language='c++'
)

setup(
    name='hovertaxi_extern',
    packages=['hovertaxi_extern'],
    ext_modules=cythonize(hovertaxi_extern_module)
)
