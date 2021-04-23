// Jason Ha
// Purpose:

#include <string>
#include <fstream>
#include <iostream>

#include "wav.h"

wav_header wav::getWavHeader(){
    return waveHeader;
}

unsigned char *wav::getBuffer(){
    return buffer;
}

void wav::readFile(const std::string &fileName){
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    
    if(file.is_open()){
        file.read(char*)&waveHeader, sizeof(wav_header));
        while(file){
            file.read((char*)&info, sizeof(info));
            
            string header_word = info.fmt_header;
            int infoSize = info.fmt_info_size;
            
            if(header_word == "FMT "){
                file.read((char*)&fmt, sizeof(FMT));
            }else if(header_word == "LIST"{
                file.read((char*)&metadata, sizeof(METADATA);
            }else if(header_word == "DATA"){
                file.read((char*)&data, sizeof(DATA));
            }else{
                file.setg(infoSize);
            }
        }
    }
    file.close();
}

void wav::writeFile(const std::string filename){
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader, sizeof(wav_header));
    outFile.write((char*)&info, sizeof(info));
    outFile.close();
}
