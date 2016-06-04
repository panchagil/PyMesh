#!/usr/bin/env sh
set -e

# build project
mkdir build
cd build
cmake ..
make
make tools

# install python
cd ..
./setup.py install