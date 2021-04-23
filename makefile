main: noisegate.o processor.o echo.o normalization.o main.cpp
	g++ -o audio noisegate.o processor.o echo.o normalization.o main.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c noisegate.cpp

processor.o: processor.cpp processor.h
	g++ -c processor.cpp

echo.o: echo.cpp echo.h
	g++ -c echo.cpp
	
normalization.o: normalization.cpp normalization.h
	g++ -c normalization.cpp

clean:
	rm *.o
