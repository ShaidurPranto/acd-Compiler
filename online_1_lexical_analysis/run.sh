#!/bin/bash

lex practice.l
g++ lex.yy.c -o out -lfl
./out ./tests/input.txt