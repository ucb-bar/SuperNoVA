#!/usr/bin/env bash

echo "*****************TEST RESULTS*************"
echo "========supernova_ra1_cab7k========="
/root/slam/test_mt1_ra_cab7k-linux
echo "========supernova_ra2_cab7k========="
/root/slam/test_mt2_ra_cab7k-linux
/root/slam/test_mt2_ra_cab7k_2-linux
echo "========supernova_ra4_cab7k========="
/root/slam/test_mt4_ra_cab7k-linux
/root/slam/test_mt4_ra_cab7k_1-linux
/root/slam/test_mt4_ra_cab7k_2-linux

poweroff -f
