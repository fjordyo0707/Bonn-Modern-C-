#include <iostream>
#include <string>
#include "image.h"
#include "io_tools.h"

int main() {
    std::string file_name = "/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena.ascii.pgm";
    std::string down2_name = "/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena_down2_in_main.pgm";
    
    igg::Image image(50, 50);

    if (!(image.FillFromPgm(file_name))) { 
        return 1;
    }

    image.DownScale(2);
    image.WriteToPgm(down2_name);
    
    return 0;
}
