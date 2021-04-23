#ifndef ECHO_H
#define ECHO_H

#include <stdio.h>
#include <cstdint>
#include <cmath>

#include "Processor.h"

using namespace std; 

class Echo : public Processor
{
	int delay;
public:
	Echo(int delay)
	void processBuffer(unsigned char*buffer, int bufferSize);
};
#endif //ECHO_H
