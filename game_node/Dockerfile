FROM alpine:3.17.0 AS build

RUN apk update && \
    apk add --no-cache \
        build-base=0.5-r3 \
        cmake=3.24.4-r0 \
        boost1.80-dev=1.80.0-r3

WORKDIR /mmo_framework_game_node

COPY src/ ./src/
COPY CMakeLists.txt . 

WORKDIR /mmo_framework_game_node/build

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8


FROM alpine:3.17.0


RUN apk update && \
    apk add --no-cache \
    libstdc++=12.2.1_git20220924-r4 \
    boost1.80-program_options=1.80.0-r3

RUN addgroup -S shs && adduser -S shs -G shs
USER shs

COPY --chown=shs:shs --from=build \
    ./mmo_framework_game_node/build/mmo_framework_game_node \
    ./app/

ENTRYPOINT [ "./app/mmo_framework_game_node" ]