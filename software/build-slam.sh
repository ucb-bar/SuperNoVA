#!/bin/bash

# This script will run on the host from the workload directory
# (e.g. workloads/example-fed) every time the workload
cat test_output.txtis built.
# It is recommended to call into something like a makefile because
# this script may be called multiple times.
echo "Building slam-rocc-tests benchmark"
RDIR=$(pwd)
FSIMSW=../../../software/firemarshal/
# using newly built binary
#./build.sh
#rm -rf build/slam/*
#cd build
#cp ../../slam/* build/slam/*
cp ../../ae-binary/*-linux build/slam/.
cp -r build/* overlay/root/
cd $FSIMSW
./marshal -v --workdir $RDIR build m3500-tests.json
./marshal -v --workdir $RDIR install m3500-tests.json
./marshal -v --workdir $RDIR build cab7k-tests.json
./marshal -v --workdir $RDIR install cab7k-tests.json
./marshal -v --workdir $RDIR build sphere-tests.json
./marshal -v --workdir $RDIR install sphere-tests.json
./marshal -v --workdir $RDIR build cab464-tests.json
./marshal -v --workdir $RDIR install cab464-tests.json
cd $RDIR
