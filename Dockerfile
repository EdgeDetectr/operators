FROM gcc:latest

RUN apt-get update && apt-get install -y \
    wget \
    build-essential \
    libopencv-dev \
    libomp-dev \
    libssl-dev

RUN wget https://github.com/Kitware/CMake/releases/download/v3.30.6/cmake-3.30.6.tar.gz && \
    tar -xvzf cmake-3.30.6.tar.gz && \
    cd cmake-3.30.6 && \
    ./bootstrap && \
    make -j$(nproc) && \
    make install && \
    cd .. && \
    rm -rf cmake-3.30.6 cmake-3.30.6.tar.gz

WORKDIR /app

COPY . .
RUN rm -rf build && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make

CMD ["tail", "-f", "/dev/null"]