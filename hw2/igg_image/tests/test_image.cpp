#include <gtest/gtest.h>
#include "igg_image/image.h"
#include <vector>

using namespace igg;

TEST(TestImage, InitFromNumber) {
    Image image(512, 512);
    EXPECT_EQ(512, image.rows());
    EXPECT_EQ(512, image.cols());
}

TEST(TestImage, InitFromFile) {
    Image image;
        
    EXPECT_EQ(true, image.FillFromPgm("/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena.ascii.pgm"));

    for (int i = 0; i < image.rows(); i++){
        for (int j = 0; j < image.cols(); j++){
            image.at(i,j) = 0;
        }
    }

    image.WriteToPgm("/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lenatoblack.pgm");
}

TEST(TestImage, InitFromFileFail) {
    Image image;
        
    EXPECT_EQ(false, image.FillFromPgm("non existent"));
}

TEST(TestImage, ComputeHistogramSum) {
    Image image;
    image.FillFromPgm("/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena.ascii.pgm");

    std::vector<float> histogram = image.ComputeHistogram(4);

    EXPECT_EQ(4, int (histogram.size()));
    EXPECT_EQ(1, histogram[0] + histogram[1] + histogram[2] + histogram[3]);
}

TEST(TestImage, ComputeHistogramNoBin) {
    Image image;
    image.FillFromPgm("/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena.ascii.pgm");

    std::vector<float> histogram = image.ComputeHistogram(0);

    EXPECT_EQ(0, int (histogram.size()) );
}

TEST(TestImage, TestDownScale) {
    Image image;
    image.FillFromPgm("/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena.ascii.pgm");

    image.DownScale(2);
    image.WriteToPgm("/home/fjord/Desktop/Modern C++/Bonn-Modern-C++/hw2/igg_image/data/lena_down2.pgm");
    
    EXPECT_EQ(256, image.rows());
    EXPECT_EQ(256, image.cols());
}
