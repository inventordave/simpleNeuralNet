# Makefile for NN

.PHONY: clean

all: nn

nn: nn.c nn.h
  make -C ../gcollect/ gcd
  gcc -O0 -g -DDEBUG ../gcollect/gcd.o -o nn.exe  nn.c


clean:
  rm -f -nn.exe

