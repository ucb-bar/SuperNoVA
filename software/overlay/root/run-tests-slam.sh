#!/usr/bin/env bash

echo "*****************TEST RESULTS*************"
echo "========supernova_incremental1_cab7k========="
/root/slam/test_mt1_incremental_cab7k-linux
echo "========supernova_incremental2_cab7k========="
/root/slam/test_mt2_incremental_cab7k-linux
/root/slam/test_mt2_incremental_cab7k_2-linux
echo "========supernova_incremental4_cab7k========="
/root/slam/test_mt4_incremental_cab7k-linux
/root/slam/test_mt4_incremental_cab7k_2-linux
echo "========supernova_ra1_cab7k========="
/root/slam/test_mt1_ra_cab7k-linux
echo "========supernova_ra2_cab7k========="
/root/slam/test_mt2_ra_cab7k-linux
/root/slam/test_mt2_ra_cab7k_2-linux
echo "========supernova_ra4_cab7k========="
/root/slam/test_mt4_ra_cab7k-linux
/root/slam/test_mt4_ra_cab7k_2-linux

echo "========supernova_incremental1_m3500========="
/root/slam/test_mt1_incremental_m3500-linux
echo "========supernova_incremental2_m3500========="
/root/slam/test_mt2_incremental_m3500-linux
/root/slam/test_mt2_incremental_m3500_2-linux
/root/slam/test_mt2_incremental_m3500_3-linux
echo "========supernova_incremental4_m3500========="
/root/slam/test_mt4_incremental_m3500-linux
/root/slam/test_mt4_incremental_m3500_2-linux
echo "========supernova_ra1_m3500========="
/root/slam/test_mt1_ra_m3500-linux
echo "========supernova_ra2_m3500========="
/root/slam/test_mt2_ra_m3500-linux
/root/slam/test_mt2_ra_m3500_2-linux
echo "========supernova_ra4_m3500========="
/root/slam/test_mt4_ra_m3500-linux
/root/slam/test_mt4_ra_m3500_2-linux
/root/slam/test_mt4_ra_m3500_3-linux

echo "========supernova_incremental1_cab464========="
/root/slam/test_mt1_incremental_cab464-linux
echo "========supernova_incremental2_cab464========="
/root/slam/test_mt2_incremental_cab464-linux
echo "========supernova_incremental4_cab464========="
/root/slam/test_mt4_incremental_cab464-linux
echo "========supernova_ra1_cab464========="
/root/slam/test_mt1_ra_cab464-linux
echo "========supernova_ra2_cab464========="
/root/slam/test_mt2_ra_cab464-linux
/root/slam/test_mt2_ra_cab464_2-linux
echo "========supernova_ra4_cab464========="
/root/slam/test_mt4_ra_cab464-linux

echo "========supernova_incremental1_sphere========="
/root/slam/test_mt1_incremental_sphere-linux
echo "========supernova_incremental2_sphere========="
/root/slam/test_mt2_incremental_sphere-linux
/root/slam/test_mt2_incremental_sphere_2-linux
echo "========supernova_incremental4_sphere========="
/root/slam/test_mt4_incremental_sphere-linux
/root/slam/test_mt4_incremental_sphere_2-linux
/root/slam/test_mt4_incremental_sphere_3-linux
echo "========supernova_ra1_sphere========="
/root/slam/test_mt1_ra_sphere-linux
echo "========supernova_ra2_sphere========="
/root/slam/test_mt2_ra_sphere-linux
/root/slam/test_mt2_ra_sphere_2-linux
echo "========supernova_ra4_sphere========="
/root/slam/test_mt4_ra_sphere-linux

poweroff -f
