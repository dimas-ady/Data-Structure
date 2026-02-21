#!/usr/bin/bash

AUTO_PATH='.automation'
OUTPUT=test

COMPILER=clang
SOURCE=$(cat "$AUTO_PATH/source")

compile() {
    echo "Compiling"
    $COMPILER $SOURCE -o $OUTPUT
    if [ $? -eq 0 ]; then
        echo "Compiling Success"
    else
        echo "Compiling Fail!"
        exit
    fi
}

run() {
    echo "Program Running..."
    ./$OUTPUT
}

compile
run