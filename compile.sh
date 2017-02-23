#!/bin/sh

 ./basic  $1.bas > $1.asm   # your basic program creates $1.asm

if test -f $1.asm
then
  nasm -f elf $1.asm
  if test -f $1.o
  then
    ld -m elf_i386 $1.o  -o $1

  else
    echo "did not create $1 executable"
  fi

fi
