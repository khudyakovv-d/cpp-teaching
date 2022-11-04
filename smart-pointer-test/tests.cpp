#include <iostream>
#include "gtest/gtest.h"
#include <memory>
#include <vector>

class TestObj {
private:
    std::string data_;
public:
    TestObj(std::string data) : data_(data) {
    }

    std::string getData() {
        return data_;
    }

    void assertData(std::unique_ptr<TestObj> obj, std::string expectedData) {
        ASSERT_EQ(obj->getData(), expectedData);
    }

};

TEST(sp_test, unique_ptr_1) {
    //std::unique_ptr<TestObj> uptr = std::make_unique<TestObj>("Hello");

    std::string data = "Hello";
    std::unique_ptr<TestObj> uptr =
            std::unique_ptr<TestObj>(new TestObj(data));

    assertData(uptr, data);
}

