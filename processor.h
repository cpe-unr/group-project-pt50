#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

/**
 * This is the Processor class.
 */

class Processor {
public:
	/**
	 * Creates the processBuffer interface.
	 * @param buffer - ...
	 * @param bufferSize - ...	
	*/
	virtual void processBuffer(unsigned char* buffer, int bufferSize)=0;
};

#endif
