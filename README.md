# floodFillProject
This project consists of two parts; a flood fill algorithm that populates a dynamically allocated 2D array and a path finder that tracks the path from a starting position to an ending position.

These are the instructions for using my makefile to run my code:


1. Firstly, the makefile will create executables for all the .cpp files in this particular assignment, which
   include manne_rishabh_assn5.cpp, conga.cpp, and zombie.cpp

2. It will combine all of these executables and compile them jointly, into one specific executable called
   'exe'

3. After editing the code, run the 'make clean', command, which will provide the executable .o files for the
   aforementioned .cpp files. Then run 'make', which will compile all the files and their dependencies

4. Then the file named 'exe' is created and can finally be run using the './exe' command, which will run the
   main .cpp file and provide the results of the user interface(conga line)

   COMMANDS IN ORDER TO RUN EVERYTHING:
   1. make clean
   2. make
   3. ./exe
