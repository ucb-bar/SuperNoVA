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
./build.sh
cp -r build/* overlay/root/
cd $FSIMSW
#rm images/slam-tests*
#./marshal -v --workdir $RDIR build m3500-tests.json
#./marshal -v --workdir $RDIR install m3500-tests.json
./marshal -v --workdir $RDIR build cab7k-tests.json
./marshal -v --workdir $RDIR install cab7k-tests.json
#./marshal -v --workdir $RDIR build sphere-tests.json
#./marshal -v --workdir $RDIR install sphere-tests.json
#./marshal -v --workdir $RDIR build cab464-tests.json
#./marshal -v --workdir $RDIR install cab464-tests.json
#this is for spike
#./marshal -i -v --workdir $RDIR build gemmini-tests.json
cd $RDIR
