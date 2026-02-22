#pragma once
#ifndef _TENSORIMAGEIO_
#define _TENSORIMAGEIO_

#include <string>

#include <opencv2/opencv.hpp>

#include "TensorX/Tensor.hpp"


namespace tensor {

    template<Arithmetic T = float>
    Tensor<T> read_gray(std::string path){
        cv::Mat image = cv::imread(path, cv::IMREAD_GRAYSCALE); // IMREAD_COLOR (BGR), IMREAD_UNCHANGED (BGRA)
        // cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        // std::cout << image.size() << "x" << image.channels() << std::endl;

        if (!image.data){
            throw std::runtime_error("read_gray: No image data");
        }

        // Convert OpenCV Mat to Tensor
        Tensor t = mat2tensor(image);
        // std::cout << "t: rank(" << t.getRank() << "), size(" << t.getLength() << ")" << std::endl;
        // std::cout << "t: dims(" << array2string(t.getRank(), t.getDims()) << ")" << std::endl;
        // std::cout << "t: type(" << typeid(typename decltype(t)::type).name() << ")" << std::endl;
        return t;
    }

};

#endif



