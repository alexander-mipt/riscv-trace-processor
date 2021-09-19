#!/bin/bash

RISCV_TOOLCHAIN=/opt/riscv
RISCV_GCC=`find $RISCV_TOOLCHAIN -type f -name riscv64-unknown-linux-gnu-gcc`

$RISCV_GCC -static $1
