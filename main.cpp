#include <iostream>
#include <stdio.h>

#include "TensorX/Tensor.hpp"
#include "converter.hpp"
#include "utils.hpp"
#include "convolution.hpp"
#include "ops.hpp"

#include <opencv2/opencv.hpp>

using tensor::Tensor;
using tensor::mat2tensor, tensor::tensor2mat;
using tensor::conv;

// using namespace cv;
using cv::Mat, cv::imread, cv::IMREAD_GRAYSCALE;
using cv::namedWindow, cv::WINDOW_AUTOSIZE, cv::imshow, cv::waitKey;

int main(){
    tensor::test_conv();
    tensor::test_mul();
    tensor::test_mul_scalars();
    tensor::test_scalar_mul();

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
    std::cout << "t: type(" << typeid(typename decltype(t)::type).name() << ")" << std::endl;

    // Convolution
    Tensor<float> _blur5x5 = {
        {2,  4,  5,  4, 2},
        {4,  9, 12,  9, 4},
        {5, 12, 15, 12, 5},
        {4,  9, 12,  9, 4},
        {2,  4,  5,  4, 2}
    };
    Tensor<float> blur5x5 = tensor::div(159.0f, _blur5x5);

    // Tensor<float> sobel_x = {
    //     {-1, 0, 1},
    //     {-2, 0, 2},
    //     {-1, 0, 1}
    // };

    Tensor filtered = tensor::conv(t, blur5x5);

    // Canny
    // 1. Gaussian Filter
    // 2. Image Derivarive
    // 3. Non-Maximum Suppression
    // 4. Double Thresholding
    // 5. Hysterisis

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    // Convert Tensor to OpenCV Mat
    imshow("Display Image", tensor2mat(t));
    waitKey(0);
    imshow("Filtered Image", tensor2mat(filtered));
    waitKey(0);

    return 0;
}
