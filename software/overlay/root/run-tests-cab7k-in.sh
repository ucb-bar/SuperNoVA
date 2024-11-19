#!/usr/bin/env bash

echo "*****************TEST RESULTS*************"
echo "========supernova_incremental1_cab7k========="
/root/slam/test_mt1_incremental_cab7k-linux
#/root/slam/test_mt1_incremental_cab7k_2-linux
echo "========supernova_incremental2_cab7k========="
/root/slam/test_mt2_incremental_cab7k-linux
#/root/slam/test_mt2_incremental_cab7k_2-linux
echo "========supernova_incremental4_cab7k========="
/root/slam/test_mt4_incremental_cab7k-linux
#/root/slam/test_mt4_incremental_cab7k_2-linux

poweroff -f
