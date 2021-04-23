#include "echo.h"

using namespace std;

Echo::Echo(int delay):delay(delay){}

void Echo::processBuffer(unsigned char* buffer, int bufferSize)
{
	for(int i = delay; i < bufferSize; i++)
	{
		buffer[i] = buffer[i]/2+buffer[i-delay]/2;
	}
} 

