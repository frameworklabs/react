#!/bin/sh
blechc react.blc
mv blech/react.h .
mv blech/react.c .
rm -rf blech
sed -i '' s/"blech\/react.h"/"react.h"/ react.c
