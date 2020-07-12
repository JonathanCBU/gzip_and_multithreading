#!/bin/bash

# gzip all 3 sample files
echo "Zipping 3 sample files. Will pause briefly if you wish to check the fie names for change."
gzip sample1.txt
gzip sample2.txt
gzip sample3.txt

# sleep briefly to see zipped files before decomp
sleep 5

# unzip all 3 sample files
echo "Decompressing 3 sample files"
gzip -d sample1.txt
gzip -d sample2.txt
gzip -d sample3.txt

# run main Cpp file where threads are split and run
echo "Compiling main.cpp using: g++ -std=c++11 -pthread -o main.exe main.cpp"
g++ -std=c++11 -pthread -o main.exe main.cpp

./main.exe

echo "Thanks for running! Change 'wait_between_threads' to false in my main.cpp file if you want to see true multithreading."