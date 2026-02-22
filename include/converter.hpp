#pragma once
#ifndef _TENSORCONVERTER_
#define _TENSORCONVERTER_

#include "TensorX/Tensor.hpp"
#include <opencv2/opencv.hpp>

namespace tensor {
    template<Arithmetic T = float>
    Tensor<T> mat2tensor(const cv::Mat& src){
        if (src.empty()){
            throw std::runtime_error("mat2tensor: empty Mat");
        }
        // CV_8UC1 - Grayscale
        if(src.type() == CV_8UC1){
            int rows = src.rows;
            int cols = src.cols;

            Tensor<T> t(rows, cols);

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    t.get(r, c) = src.at<uchar>(r, c);
                }
            }

            return t;
        }
        // CV_8UC3, CV_8UC4 etc.
        else {
            throw std::runtime_error("mat2tensor: unsupported image format");
        }
    }

    template<Arithmetic T = float>
    cv::Mat tensor2mat(const Tensor<T>& t){
        // 2D Tensor - Grayscale
        if (t.getRank() == 2){
            int rows = t.getDims()[0];
            int cols = t.getDims()[1];

            cv::Mat m(rows, cols, CV_8UC1);
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    m.at<uchar>(r, c) = t.get(r, c);
                }
            }
            return m;
        }
        // 3D Tensor
        else {
            throw std::runtime_error("tensor2mat: unsupported image format");
        }
    }
};

#endif
