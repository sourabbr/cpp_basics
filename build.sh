#! /bin/bash

folder=$1

mkdir ${folder}/bin
g++ -I -Wall ${folder}/src/*.cpp -o ${folder}/bin/output.exe