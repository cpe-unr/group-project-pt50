main: noisegate.o main.cpp
	g++ -o audio noisegate.o main.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c noisegate.cpp

processor.o: processor.cpp processor.h
	g++ -c processor.cpp

clean:
	rm *.o
