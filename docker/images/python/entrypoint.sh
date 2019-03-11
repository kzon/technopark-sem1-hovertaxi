cd /home/hovertaxi

cd src/extern
python setup.py build_ext --inplace
cd ../..

python src/app.py