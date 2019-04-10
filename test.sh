#!/bin/bash
LD_PRELOAD=$PWD/LDmitm.so cat /proc/self/cmdline
