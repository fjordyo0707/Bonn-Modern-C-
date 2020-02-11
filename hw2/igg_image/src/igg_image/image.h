#pragma once

#include <vector>
#include <string>

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
  Image() {};
  Image(int rows, int cols): rows_{rows}, cols_{cols}{
    data_.reserve(cols_ * rows_);
  };
  int rows() const { return rows_; }
  int cols() const { return cols_; }
  int& at(int row, int col); 
  bool FillFromPgm(const std::string& file_name);
  void WriteToPgm(const std::string& file_name);
  std::vector<float> ComputeHistogram(int bins);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg