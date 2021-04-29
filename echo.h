#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include <cstdint>
#include <cmath>

#include "processor.h"

using namespace std; 

template <typename T>
class Echo : public Processor<T>
{
	int delay;
public:
	Echo(int delay)
	void processBuffer(T* buffer, int bufferSize);
};

template <typename T> Echo <T>::Echo(int delay): threshold(delay){}
template <typename T> void Echo <T>::processBuffer(T* buffer, int bufferSize)
{
	for(int i = delay; i < bufferSize; i++)
	{
		buffer[i] = buffer[i]/2+buffer[i-delay]/2;
	}
}
#endif //ECHO_H
