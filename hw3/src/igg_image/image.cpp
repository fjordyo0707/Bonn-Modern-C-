#include "image.h"

namespace igg{
    
    Image::Pixel& Image::at(int row, int col){
      return data_[ row * cols_ + col];
    }


    void Image::DownScale(int scale){
      int re_cols_ = cols_ / scale;
      int re_rows_ = rows_ / scale;
      std::vector<Image::Pixel> resized_data(re_cols_ * re_rows_);

      for(int i = 0; i < re_rows_; i++){
          for(int j = 0; j < re_cols_; j++){
              resized_data[i * re_cols_ + j] = at(i * scale, j * scale);
          }
      }

      data_ = resized_data;
      rows_ = re_rows_;
      cols_ = re_cols_;
    }

  void Image::UpScale(int scale){
    int re_cols_ = cols_ * scale;
    int re_rows_ = rows_ * scale;
    std::vector<Image::Pixel> resized_data(re_cols_ * re_rows_);

    for(int i = 0; i < re_rows_; i++){
       for(int j = 0; j < re_cols_; j++){
           resized_data[i * re_cols_ + j] = at(i / scale, j / scale);
       }
    }

    data_ = resized_data;
    rows_ = re_rows_;
    cols_ = re_cols_;
  }

  bool Image::ReadFromDisk(const std::string& file_name){
      const ImageData my_image_data = my_strategy_.Read(file_name);
      rows_ = my_image_data.rows;
      cols_ = my_image_data.cols;
      max_val_ = my_image_data.max_val;
      data_.resize(rows_ * cols_);

      for(int i = 0; i < rows_ *  cols_; i++){
          data_[i].red = my_image_data.data[0][i];
          data_[i].green = my_image_data.data[1][i];
          data_[i].blue = my_image_data.data[2][i];
      }

    if(my_image_data.data.empty())
        return false;

    return true;
  }
  void Image::WriteToDisk(const std::string& file_name){
      ImageData my_image_data;
      my_image_data.rows = rows_;
      my_image_data.cols = cols_;
      my_image_data.max_val = max_val_;
      my_image_data.data.resize(3);
      for(int i = 0; i < my_image_data.data.size(); i++){
        my_image_data.data[i].resize(rows_ * cols_);
      }

      for(int i = 0; i < rows_ * cols_; i++){
        my_image_data.data[0][i] = data_[i].red;
        my_image_data.data[1][i] = data_[i].green;
        my_image_data.data[2][i] = data_[i].blue;
      }
      bool is_write = my_strategy_.Write(file_name, my_image_data);
  }
} 
