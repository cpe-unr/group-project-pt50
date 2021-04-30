// PT 50
// CS 202: Semester Project
// https://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file

#ifndef WAV_H
#define WAV_H

#include <string>
#include <vector>

#include "wavheader.h"

class Wav{
protected:
    int bufferSize_data;
    unsigned char* buffer = NULL;
    std::vector <SubChunkData> metadata;
    wavHeader wave_Header;
    dataChunk data_Chunk;
    FMT fmt;
public:
    wavHeader getwavHeader();
    unsigned char *getBuffer();
    int getBufferSize();
    void readFile(const std::string &filename);
    void writeFile(const std::string &outFilename);
    ~Wav();
};

#endif //WAV_H
