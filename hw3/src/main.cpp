#include <iostream>
#include <string>
#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"


int main() {
    std::string file_name = "../data/pbmlib.ascii.ppm";
    std::string down2_name = "../data/pbmlib_down.ascii.ppm";
    igg::PpmIoStrategy my_strategy; 
    igg::Image image(my_strategy);

    image.ReadFromDisk(file_name);
    image.DownScale(2);
    image.WriteToDisk(down2_name);
    
    return 0;
}