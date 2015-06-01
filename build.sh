#!/bin/bash

if (( $# < 1 ))
then
    echo -e "USAGE: $0 <source_file>\n Output file will be called exe and "
    exit 1;
fi

GTK_VERSION=3.0
PKG_CMD="pkg-config gtk+-${GTK_VERSION}"


gcc `${PKG_CMD} --cflags` "${1}" -o exe `${PKG_CMD} --libs`
