#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <cstdint>
#include <cmath>

#include "Processor.h"

class Normalization: public Processor
{
public:
	void processBuffer(unsigned char* buffer, int bufferSize);
};

#endif //NORMALIZATION_H

