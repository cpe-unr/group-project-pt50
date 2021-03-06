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
	 * NoiseGate function Removes sound that is above a certain threshold
	 * @param threshold - the threshold of the audio file
	*/
	NoiseGate(int threshold);

	/**
	 * ProcessBuffer is gets the buffer and the bufferSize
	 * @param buffer - the audio file
	 * @param bufferSize - gets the size of the audio file, how many digits there are. 	
	*/
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

