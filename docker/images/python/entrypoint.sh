# Build Cython modules
cd /home/hovertaxi/src/extern
git config --global user.name "Anton Kobzev"
git config --global user.email "anton.cobzew@yandex.ru"
cmake .

make aircraft
mv src/controllers/aircraft/aircraft.so aircraft.so

make demo
mv src/controllers/demo/demo.so demo.so


# Start server
cd /home/hovertaxi
python src/app.py