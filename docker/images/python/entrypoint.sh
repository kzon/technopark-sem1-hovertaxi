# Build Cython modules
mkdir -p /home/hovertaxi-build/cmake-build-debug
cd /home/hovertaxi-build/cmake-build-debug
git config --global user.name "Anton Kobzev"
git config --global user.email "anton.cobzew@yandex.ru"
cmake -DCMAKE_BUILD_TYPE=Debug /home/hovertaxi/src/extern

make aircraft_controller
mv src/controllers/aircraft/aircraft_controller.so /home/hovertaxi/src/extern/aircraft_controller.so

make order_controller
mv src/controllers/order/order_controller.so /home/hovertaxi/src/extern/order_controller.so


# Start server
cd /home/hovertaxi
python src/app.py