#!/usr/bin/env bash

echo "*****************TEST RESULTS*************"
echo "========supernova_ra1_cab464========="
/root/slam/test_mt1_ra_cab464-linux
/root/slam/test_mt1_ra_cab464_2-linux
echo "========supernova_ra2_cab464========="
/root/slam/test_mt2_ra_cab464-linux
/root/slam/test_mt2_ra_cab464_2-linux
echo "========supernova_ra4_cab464========="
/root/slam/test_mt4_ra_cab464-linux
/root/slam/test_mt4_ra_cab464_2-linux

poweroff -f
