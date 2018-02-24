#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/bitspace.ico

convert ../../src/qt/res/icons/bitspace-16.png ../../src/qt/res/icons/bitspace-32.png ../../src/qt/res/icons/bitspace-48.png ${ICON_DST}
