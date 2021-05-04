// PT 50
// CS 202: Semester Project
// https://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file

/**
 * This is the Wav class.
*/

#ifndef WAV_H
#define WAV_H

#include <string>
#include <vector>

#include "wavheader.h"

class Wav{
protected:
    int bufferSize_data;
	//!< This variable .....
    unsigned char** buffers = NULL;
	//!< This variable .....
    std::vector <SubChunkData> metadata;
	//!< This variable .....
    wavHeader wave_Header;
	//!< This variable .....
    dataChunk data_Chunk;
	//!< This variable .....
    FMT fmt;
	//!< This variable .....
public:
    wavHeader getwavHeader();
	/**
	 * getBuffer....
	*/
    unsigned char *getBuffer(int);
	/**
	 * getBufferSize....
	*/
    int getBufferSize() const;
	/**
	 * getBitDepth....
	*/
    int getBitDepth();
	/**
	 * getNumChannels....
	*/
    int getNumChannels();
	/**
	 * Reads into the audio file.
	 * @param filename - the name of the audio file
	*/
    void readFile(const std::string &filename);
	/**
	 * Writes a new audio file.
	 * @param filename - the name of the audio file
	*/
    void writeFile(const std::string &outFilename);
	/**
	 * Prints out Metadata
	 * @param filename - the name of the audio file
	*/
    void printMetaData();
	
	/**
	 * Deconstructor of Wav class.
	*/
    ~Wav();
};

#endif //WAV_H
