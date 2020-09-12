#include "igg_image/io_strategies/ppm_strategy.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name,
                          const ImageData& data) const {
    std::fstream file;
    file.open(file_name, std::ios_base::out);
    if(!file){
        std::cerr << "Can't open file!\n";
        return false; 
    } else{
        file << "P3"<< std::endl;
        file << data.cols << " "<< data.rows << std::endl;
        file << data.max_val << std::endl;
        for(int i = 0; i < data.cols * data.rows; i++){
            file << data.data[0][i] <<" "<< data.data[1][i]<<" "<< data.data[2][i]<<"  ";
        }
    }
    return true;
}

ImageData PpmIoStrategy::Read(const std::string& file_name) const {
    std::ifstream file(file_name, std::ios_base::in);;
    ImageData image_data;
    std::string line;
    bool is_read_image_size = false;
    bool is_read_max_val = false;

    if(file.is_open()){
        while(!is_read_max_val) {
            std::getline(file, line);

            if(line[0] == 'P')
                continue;

            if(line[0] == '#')
                continue;

            if(!is_read_image_size){
                std::stringstream iss(line);
                iss >> image_data.cols >> image_data.rows;
                is_read_image_size = true;
            } else if (!is_read_max_val){
                std::stringstream iss(line);
                iss >> image_data.max_val;
                is_read_max_val = true;
            }
        }

        image_data.data.resize(3);
        for(auto& ch: image_data.data)
            ch.resize(image_data.cols * image_data.rows);
    
        int i = 0;
        while(!file.eof()){
            file >> image_data.data[0][i];
            file >> image_data.data[1][i];
            file >> image_data.data[2][i];
            ++i;
        }
        file.close();
    } else {

    }
    return image_data;
}

}  // namespace igg
