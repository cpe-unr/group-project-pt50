// PT 50
// CS 202: Semester Project
// https://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file

#include <iostream>
#include <string>
#include <fstream>

#include "wav.h"

wavHeader Wav::getwavHeader(){
    return wave_Header;
}

unsigned char *Wav::getBuffer(int i){
    return buffers[i];
}

int Wav::getBufferSize() const{
    return bufferSize_data;
}

int Wav::getBitDepth(){
    return fmt.bit_depth;
}

int Wav::getNumChannels(){
    return fmt.num_channels;
}

void Wav::readFile(const std::string &fileName){
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&wave_Header, sizeof(wavHeader));

        if (wave_Header.wav_size > 0) {
            file.read((char*)&data_Chunk, sizeof(dataChunk));
        }

        file.read((char*)&fmt, sizeof(FMT));

        dataChunk chunk;
        while (true) {
            file.read((char*)&chunk, sizeof(dataChunk));
            if (chunk.fmt_header[0] == 'd' && chunk.fmt_header[1] == 'a' && chunk.fmt_header[2] == 't' && chunk.fmt_header[3] == 'a') break;
            file.seekg(chunk.fmt_chunk_size, std::ios::cur);
        }

        buffers = new unsigned char * [fmt.num_channels];
        bufferSize_data = chunk.fmt_chunk_size;
        int bytes_per_sample = fmt.bit_depth / 8;
        for (int i = 0; i < fmt.num_channels; i++) {
            buffers[i] = new unsigned char[bufferSize_data / fmt.num_channels];
        }
        
        for (int i = 0; i < bufferSize_data; i++) {
            file.read((char *) &buffers[i / bytes_per_sample % fmt.num_channels][i / fmt.num_channels], 1);
        }
    }
    file.close();
    std::cout << "RIFF HEADER: " << wave_Header.riff_header << "\n";
    std::cout << "WAV SIZE: " << wave_Header.wav_size << "\n";
    std::cout << "WAV HEADER: " << wave_Header.wave_header << "\n";
    std::cout << "FMT HEADER: " << data_Chunk.fmt_header << "\n";
    std::cout << "FMT CHUNK SIZE: " << data_Chunk.fmt_chunk_size << "\n";
    std::cout << "AUDIO FORMAT: " << fmt.audio_format << "\n";
    std::cout << "NUM OF CHANNELS: " << fmt.num_channels << "\n";
    std::cout << "SAMPLE RATE: " << fmt.sample_rate << "\n";
    std::cout << "BYTE RATE: " << fmt.byte_rate << "\n";
    std::cout << "SAMPLE ALLIGNMENT: " << fmt.sample_alignment << "\n";
    std::cout << "BIT DEPTH: " << fmt.bit_depth << "\n";
}

void Wav::writeFile(const std::string &outFilename){
    std::ofstream outFile(outFilename, std::ios::out | std::ios::binary);
    outFile.write((char*)&wave_Header, sizeof(wavHeader));
    outFile.write((char*)&data_Chunk, sizeof(dataChunk));
    outFile.write((char*)&fmt, sizeof(FMT));
    outFile.write("data", 4);
    outFile.write((char*)&bufferSize_data, sizeof(bufferSize_data));
    int bytes_per_sample = fmt.bit_depth / 8;
    for (int i = 0; i < bufferSize_data; i++) {
        outFile.write((char*)&(buffers[i / bytes_per_sample % fmt.num_channels][i / fmt.num_channels]), 1);
    }
}

Wav::~Wav(){
    if(buffers != NULL){
        for (int i = 0; i < fmt.num_channels; i++) {
            delete[] buffers[i];
        }
    }
    delete[] buffers;
}
