FROM alpine:3.19.1 AS build

RUN apk update && \
    apk add --no-cache \
        build-base=0.5-r3 \
        cmake=3.27.8-r0 \
        boost1.82-dev=1.82.0-r3 \
        zeromq-dev \
        cppzmq \
        protobuf-dev

WORKDIR /mmo_framework_game_node

COPY src/ ./src/
COPY CMakeLists.txt . 

WORKDIR /mmo_framework_game_node/build

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8


FROM alpine:3.19.1

RUN apk update && \
    apk add --no-cache \
    libstdc++=13.2.1_git20231014-r0 \
    boost1.82-program_options=1.82.0-r3\
    libzmq \
    cppzmq \
    protobuf
   

RUN addgroup -S shs && adduser -S shs -G shs
USER shs

COPY --chown=shs:shs --from=build \
    ./mmo_framework_game_node/build/mmo_framework_game_node \
    ./app/

EXPOSE 8555

ENTRYPOINT [ "./app/mmo_framework_game_node" ]