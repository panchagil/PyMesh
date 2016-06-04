#!/usr/bin/env sh
set -e

cd build
make all_tests
cd ..

python -c "import pymesh; pymesh.test()"