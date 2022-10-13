#ifndef BIGDECINT_H_INCLUDE
#define BIGDECINT_H_INCLUDE
#include <iostream>
using namespace std;

class BigInt {
    private:
        string digits;
    public:
        BigInt();
        BigInt(string);
        BigInt(long long);
        BigInt& operator+ (BigInt num1);
        BigInt& operator= (BigInt anotherDec);
};
#endif
