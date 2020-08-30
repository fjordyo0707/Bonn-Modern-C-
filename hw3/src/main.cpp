#include <iostream>
#include <string>
#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"
#include "igg_image/io_strategies/png_strategy.h"


int main() {
    std::string file_name = "../data/lena1.png";
    std::string down2_name = "../data/lena1_down2.png";
    igg::PngIoStrategy my_strategy; 
    igg::Image image(my_strategy);

    image.ReadFromDisk(file_name);
    image.DownScale(2);
    image.WriteToDisk(down2_name);
    
    return 0;
}