#!/bin/bash

# Script is in repo/cicd directory

# Compile tests from tests.cpp
make

# Start the tests
./sentrim-tests
