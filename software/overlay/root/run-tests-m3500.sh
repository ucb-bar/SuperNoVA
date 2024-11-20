#!/usr/bin/env bash

echo "*****************TEST RESULTS*************"
echo "========supernova_ra1_m3500========="
/root/slam/test_mt1_ra_m3500-linux
echo "========supernova_ra2_m3500========="
/root/slam/test_mt2_ra_m3500-linux
/root/slam/test_mt2_ra_m3500_2-linux
echo "========supernova_ra4_m3500========="
/root/slam/test_mt4_ra_m3500-linux
/root/slam/test_mt4_ra_m3500_2-linux
/root/slam/test_mt4_ra_m3500_3-linux

poweroff -f
