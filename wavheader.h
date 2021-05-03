// PT 50
// CS 202
// Purpose:

#ifndef WAVEHEADER_H
#define WAVEHEADER_H

/**
 * wavHeader....
 */
struct wavHeader{
    char riff_header[4]; //!<RIFF
    char wave_header[4]; //!<WAVE
    int wav_size; //!<total size of file in bytes - 8
};

/**
 * dataChucnk is....
 */
struct dataChunk{
    char fmt_header[4]; //!<DATA
    int fmt_chunk_size; //!<size of chunk in bytes
};

/**
 * FMT is ....
 */
struct FMT{
    int sample_rate; //!<sample rate
    int byte_rate; //!<byte rate
    short audio_format; //!<numeric id of audio format
    short num_channels; //!<number of audio channels
    short sample_alignment; //!<sample alignment
    short bit_depth; //!<bitdepth
};

/**
 * SubChunkData...
 */
struct SubChunkData: public dataChunk{
    char *buffer; //!<buffer...
};

#endif //WAVEHEADER_H

