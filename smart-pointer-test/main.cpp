#include <iostream>
#include <memory>
#include <vector>

class TestObj {
private:
    std::string data_;
public:
    TestObj(std::string data) : data_(data) {
    }

    const std::string getData() const {
        return data_;
    }

    std::string setData(std::string data) {
        data_ = data;
    }

};

void compareData(std::unique_ptr<TestObj> obj, std::string expectedData) {
    std::cout << obj->setData(expectedData);
}

void compareData(std::shared_ptr<TestObj> obj, std::string expectedData) {
    std::cout << obj->getData().compare(expectedData);
}

int main() {
    std::string data = "Hello";

    {
        //std::unique_ptr<TestObj> uptr = std::make_unique<TestObj>("Hello");

        const std::unique_ptr<TestObj> uptr =
                std::unique_ptr<TestObj>(new TestObj(data));

        compareData(std::move(uptr), "Hello 2");

        std::cout << uptr->getData();
    }

//    {
//        std::shared_ptr<TestObj> sptr =
//                std::shared_ptr<TestObj>(new TestObj(data));
//
//        compareData(sptr, "Hello 2");
//
//        std::cout << std::endl << sptr->getData();
//    }

    return 0;
}

