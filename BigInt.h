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
        // ~BigDecimalInt();

                        /*  operators overloading   */
        
        // arithmatic 
       // I made this operator as a friend member to be able to pass 2 objects as a argument
        friend BigDecimalInt operator+ (BigDecimalInt , BigDecimalInt );

        // assignment 
        BigDecimalInt& operator= (BigDecimalInt anotherDec);

        // bitwise
        friend ostream& operator << (ostream& out, BigDecimalInt b);
        friend istream& operator >> (istream& in, BigDecimalInt &b);

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
