#!/bin/bash

IFS=$'\n\r'

rm actual_output.txt

for i in `cat input.txt`; do
    echo $i | xargs ./a.out >> actual_output.txt
done