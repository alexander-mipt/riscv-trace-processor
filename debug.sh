#!/bin/bash

RISCV_TOOLCHAIN=/opt/riscv
SPIKE=`find $RISCV_TOOLCHAIN -type f -name spike`
PK=`find $RISCV_TOOLCHAIN -type f -name pk`

$SPIKE -d $PK $1
