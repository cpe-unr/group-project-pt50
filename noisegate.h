#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>

#include "processor.h"
using namespace std;

/**
 * The template class for noise gate.
 */

template <typename T>
class noiseGate : public Processor<T>
{
	int threshold;
	//!< This variable determines the threshold of the gate.

public:
	/**
	 * NoiseGate function ....
	 * @param threshold - the threshold of the audio file
	*/
	NoiseGate(int threshold);

	/**
	 * ProcessBuffer is ....
	 * @param buffer - ...
	 * @param bufferSize - ...	
	*/
	void processBuffer(T* buffer, int bufferSize);

};
template <typename T> noiseGate <T>::NoiseGate(int threshold): threshold(threshold){}
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

