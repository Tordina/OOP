#include<iostream>
#include"lab3_oop.h"

int main() {

    DTM::Array3d<int> array3D(3, 3, 3);

    array3D.fill_1(7);

    array3D.Print();

    array3D.setValue(1, 2, 3, 771);

    std::cout << array3D.getValue(1, 2, 3) << std::endl;


    array3D.zeroes();


    array3D.Print();

    return 0;
}