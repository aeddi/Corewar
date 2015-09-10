#!/bin/zsh

for file in ./championships/**/**.s ./examples/*.s; do ../asm $file; done
for file in ./championships/**/**.cor ./examples/*.cor; do mv $file ./compilled/asm_ref

for file in ./championships/**/**.s ./examples/*.s; do ../../asm $file; done
for file in ./championships/**/**.cor ./examples/*.cor; do mv $file ./compilled/asm_gody

cd ./compilled/asm_gody
for file in *; do diff -s $file ../asm_ref/$file; done
