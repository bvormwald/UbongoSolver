g++ -std=c++11 -Wall -fPIC -shared src/*.cpp `root-config --cflags --glibs` -I ./include -o libUbongoSolver.so
g++ -std=c++11 -Wall examples/main.C  `root-config --cflags --glibs` -I ./include -L . -lUbongoSolver -o main


