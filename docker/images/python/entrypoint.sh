# Build Cython modules
cd /home/hovertaxi/src/extern
git config --global user.name "Anton Kobzev"
git config --global user.email "anton.cobzew@yandex.ru"
cmake .

# Start server
cd /home/hovertaxi
python src/app.py