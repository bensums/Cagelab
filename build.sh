#!/bin/bash
set -e

if [ ! -d 3rd_party ]; then
        mkdir 3rd_party
fi
cd 3rd_party
if [ ! -d fbxsdk ]; then
        mkdir fbxsdk
        cd fbxsdk
        wget http://download.autodesk.com/us/fbx/2018/2018.1.1/fbx20181_1_fbxsdk_linux.tar.gz
        tar xzf fbx*.tar.gz
        # Install in current directory
        ./fbx20181_1_fbxsdk_linux .
        cd ..
fi
if [ ! -d libQGLViewer ]; then
        find . -type f -exec sed -i 's/QGLViewer/QGLViewer/g' {} +
        git clone --depth 1 --branch v2.6.4 https://github.com/GillesDebunne/libQGLViewer
        cd libQGLViewer
        qmake
        make
        cd ..
fi
if [ ! -d glm ]; then
        git clone https://github.com/g-truc/glm
fi
if [ ! -d eigen ]; then
        git clone https://gitlab.com/libeigen/eigen
fi
cd ..
qmake
make

