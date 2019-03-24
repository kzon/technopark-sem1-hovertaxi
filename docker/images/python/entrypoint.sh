# Compile Cython modules
cd /home/hovertaxi/src/extern/wrappers

cd controllers/vehicle
python setup.py build_ext --inplace
cd -


# Start server
cd /home/hovertaxi
python src/app.py