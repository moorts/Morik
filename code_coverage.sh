#!/bin/bash

if [ -e "./src/build" ]; then
	rm -r src/build
fi

mkdir src/build
cd src/build
cmake ..
make
ctest -D ExperimentalCoverage
