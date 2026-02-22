#include <iostream>
#include <stdio.h>

#include "TensorX/Tensor.hpp"

#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    std::cout << "Hello, Tensor Library!" << std::endl;

    std::string imagePath = "./lenna.png";

    Mat image;
    image = imread(imagePath, IMREAD_COLOR);

    if (!image.data){
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}
