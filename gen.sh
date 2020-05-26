#!/bin/bash
blechc react.blc
mv blech/react.h .
mv blech/react.c .
rm -rf blech
case "$OSTYPE" in
  darwin*)	sed -i '' s/"blech\/react.h"/"react.h"/ react.c ;;
  *)	   	sed -i s/"blech\/react.h"/"react.h"/ react.c ;;
esac
