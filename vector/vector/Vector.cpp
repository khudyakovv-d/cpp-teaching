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
    std::cout << "Create vector " << this << "\n";
}

int Vector::size() const {
    return size_;
}

Vector::~Vector() {
    delete[] elem_;
    std::cout << "Delete vector " << this << "\n";
}

double &Vector::operator[](int i) {
    return elem_[i];
}

const double &Vector::operator[](int i) const {
    return elem_[i];
}

Vector::Vector(std::initializer_list<double> lst) :
        elem_(new double[lst.size()]),
        size_(static_cast<int>(lst.size())) {
    std::copy(lst.begin(), lst.end(), elem_);
    std::cout << "Create " << this << " from list" << std::endl;
}

Vector::Vector(const Vector &vec) :
        elem_(new double[vec.size_]),
        size_(vec.size_) {
    for (int i = 0; i < size_; ++i) {
        elem_[i] = vec[i];
    }
    std::cout << "Create " << this << " from " << &vec << std::endl;
}

Vector &Vector::operator=(const Vector &vec) {
    if (this == &vec) {
        return *this;
    }

    delete[] elem_;

    auto *res_elem = new double[vec.size_];

    for (int i = 0; i < vec.size_; ++i) {
        res_elem[i] = vec[i];
    }

    elem_ = res_elem;
    size_ = vec.size_;

    std::cout << "Copy " << &vec << " to " << this << std::endl;

    return (*this);
}

Vector::Vector() {
    this->elem_ = nullptr;
    this->size_ = 0;
    std::cout << "Create default vector " << this << "\n";
}

Vector::Vector(Vector &&vec) noexcept {
    this->elem_ = vec.elem_;
    this->size_ = vec.size_;
    vec.elem_ = nullptr;
    vec.size_ = 0;
    std::cout << "Create vector " << this << " with move " << &vec << "\n";
}

Vector &Vector::operator=(Vector &&vec) noexcept {
    delete[] this->elem_;
    this->elem_ = vec.elem_;
    this->size_ = vec.size_;
    vec.elem_ = nullptr;
    vec.size_ = 0;
    std::cout << "Copy with move " << &vec << " to " << this << std::endl;
}

Vector::operator std::string() const {
    std::string res;
    for (int i = 0; i < this->size_; ++i) {
        res += std::to_string(elem_[i]) + " ";
    }
    return res;
}

Vector operator+(const Vector &vec1, const Vector &vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::length_error("Vectors must be same size");
    }

    Vector res(vec1.size());

    for (int i = 0; i < vec1.size(); ++i) {
        res[i] = vec1[i] + vec2[i];
    }

    std::cout << "Sum " << &vec1 << " and " << &vec2 << " to " << &res << std::endl;

    return res;
}

Vector sum(const Vector &vec1, const Vector &vec2, const Vector &vec3) {
    return vec1 + vec2 + vec3;
}

std::ostream &operator<<(std::ostream &o, const Vector &i) {
    return o << std::string(i) << std::endl;
}