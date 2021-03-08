#!/bin/sh

name=$(find . -type f -name "*.sh")
basename=$(basename -s .sh $name)
echo "$basename"
