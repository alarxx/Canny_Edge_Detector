#pragma once
#ifndef _UTILS_
#define _UTILS_

#include <string>

template<typename T>
std::string array2string(int length, const T * array){
    std::string result = "[";
    for(int i = 0; i < length; ++i){
        result += std::to_string(array[i]);
        if (i != length - 1) result += ", ";
    }
    result += "]";
    return result;
}

#endif
