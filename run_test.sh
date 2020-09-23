#!/bin/bash

IFS=$'\n'

for i in 'cat input.txt'; do
  echo "Szamok: $i, duplajuk:"
  echo "$i" | ./a.exe
done