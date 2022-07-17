FROM ubuntu:latest

LABEL org.opencontainers.image.title="Morik"

RUN mkdir -p /usr/src/morik

COPY . /usr/src/morik

WORKDIR /usr/src/morik

RUN apt update && apt install -y sqlite3 libsqlite3-dev libcrypto++-dev cmake g++-11 g++

RUN ./run_tests.sh

WORKDIR /usr/src/morik/src/build

ENTRYPOINT [ "./src" ]
