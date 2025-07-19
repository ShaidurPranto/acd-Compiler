#!/bin/bash

lex 2105177.l
g++ lex.yy.c -o out -lfl
./out ./tests/input.txt