#include "normalization.h"

using namespace std; 

void Normalization::processBuffer(unsigned char* buffer, int bufferSize)
{
	for(int i = 0; i < bufferSize; i++)
	{
		if(buffer[i]<229)
		{
			buffer[i] = 229;
		}	
	}
}



