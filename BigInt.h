#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

namespace HelperFunctions
{

}

class BigDecimalInt {
    private:
        string digits;
    public:

        // Constructors
        BigDecimalInt();
        BigDecimalInt(string);
        BigDecimalInt(long long);

        /*  operator overloading   */
        BigDecimalInt operator+ (BigDecimalInt num);
        BigDecimalInt& operator= (BigDecimalInt anotherDec);
        friend ostream& operator << (ostream& out, BigDecimalInt b);
        friend bool operator<(const BigDecimalInt &a, const BigDecimalInt &b);

        bool operator> (BigDecimalInt anotherDec);
        bool operator== (BigDecimalInt anotherDec);

        // setters 
        void set_string_digits(string &BigInt);

        // getters
        string get_digits();
        
        // instance methods
        int size();
        int sign();

};