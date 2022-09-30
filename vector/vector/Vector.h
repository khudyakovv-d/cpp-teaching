//
// Created by daniil on 10.09.22.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


#include <malloc.h>

//struct Vector {
//    double *elem;
//    int size;
//};
//
//
//Vector *create_vector(int size) {
//    Vector *vector = (Vector *) malloc(sizeof(Vector));
//    vector->elem = (double *) malloc(sizeof(double) * size);
//    vector->size = size;
//    return vector;
//}
//
//void delete_vector(Vector *vector ) {
//    free(vector->elem);
//    free(vector);
//}

class Vector {
private:
    double *elem_;
    int size_;
public:

    Vector();

    explicit Vector(int size);

    Vector(std::initializer_list<double> lst);

    int size() const;

    ~Vector();

    double &operator[](int i);

    const double &operator[](int i) const;

    Vector(const Vector &vec);

    Vector &operator=(const Vector &vec);

    Vector(Vector &&vec) noexcept ;

    Vector &operator=(Vector &&vec) noexcept ;

    operator std::string() const;

};

Vector operator+(const Vector &vec1, const Vector &vec2);

Vector sum(const Vector &vec1, const Vector &vec2, const Vector &vec3);

std::ostream& operator<<(std::ostream& o, const Vector& i);


#endif //VECTOR_VECTOR_H
