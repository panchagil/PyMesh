#!/usr/bin/env sh
set -e
set -x

# python dependencies
pip install --upgrade pip
pip install -r python/requirements.txt

# submodules
git submodule update --init --recursive
mkdir third_party/build
cd third_party/build
cmake ..
make -s
make install -s
cd ../..