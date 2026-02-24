#!/bin/bash

# Script is in repo/cicd directory

# Create deb-package with passed name
dpkg-deb --build ../$1
