#!/bin/bash
LD_PRELOAD=$PWD/LDmitm.so ping www.google.com
