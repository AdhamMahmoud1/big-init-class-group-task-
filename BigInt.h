#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


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


namespace HelperFunctions
{

    // Those functions check whether bigint is -ve or +ve
    bool IsPositive(BigDecimalInt &a)
    {
        bool ans = false;
        if (a.sign() == 1)
        {
            ans = true;
        }

        return ans;
    }

    bool IsNegative(BigDecimalInt &a)
    {
        bool ans = false;
        
        if (a.sign() == -1)
        {
            ans = true;
        }

        return ans;
    }


    // Take string of digits and parse to get rid of sign
    string ParseString(string target)
    {
        // to store answer
        string temp = "";

        // if first char in target has a sign
        if (!isdigit(target[0]))
        {
            
            temp = target.substr(1, target.length() - 1);

        }
        
        else
        {
            // incase 0 of target has digit
            temp = target;
        }

        return temp;
    }

    // Check if givin string comprised of zeros 
    bool IsStringCompriesdOfZeros(string &target)
    {
        // flag
        bool flag = false;

        // set is data strucure removes dublicate numbers
        set<char> temp(target.begin(), target.end());

        // get first element by iterator and pointer
        auto first_element = *temp.begin();
        if ((temp.size() == 1) && (first_element == '0'))
        {
            flag = true;
        }
        

        return flag;

    }

    // Take string and remove any leading zeros
    void remove_leading_zeros(string &target)
    {
        int i = 0;

        while (target[i] == '0')
        {
            i ++;
        }
        target = target.substr(i, target.length() - i);
    
    }

    // Do line z-index function in python
    void Fill_zindex(string &target, int n)
    {
        // reversed string
        reverse(target.begin(), target.end());

        for(int i = 0; i < n; ++i)
        {
            target.push_back('0');
        }

        reverse(target.begin(), target.end());

        
    }

    // Compare between two BigDecimalInts
    bool IsFirstSmaller(BigDecimalInt &a, BigDecimalInt &b)
    {
        bool ans = false;
        if (a < b)
        {
            ans = true;
        }

        return ans;
    }


    // Find substraction of Two +ve strings
    string find_diff(string first_str, string second_str, bool is_first_smaller=false)
    {
        // ans to store out put of substration
        string ans = "";

        // bigger is first to loop at
        if (is_first_smaller)
        {
            // if first smaller swap so we can substract
            swap(first_str, second_str);


        }

        // after checking, create important credinials
        int len_a = first_str.length();
        int len_b = second_str.length();


        // carry variable to store carry providing sub is negative
        int carry = 0;

        // file rest of smaller digits with zeros
        Fill_zindex(second_str, (len_a - len_b));

        /*Substraction algorithm

            1- iterate backwords over both strings (or simply reverse both of them)
            2- substract each correspoding digits - carry
            3- if sub < 0 (negative ): add 10 to sub and carry = 1
        */
        for (int i = len_a - 1; i >= 0; --i)
        {
            int sub = ((first_str[i] - '0') - (second_str[i] - '0')) - carry;
            
            // if sub < 0: add 10, and carry = 1: so as it will be subsracted to next digit
            if (sub < 0)
            {
                sub += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            // push back to ans: if not zero
            ans.push_back(sub + '0');

        }

        // revser string to get rid of (iterating backwords impact)
        reverse(ans.begin(), ans.end());

        // check if string has any leading zeros
        if (IsStringCompriesdOfZeros(ans))
        {
            ans = "0";
        }   
        else
        {
            // remove any leading zeros if exists
            remove_leading_zeros(ans);
        }
        
        return ans;
    }

    // Find Sum of +ve BigDecimalInts
    string find_sum (string num1, string num2)     // Thanks to Adham Mahmoud
    {
        string sum = "";
    
        if (num1.length() > num2.length())
        {
            swap(num1, num2);
        } 
        reverse(num1.begin(), num1.end()); // reversing the number two add digits from the smalleset to the greatest
        reverse(num2.begin(), num2.end()); // reversing the number two add digits from the smalleset to the greatest
        int len1 = num1.size(), len2 = num2.size();
        int carry = 0;
        int intSum;
        for (int i = 0; i < len1; i++){
            intSum = (num1[i] - '0') + ((num2[i] - '0') + carry);
            sum.push_back((intSum % 10) + '0');
            carry = intSum / 10;
        }
        for (int i = len1; i < len2 ; i++){  // If the number of digits of the number is greater than the other
            int intSum = ((num2[i] - '0') + carry);
            sum.push_back((intSum % 10) + '0');
            carry = intSum / 10;
        }
        if (carry){
            sum.push_back(carry + '0');
        }
        if (sum[0] == '-'){
            reverse(sum.begin() + 1, sum.end());
        }
        else {
            reverse(sum.begin(), sum.end());
        }
        
        return sum;
    }

}
