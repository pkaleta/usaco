#!/usr/bin/env bash

DIR="/home/insane/algo/usaco"

if [ $# -eq 2 ]; then
    SECTION_NAME="Section ${1}.0"
    SECTION_DIR=${DIR}"/"${SECTION_NAME}
    if [ ! -d SECTION_DIR ]; then
        mkdir "$SECTION_DIR";
    fi
else
    echo "Usage: $0 SECTION_NUMBER TASK_NAME";
    exit 1;
fi

