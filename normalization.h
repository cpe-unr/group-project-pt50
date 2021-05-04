#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream> 
#include <cstdint>
#include <cmath>

#include "processor.h"

/**
 * Template class for Normalization.
 */

template <typename T>
class Normalization: public Processor<T>
{
	int threshold;
	//!< This determines the threshold of the wav file...
public:

	/**
	 * The Normilizer function sets sounds above or below the threshold to be louder or quieter
	 * @param threshold - takes the user threshold for the max or min sound they want
 	*/
	Normilizer(int threshold);

	/**
	 * ProcessBuffer is gets the buffer and the buffer size
	 * @param buffer - is the audio file type (8 bit or 16 bit)
	 * @param bufferSize - how big the audio file is (how many bytes)	
	*/
	void processBuffer(T* buffer, int bufferSize);
};
template <typename T> Normilizer <T>::Normilizer(int threshold): threshold(threshold){}
template <typename T> void Normilizer <T>::processBuffer(T* buffer, int bufferSize)
{
	int max = 0;
	for(int i = 0; i<bufferSize; i++)
	{
		if(buffer[i]<max){
			buffer[i] = max;
		}
		if(buffer[i] == char)
		{
			buffer[i] * (255/max);
		}
		if(buffer[i] == short)
		{
			buffer[i] * (max/32767);
		}
		
	}
}


#endif //NORMALIZATION_H

