#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

class Processor {
public:
	virtual void processBuffer(unsigned char* buffer, int bufferSize)=0;
};

#endif
