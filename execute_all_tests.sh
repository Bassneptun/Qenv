#!/bin/zsh

for exe in *test*; do
  echo $exe
  ./$exe
done
