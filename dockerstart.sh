#! /bin/sh
premake5 gmake
make
chmod +x bin/Debug-linux-/Sandbox/Sandbox
./bin/Debug-linux-/Sandbox/Sandbox
ls -lh