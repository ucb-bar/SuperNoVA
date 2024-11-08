#!/bin/bash

# This script will run on the host from the workload directory
# (e.g. workloads/example-fed) every time the workload
cat test_output.txtis built.
# It is recommended to call into something like a makefile because
# this script may be called multiple times.
echo "Building slam-rocc-tests benchmark"
RDIR=$(pwd)
FSIMSW=/scratch/seah/chipyard-supernova/software/firemarshal/
#cd gemmini-rocc-tests
#./build.sh
#cp -r build/* ../overlay/root/
cd $FSIMSW
rm images/slam-tests*
./marshal -v --workdir $RDIR build slam-tests.json
./marshal -v --workdir $RDIR install slam-tests.json
#this is for spike
#./marshal -i -v --workdir $RDIR build gemmini-tests.json
cd $RDIR
