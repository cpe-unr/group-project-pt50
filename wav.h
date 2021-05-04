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
	//!< This variable is the buffer size
    unsigned char** buffers = NULL;
	//!< This variable is the buffer
    std::vector <SubChunkData> metadata;
	//!< This variable is the metadata
    wavHeader wave_Header;
	//!< This variable is a waveheader object
    dataChunk data_Chunk;
	//!< This variable datachunk object
    FMT fmt;
	//!< This variable is an fmt object
public:
	/**
	 * getwavHeader
	 */
    wavHeader getwavHeader();
	/**
	 * gets the buffer
	*/
    unsigned char *getBuffer(int);
	/**
	 * gets the buffer size
	*/
    int getBufferSize() const;
	/**
	 * gets bit depth
	*/
    int getBitDepth();
	/**
	 * get number of channels
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
