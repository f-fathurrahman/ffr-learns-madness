#!/bin/bash
basn=`basename $1 .cpp`

rm -vf $basn.x
mpicxx $1 `pkg-config --libs MADNESS` -o $basn.x
echo "Executable: $basn.x"
