#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream> 
#include <cstdint>
#include <cmath>

#include "processor.h"

template <typename T>
class Normalization: public Processor<T>
{
	int threshold;
public:
	Normilizer(int threshold);
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

