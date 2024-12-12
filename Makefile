# Makefile for NN

.PHONY: clean

all: nn

nn: nn.c
	gcc -g -DDEBUG -lm -O0 nn.c	-o nn.exe

clean:
	rm -f nn.exe

