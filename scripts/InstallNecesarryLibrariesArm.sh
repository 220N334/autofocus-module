#! /bin/sh
pushd ..
wget https://github.com/prepkg/opencv-raspberrypi/releases/latest/download/opencv_64.deb
sudo apt install -y ./opencv_64.deb
popd