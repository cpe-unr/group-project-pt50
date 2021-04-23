#ifndef NOISEGATE_H
#define NOISEGATE_H

#include <stdio.h>
#include <cstdint>
#include <cmath>

#include "Processor.h"

using namespace std; 

class noiseGate : public Processor
{
	int threshold;

public:
	Noisegate(int threshold);
	void processBuffer(unsigned char* buffer, int bufferSize);

};
#endif //NOISEGATE_H 

