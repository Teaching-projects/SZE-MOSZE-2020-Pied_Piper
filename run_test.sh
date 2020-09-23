#!/bin/bash

IFS=$'\n'

rm output.txt

for i in 'cat input.txt'; do
  echo "$i" | ./a.exe >> output.txt
done