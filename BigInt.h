#ifndef BIGINT_H_INCLUDE
#define BIGINT_H_INCLUDE
#include <iostream>
using namespace std;

class BigDecimalInt {
    private:
        string digits;
    public:
        BigDecimalInt();
        BigDecimalInt(string);
        BigDecimalInt(long long);
        BigDecimalInt& operator+ (BigDecimalInt num1);
        bool operator> (BigDecimalInt anotherDec);
        bool operator== (BigDecimalInt anotherDec);
        BigDecimalInt& operator= (BigDecimalInt anotherDec);
        int size();
        int sign();
        friend ostream& operator << (ostream& out, BigDecimalInt b);
};
#endif
