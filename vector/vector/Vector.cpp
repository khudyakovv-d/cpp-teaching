//
// Created by daniil on 10.09.22.
//

#include <iostream>
#include "Vector.h"

Vector::Vector(int size) :
        elem_(new double[size]),
        size_(size) {
    for (int i = 0; i < size_; ++i) {
        elem_[i] = 0;
    }
    std::cout << "Create vector" << "\n";
}

int Vector::size() const {
    return size_;
}

Vector::~Vector() {
    delete[] elem_;
    std::cout << "Delete vector" << "\n";
}

double &Vector::operator[](int i) {
    std::cout << "Get element " << i << "in simple operator\n";
    return elem_[i];
}

const double &Vector::operator[](int i) const {
    std::cout << "Get element " << i << "in const operator\n";
    return elem_[i];
}

Vector::Vector(std::initializer_list<double> lst) :
        elem_(new double[lst.size()]),
        size_(static_cast<int>(lst.size())) {
    std::copy(lst.begin(), lst.end(), elem_);
}

Vector::Vector(const Vector &vec) :
        elem_(new double[vec.size_]),
        size_(vec.size_) {
    for (int i = 0; i < size_; ++i) {
        elem_[i] = vec[i];
    }
}

Vector &Vector::operator=(const Vector &vec) {
    delete[] elem_;

    double *res_elem = new double[vec.size_];

    for (int i = 0; i < vec.size_; ++i) {
        res_elem[i] = vec[i];
    }

    elem_ = res_elem;
    size_ = vec.size_;

    return (*this);
}
