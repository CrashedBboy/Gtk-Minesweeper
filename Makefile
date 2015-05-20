#!/bin/sh
CC=gcc
CFLAGS=`pkg-config --cflags --libs gtk+-2.0`
ENTRY=src/main.c

clear

if [ -f $ENTRY ] ; then
	$CC $ENTRY $CFLAGS -o Minesweeper
else
	cowsay "File main.c Not Found "
fi