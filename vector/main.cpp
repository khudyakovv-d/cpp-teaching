#include <iostream>
#include "Vector.h"

int main() {

    // Создаем объект без new
    // При выходе из области видимости вызывается его деструктор
    {
        std::cout << "Test 1" << std::endl;
        Vector vector1(10);
        int size = vector1.size();
        std::cout << size << std::endl;
    }
    std::cout << std::endl;

    // Создаем объект с помощью new
    // При выходе из области видимости вызывается деструктор не вызывается - вызываем явно
    {
        std::cout << "Test 2" << std::endl;
        Vector *vector2 = new Vector(10);
        int size = vector2->size();
        std::cout << size << std::endl;
        delete vector2;
    }
    std::cout << std::endl;

    // Реализуем оператор []
    {
        std::cout << "Test 3" << std::endl;
        Vector vector1(10);
        vector1[5] = 10;
    }
    std::cout << std::endl;

    // Initializer list конструктор
    {
        Vector vector1{1, 3, 5, 7};
        std::cout << vector1[2] << std::endl;
    }
    std::cout << std::endl;

    // Пример использования копирующего конструктора
    // Если убрать переопределение копирующего конструктора -
    // увидим что изменилось значение vector1, чего быть не должно
    {
        std::cout << "Test 4" << std::endl;
        Vector vector1{1, 3, 5, 7};
        Vector vector2 = vector1;
        vector2[2] = 10;
        std::cout << vector1[2] << std::endl;
    }
    std::cout << std::endl;

    {
        std::cout << "Test 5" << std::endl;
        Vector vector1{1, 3, 5, 7};

        Vector vector2(10);
        vector2 = vector1;
        vector2[2] = 10;

        std::cout << vector1[2] << std::endl;
        std::cout << vector2[2] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
