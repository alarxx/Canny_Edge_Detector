#include <iostream>
#include <stdio.h>

#include "TensorX/Tensor.hpp"
#include "converter.hpp"
#include "utils.hpp"

#include <opencv2/opencv.hpp>

using tensor::Tensor;
using tensor::mat2tensor, tensor::tensor2mat;

// using namespace cv;
using cv::Mat, cv::imread, cv::IMREAD_GRAYSCALE;
using cv::namedWindow, cv::WINDOW_AUTOSIZE, cv::imshow, cv::waitKey;

int main(){
    std::string imagePath = "./lenna.png";

    Mat image;
    image = imread(imagePath, IMREAD_GRAYSCALE); // IMREAD_COLOR (BGR), IMREAD_UNCHANGED (BGRA)
    // cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    std::cout << image.size() << "x" << image.channels() << std::endl;

    if (!image.data){
        printf("No image data \n");
        return -1;
    }

    // Convert OpenCV Mat to Tensor
    Tensor t = mat2tensor(image);
    std::cout << "t: rank(" << t.getRank() << "), size(" << t.getLength() << ")" << std::endl;
    std::cout << "t: dims(" << array2string(t.getRank(), t.getDims()) << ")" << std::endl;


    namedWindow("Display Image", WINDOW_AUTOSIZE);
    // Convert Tensor to OpenCV Mat
    imshow("Display Image", tensor2mat(t));

    waitKey(0);

    return 0;
}
