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

unsigned char *Wav::getBuffer(){
    return buffer;
}

void Wav::readFile(const std::string &fileName){
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    
    if(file.is_open()){
        file.read((char*)&wave_Header, sizeof(wavHeader));
        while(file){
            file.read((char*)&data_Chunk, sizeof(dataChunk));
            
            std::string header_word = data_Chunk.fmt_header;
            int chunkSize = data_Chunk.fmt_chunk_size;
            
            //Format Chunk
            if(header_word == "FMT "){
                file.read((char*)&fmt, sizeof(FMT));
            }
            //Metadata Chunk
            else if(header_word == "LIST"){
                int counter = 0;
                char garbage[4];
                file.read(garbage, 4);
                while(counter < chunkSize){
                    SubChunkData subchunk;
                    file.read((char*)&subchunk, sizeof(dataChunk));
                    subchunk.buffer = new char [subchunk.fmt_chunk_size];
                    metadata.push_back(subchunk);
                    counter += (sizeof(dataChunk) + subchunk.fmt_chunk_size);
                }
            }
            //Data Chunk
            else if(header_word == "DATA"){
                bufferSize_data = chunkSize;
                buffer = new unsigned char [chunkSize];
                file.read((char*)&buffer, chunkSize);
            }else{
                //*seekg: allows you to seek to an arbitrary position in a file, it is used in file handling to sets the position of the next character to be extracted from the input stream from a given file.
                file.seekg(chunkSize, std::ios::cur);
            }
        }
    }
    file.close();
}

void Wav::writeFile(const std::string &outFilename){
    std::ofstream outFile(outFilename, std::ios::out | std::ios::binary);
    outFile.write((char*)&wave_Header, sizeof(wavHeader));
    
    //Format Chunk
    outFile.write("fmt ", 4);
    int size = sizeof(fmt);
    outFile.write((char*)&size, sizeof(size));
    outFile.write((char*)&fmt, sizeof(FMT));
    
    //Metadata Chunk
    outFile.write("LIST", 4);
    size = 4;
    for(SubChunkData s: metadata){
        size += (sizeof(dataChunk) + s.fmt_chunk_size);
    }
    outFile.write((char*)&size, sizeof(size));
    outFile.write("INFO", 4);
    for(SubChunkData s: metadata){
        outFile.write((char*)&s, sizeof(dataChunk));
        outFile.write((char*)&s.buffer, sizeof(s.fmt_chunk_size));
    }
    
    //Data Chunk
    outFile.write("DATA", 4);
    outFile.write((char*)&bufferSize_data, sizeof(bufferSize_data));
    outFile.write((char*)&buffer, bufferSize_data);
}

Wav::~Wav(){
    if(buffer != NULL){
        delete[] buffer;
    }
}
