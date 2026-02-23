#!/bin/bash

# Script is in repo/cicd directory

# Create repo/usr/bin folder
mkdir -p ../usr/bin

# Go to repo/src and run Makefile there
make -C ../src
