#!/bin/sh

OLD=$PWD
rm -rf /dev/shm/recpt1/recpt1-master/
mkdir -p /dev/shm/recpt1/recpt1-master/
cp -Rp recpt1 driver /dev/shm/recpt1/recpt1-master/
cd /dev/shm/recpt1/recpt1-master/recpt1/
make distclean
make clean
sh autogen.sh
./configure --enable-b25
make
objdump -S -l -d recpt1 > recpt1.txt
cd $OLD
cp /dev/shm/recpt1/recpt1-master/recpt1/recpt1.txt .
cp /dev/shm/recpt1/recpt1-master/recpt1/recpt1 .


