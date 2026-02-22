#pragma once
#ifndef _TENSOROPS_
#define _TENSOROPS_

#include "TensorX/Tensor.hpp"

#include <string>
#include <cassert>


namespace tensor {

    template<Arithmetic T>
    bool equal(Tensor<T>& a, Tensor<T>& b){
        // same object
        if (&a == &b) return true;

        // ranks must match
        if (a.getRank() != b.getRank()) return false;

        int rank = a.getRank();
        int* ad = a.getDims();
        int* bd = b.getDims();

        // dims must match (handle null dims safely)
        if (rank > 0){
            if (ad == nullptr || bd == nullptr) return false;
            for (int i = 0; i < rank; ++i){
                if (ad[i] != bd[i]) return false;
            }
        }

        int n = a.getLength(); // b.getLength()
        // Directly use coeffs
        T * ac = a.getCoeffs();
        T * bc = b.getCoeffs();

        if (n > 0 && (ac == nullptr || bc == nullptr)) return false;

        for (int i = 0; i < n; ++i){
            if (ac[i] != bc[i]) return false;
        }
        return true;
    }


    template<Arithmetic T, typename Op>
    Tensor<T> elementwise(
        Tensor<T>& a, Tensor<T>& b,
        Op op, std::string opname = "elementwise"
    ){
        if (a.getRank() != b.getRank()){
            throw std::runtime_error(opname + ": ranks don't match");
        }

        int rank = a.getRank();
        int* ad = a.getDims();
        int* bd = b.getDims();
        // dims must match
        if (rank > 0){
            if (ad == nullptr || bd == nullptr){
                throw std::runtime_error(opname + ": nullptr dims");
            }
            for (int i = 0; i < rank; ++i){
                if (ad[i] != bd[i]){
                    throw std::runtime_error(opname + ": dims don't match");
                }
            }
        }

        int n = a.getLength(); // b.getLength()
        // Directly use coeffs
        T * ac = a.getCoeffs();
        T * bc = b.getCoeffs();

        if (n > 0 && (ac == nullptr || bc == nullptr)){
            throw std::runtime_error(opname + ": nullptr coeffs");
        }

        // Scalars
        if (rank == 0){
            return tensor::scalar<T>(op(ac[0], bc[0]));;
        }
        // Tensors
        Tensor<T> out(rank, ad);
        T * oc = out.getCoeffs();
        for (int i = 0; i < n; ++i){
            oc[i] = op(ac[i], bc[i]);
        }
        return out;
    }


    template<Arithmetic T>
    Tensor<T> mul(Tensor<T>& a, Tensor<T>& b){
        return elementwise<T>(a, b, [](T x, T y){ return x * y; }, "mul");
    }
    template<Arithmetic T>
    Tensor<T> div(Tensor<T>& a, Tensor<T>& b){
        return elementwise<T>(a, b, [](T x, T y){ return x / y; }, "div");
    }
    template<Arithmetic T>
    Tensor<T> add(Tensor<T>& a, Tensor<T>& b){
        return elementwise<T>(a, b, [](T x, T y){ return x + y; }, "add");
    }
    template<Arithmetic T>
    Tensor<T> sub(Tensor<T>& a, Tensor<T>& b){
        return elementwise<T>(a, b, [](T x, T y){ return x - y; }, "sub");
    }


    void test_mul(){
        Tensor<float> a = {
            {1, 2, 3},
            {3, 4, 5}
        };
        Tensor<float> b = {
            {5, 6, 7},
            {6, 7, 8}
        };
        Tensor<float> expected = {
            { 5, 12, 21},
            {18, 28, 40}
        };

        Tensor<float> out = mul(a, b);
        std::cout << out << std::endl;
        assert(equal(out, expected) && "mul result is not correct");
    }

};

#endif
