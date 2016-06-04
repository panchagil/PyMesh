#!/usr/bin/env sh
set -e
set -x

# build project
mkdir -p build
cd build
cmake ..
make -s
make tools -s

# install python
cd ..
./setup.py install