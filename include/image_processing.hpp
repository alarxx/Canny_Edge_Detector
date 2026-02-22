#pragma once
#ifndef _TENSORIMAGEPROCESSING_
#define _TENSORIMAGEPROCESSING_

#include "TensorX/Tensor.hpp"


namespace tensor {

    template<Arithmetic T>
    Tensor<T> gaussian_blur(Tensor<T>& image, int times = 1){
        Tensor<float> _blur5x5 = {
            {2,  4,  5,  4, 2},
            {4,  9, 12,  9, 4},
            {5, 12, 15, 12, 5},
            {4,  9, 12,  9, 4},
            {2,  4,  5,  4, 2}
        };
        Tensor blur5x5 = div(159.0f, _blur5x5);

        Tensor<T> result = image;

        for (int i = 0; i < times; ++i){
            std::cout << "gaussian_blur" << std::endl;
            result = conv(result, blur5x5);
        }

        return result;
    }

};

#endif
