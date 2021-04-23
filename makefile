main: noisegate.o main.cpp
	g++ -o audio noisegate.o main.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c noisegate.cpp

clean:
	rm *.o
