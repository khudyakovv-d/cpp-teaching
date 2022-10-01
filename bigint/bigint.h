#include <string>

class BigInt {
public:
    BigInt();
    BigInt(int val);
    BigInt(std::string val); // бросать исключение std::invalid_argument при ошибке
    BigInt(const BigInt & val);
    ~BigInt();

    BigInt &operator=(const BigInt & val);  //возможно присваивание самому себе!

    BigInt operator~() const;
    BigInt &operator++();
    const BigInt operator++(int);
    BigInt &operator--();
    const BigInt operator--(int);

    BigInt &operator+=(const BigInt &val);
    BigInt &operator*=(const BigInt &val);
    BigInt &operator-=(const BigInt &val);
    BigInt &operator/=(const BigInt &val);
    BigInt &operator^=(const BigInt &val);
    BigInt &operator%=(const BigInt &val);
    BigInt &operator&=(const BigInt &val);
    BigInt &operator|=(const BigInt &val);

    BigInt operator+() const;  // unary +
    BigInt operator-() const;  // unary -

    bool operator==(const BigInt &val) const;
    bool operator!=(const BigInt &val) const;
    bool operator<(const BigInt &val) const;
    bool operator>(const BigInt &val) const;
    bool operator<=(const BigInt &val) const;
    bool operator>=(const BigInt &val) const;

    operator int() const;
    operator std::string() const;

    size_t size() const;
};

BigInt operator+(const BigInt &, const BigInt &);
BigInt operator-(const BigInt &, const BigInt &);
BigInt operator*(const BigInt &, const BigInt &);
BigInt operator/(const BigInt &, const BigInt &);
BigInt operator^(const BigInt &, const BigInt &);
BigInt operator%(const BigInt &, const BigInt &);
BigInt operator&(const BigInt &, const BigInt &);
BigInt operator|(const BigInt &, const BigInt &);

std::ostream &operator<<(std::ostream &o, const BigInt &i);
