FROM python:3.7.3

RUN apt-get update && apt-get install -y \
	cmake libssl-dev libsasl2-dev pkg-config

# Install mongo-c-driver
RUN wget https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
	tar xzf mongo-c-driver-1.13.0.tar.gz && \
	cd mongo-c-driver-1.13.0 && \
	mkdir cmake-build && \
	cd cmake-build && \
	cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
	make && make install

# Install mongo-cxx-driver
RUN curl -OL https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz && \
	tar -xzf r3.4.0.tar.gz && \
	cd mongo-cxx-driver-r3.4.0/build && \
	cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
	make && make install

## Install mangrove
#RUN git clone -b master https://github.com/mongodb-labs/mangrove && \
#	cd mangrove/build && \
#	PKG_CONFIG_PATH=/usr/local/lib/pkgconfig cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
#	make && make install

# Install Python packages
COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt

COPY entrypoint.sh /entrypoint.sh
ENTRYPOINT ["bash", "/entrypoint.sh"]