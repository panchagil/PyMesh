#!/usr/bin/env sh
set -e

brew update
brew outdated cmake || brew upgrade cmake
brew outdated cgal || brew upgrade cgal
brew install swig
brew install python