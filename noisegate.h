#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>

#include "processor.h"

using namespace std; 

template <typename T>
class noiseGate : public Processor<T>
{
	int threshold;

public:
	NoiseGate(int threshold);
	void processBuffer(T* buffer, int bufferSize);

};
template <typename T> NoiseGate <T>::NoiseGate(int threshold): threshold(threshold){}
template <typename T> void NoiseGate <T>::processBuffer(T* buffer, int bufferSize)
{
	T zeroPoint;
	zeroPoint = std:numberic_limits<T>.max();
	for(int i = 0; i<bufferSize; i++)
	{
		if(buffer[i] == char)
		{
			if(buffer[i]<(zeroPoint+5) && (buffer[i] > (zeroPoint-5)))
			{
				buffer[i] = 128;
			}
		}
		if(buffer[i] == short)
		{
			if(buffer[i]<(zeroPoint+5) && (buffer[i] > (zeroPoint-5)))
			{
				buffer[i] = 32768;
			}
		}
		
	}
}

#endif //NOISEGATE_H 

