#!/bin/bash
gcc -shared -fPIC  main.c -o LDmitm.so -ldl
