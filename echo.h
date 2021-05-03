#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include <cstdint>
#include <cmath>

#include "processor.h"

using namespace std; 

/**
 * Template class for Echo.
 */


template <typename T>
class Echo : public Processor<T>
{
	int delay;
	//!< This determines the delay of the echo.

public:
	/**
	 * This function gives the audio file an echo...
	 * @param delay - this will pass in the delay length of the echo.
	*/
	Echo(int delay)

	/**
	 * ProcessBuffer is ....
	 * @param buffer - ...
	 * @param bufferSize - ...	
	*/
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
