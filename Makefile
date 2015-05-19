#!/bin/sh
CC=gcc
CFLAGS=`pkg-config --cflags --libs gtk+-2.0`

clear

if [ -f main.c ] ; then
	$CC main.c $CFLAGS -o Minesweeper
else
	cowsay "File main.c Not Found "
fi