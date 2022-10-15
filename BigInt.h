#pragma once
#include <iostream>
#include <string>
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

        // Decstructor
        ~BigDecimalInt();

                        /*  operators overloading   */
        
        // arithmatic 
        BigDecimalInt operator+ (BigDecimalInt num);

        // assignment 
        BigDecimalInt& operator= (BigDecimalInt anotherDec);

        // bitwise
        friend ostream& operator << (ostream& out, BigDecimalInt b);

        // Relational
        bool operator> (BigDecimalInt anotherDec);
        friend bool operator<(const BigDecimalInt &a, const BigDecimalInt &b);
        bool operator== (BigDecimalInt anotherDec);

                                /*  Methods   */

        // setters 
        void set_string_digits(string &BigInt);

        // getters
        string get_digits();
        
        // instance methods
        int size();
        int sign();

};