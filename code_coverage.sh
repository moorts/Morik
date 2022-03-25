#!/bin/bash

if [ ! -e "./src/build" ]; then
	mkdir src/build
fi

cd src/build
cmake ..
make
ctest -D ExperimentalCoverage
