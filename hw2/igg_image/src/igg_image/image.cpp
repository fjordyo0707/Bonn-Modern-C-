#include "image.h"
#include "io_tools.h"
#include <iostream>

namespace igg{

  // setter and getter
  int& Image::at(int row, int col){
    return data_[ row * cols_ + col];
  }

  bool Image::FillFromPgm(const std::string& file_name){
    io_tools::ImageData temp_data = io_tools::ReadFromPgm(file_name);

    if(temp_data.data.empty()){
      return false;
    }

    rows_ = temp_data.rows;
    cols_ = temp_data.cols;
    max_val_ = temp_data.max_val;
    data_ = temp_data.data;
    
    return true;
  }

  void Image::WriteToPgm(const std::string& file_name){
      io_tools::ImageData temp_data = {rows_, cols_, max_val_, data_};

      bool write_sucessful = io_tools::WriteToPgm(temp_data, file_name);

      if (write_sucessful)
          std::cout<< "The data is processed sucessfully."<<std::endl;
      else
          std::cout<< "The data is processed wrong."<<std::endl;
  }

  std::vector<float> Image::ComputeHistogram(int bins) {
      std::vector<float> histogram(bins, 0);
      if (bins==0)
          return histogram;
      int span = 255/bins;
      int total_pixel = rows_ * cols_;
      for(const auto& value : data_ ){
          int span_idx = value/span;
          histogram[span_idx] = histogram[span_idx] + 1 / (float) total_pixel;
      }
      
      return histogram;
  }

  void Image::DownScale(int scale){
      int re_cols_ = cols_ / scale;
      int re_rows_ = rows_ / scale;
      std::vector<int> resized_data(re_cols_ * re_rows_, 0);

      for(int i = 0; i < re_rows_; i++){
          for(int j = 0; j < re_cols_; j++){
              resized_data[i * re_cols_ + j] = at(i * scale, j * scale);
          }
      }

      data_ = resized_data;
      rows_ = re_rows_;
      cols_ = re_cols_;
  }






}
