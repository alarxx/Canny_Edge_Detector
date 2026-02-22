#include <iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>

#include "TensorX/Tensor.hpp"
#include "converter.hpp"
#include "utils.hpp"
#include "convolution.hpp"
#include "ops.hpp"
#include "image_processing.hpp"
#include "image_io.hpp"


using tensor::Tensor;
using tensor::mat2tensor, tensor::tensor2mat;


void test(){
    tensor::test_conv();
    tensor::test_mul();
    tensor::test_mul_scalars();
    tensor::test_scalar_mul();
}


int main(){
    Tensor<float> t = tensor::read_gray("./lenna.png");
    std::cout << "t: rank(" << t.getRank() << "), size(" << t.getLength() << ")" << std::endl;
    std::cout << "t: dims(" << array2string(t.getRank(), t.getDims()) << ")" << std::endl;
    std::cout << "t: type(" << typeid(typename decltype(t)::type).name() << ")" << std::endl;

    // Convolution

    // Tensor<float> sobel_x = {
    //     {-1, 0, 1},
    //     {-2, 0, 2},
    //     {-1, 0, 1}
    // };

    Tensor filtered = tensor::gaussian_blur(t, 2);

    // Canny
    // 1. Gaussian Filter
    // 2. Image Derivarive
    // 3. Non-Maximum Suppression
    // 4. Double Thresholding
    // 5. Hysterisis

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    // Convert Tensor to OpenCV Mat
    cv::imshow("Display Image", tensor2mat(t));
    cv::waitKey(0);
    cv::imshow("Filtered Image", tensor2mat(filtered));
    cv::waitKey(0);

    return 0;
}
