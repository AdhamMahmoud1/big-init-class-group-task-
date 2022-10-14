#ifndef BIGINT_H_INCLUDE
#define BIGINT_H_INCLUDE
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
        bool operator> (BigInt anotherDec);
        bool operator== (BigInt anotherDec);
        BigInt& operator= (BigInt anotherDec);
        int size();
        int sign();
        friend ostream& operator << (ostream& out, BigInt b);
};
#endif
