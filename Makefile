output: MainApp.o Jobs.o
	g++ -std=c++0x -Wall MainApp.o Jobs.o -o simulate

MainApp.o: MainApp.cpp
	g++ -c MainApp.cpp

Jobs.o: Jobs.cpp Jobs.h
	g++ -c Jobs.cpp
