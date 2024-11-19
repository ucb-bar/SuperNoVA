#!/usr/bin/env bash

echo "*****************TEST RESULTS*************"
echo "========supernova_ra1_sphere========="
/root/slam/test_mt1_ra_sphere-linux
echo "========supernova_ra2_sphere========="
/root/slam/test_mt2_ra_sphere-linux
/root/slam/test_mt2_ra_sphere_2-linux
echo "========supernova_ra4_sphere========="
/root/slam/test_mt4_ra_sphere-linux

poweroff -f
