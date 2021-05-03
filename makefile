main: noisegate.o processor.o echo.o normalization.o main.cpp
	g++ -o audio noisegate.o processor.o echo.o normalization.o main.cpp

noisegate.o: noisegate.h
	g++ -c noisegate.h

processor.o: processor.h
	g++ -c processor.h

echo.o: echo.h
	g++ -c echo.h
	
normalization.o: normalization.h
	g++ -c normalization.h

clean:
	rm *.o
