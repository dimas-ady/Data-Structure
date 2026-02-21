#!/usr/bin/bash

AUTO_PATH='.automation'
TEMP_FOLDER='.temp'
OUTPUT=test

COMPILER=clang
SOURCE=$(cat "$AUTO_PATH/source")

compile() {
    echo "Compiling"
    $COMPILER $SOURCE -o $TEMP_FOLDER/$OUTPUT
    if [ $? -eq 0 ]; then
        echo "Compiling Success"
    else
        echo "Compiling Fail!"
        exit
    fi
}

run() {
    echo "Program Running..."
    ./$TEMP_FOLDER/$OUTPUT
}

compile
run