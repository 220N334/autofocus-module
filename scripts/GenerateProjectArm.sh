#! /bin/sh
pushd ..
chmod +x vendor/premake/arm/premake5
./vendor/premake/arm/premake5 gmake
make
popd