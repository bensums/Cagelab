#!/bin/bash
d="$(dirname "$(realpath $0)")"
LD_LIBRARY_PATH="$d/3rd_party/libQGLViewer/QGLViewer/":"$d/3rd_party/fbxsdk/lib/gcc4/x64/release/" "$d/Cagelab2018"
