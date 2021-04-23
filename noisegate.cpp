#include "noisegate.h"

Noisegate::Noisegate(int threshold): threshold(threshold){}

void Noisegate::processBuffer(unsigned char* buffer, int bufferSize)
{
	for(int i = 0; i<bufferSize; i++)
	{
		if(buffer[i] (128+5) && (buffer[i] > (128-5)))
			{
				buffer[i] = 128; 
			}
	}
}
