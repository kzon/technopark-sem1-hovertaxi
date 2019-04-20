# Build Cython modules
mkdir -p /home/hovertaxi-build/cmake-build-debug
cd /home/hovertaxi-build/cmake-build-debug
git config --global user.name "Anton Kobzev"
git config --global user.email "anton.cobzew@yandex.ru"
cmake -DCMAKE_BUILD_TYPE=Debug /home/hovertaxi/src/extern

make aircraft
mv src/controllers/aircraft/aircraft.so /home/hovertaxi/src/extern/aircraft.so

make order
mv src/controllers/order/order.so /home/hovertaxi/src/extern/order.so


# Start server
cd /home/hovertaxi
python src/app.py