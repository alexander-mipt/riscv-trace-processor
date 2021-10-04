#!/bin/bash

RISCV_TOOLCHAIN=/opt/riscv
SPIKE=`find $RISCV_TOOLCHAIN -type f -name spike`
PK=`find $RISCV_TOOLCHAIN -type f -name pk`
NM=`find $RISCV_TOOLCHAIN -type f -name nm`
OBJDUMP=`find $RISCV_TOOLCHAIN -type f -name objdump`

if [[ ! $RISCV_TOOLCHAIN || ! $SPIKE || ! $PK || ! $NM ]]; then
    echo "wrong env"
    exit 1
fi

FILE="trace.txt"
FORMATTED="formatted_trace.txt"

if [[ $1 ]]; then
    echo simulation:
    $SPIKE -l --log=$FILE $PK $1
    echo generation objdump:
    $OBJDUMP -d $1 > obj
fi

echo formatting trace

if [ ! -f "$FILE" ]; then
    echo "no $FILE"
    exit 1
fi

if [ -f "$FORMATTED" ]; then
    rm $FORMATTED
fi

STR=`$NM -S a.out | grep "T main"`
if [[ ! $STR ]]; then
    echo "no symbols"
    exit 1
fi

read var1 var2 skip <<< $STR
printf -v var1 '%#x' "$((0x$var1))"
printf -v var2 '%#x' "$(($var1 + "0x$var2" - 4))"

START=`grep -n ${var1##0x} $FILE | cut -f1 -d:`
END=`grep -n ${var2##0x} $FILE | cut -f1 -d:`

#echo $START $END

sed -n "$START,${END}p" $FILE > tmp.txt

while read line; do
    # echo $line
    echo ${line##*: } | sed -r 's/ ([+-]) /\1/g' | sed -r 's/,//g' >> $FORMATTED #| sed -r 's/[\(\)]+/_/g'
done < tmp.txt

rm tmp.txt
# sed -r 's/ ([+-]) /\1/g'
