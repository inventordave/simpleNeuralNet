# Makefile for NN

.PHONY: clean

all: nn

nn: nn.c
	gcc -g -DDEBUG -lm -O -o nn.exe  nn.c


clean:
	rm -f -nn.exe

