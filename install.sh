#!/bin/bash
cd src
make clean
make all
cd ../
make clean
make all
ln -s bin/TicTacToe TicTacToe