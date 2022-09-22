FROM ubuntu:22.04
RUN apt -y update && apt install -y g++ make binutils git \ 
    cmake libssl-dev libboost-system-dev libcurl4-openssl-dev zlib1g-dev
WORKDIR /usr/src/
RUN git clone https://github.com/reo7sp/tgbot-cpp && cd tgbot-cpp && rm -rf .git \
   && cmake . && make -j$(nproc) && make install && rm -rf /usr/src/tgbot-cpp/
#RUN git clone https://github.com/adeharo9/cpp-dotenv && cd cpp-dotenv && rm -rf .git \
#   && cmake . && make -j$(nproc) && make install && rm -rf /usr/src/cpp-dotenv
WORKDIR /usr/src/app
COPY . .
RUN cd src && cmake . && make -j$(nproc) && ls -a && cp mirrorbot /usr/src/app
CMD ./mirrorbot