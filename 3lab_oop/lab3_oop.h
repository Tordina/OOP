#pragma once
#include<iostream>
namespace DTM {
    template <typename T>
    class Array3d {
    private:
        int dim0_, dim1_, dim2_;
        T* _arr;
        void fill(int number) {
            for (int i = 0; i < dim0_; i++) {
                for (int j = 0; j < dim1_; j++) {
                    for (int k = 0; k < dim2_; k++)
                    {
                        _arr[(i, j, k)] = number;
                    }
                }
            }

        }

    public:

        Array3d(int dim0, int dim1, int dim2) :dim0_(dim0), dim1_(dim1), dim2_(dim2) {

            _arr = new T[dim0 * dim1 * dim2];

        }

        ~Array3d() {
            delete[] _arr;
        }

        T& operator()(int i, int j, int k) {
            return _arr[i * (dim1_ * dim2_) + j * dim2_ + k];
        }

        T getValue(int i, int j, int k)
        {
            return _arr[i * (dim1_ * dim2_) + j * dim2_ + k];
        }

        T setValue(int i, int j, int k, const T& data)
        {
            return _arr[i * (dim1_ * dim2_) + j * dim2_ + k] = data;
        }

        Array3d(const Array3d& array3D) = delete;

        Array3d& operator=(const Array3d& array3D) = delete;

        void fill_1(int number)
        {
            fill(number);
        }

        void ones() {
            fill(1);

        }

        void zeroes() {
            fill(0);

        }

        void Print()
        {
            for (int i = 0; i < dim0_; i++)
            {
                for (int j = 0; j < dim1_; j++)
                {
                    for (int k = 0; k < dim2_; k++)
                    {
                        std::cout << _arr[(i, j, k)] << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }

    };

}