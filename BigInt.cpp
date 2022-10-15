#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

//_______________
// Adham Mahmoud

BigDecimalInt::BigDecimalInt(string decStr){
    digits = "";
    if (decStr[0] == '-'){
        digits.push_back(decStr[0]);
        decStr.erase(decStr.begin());
        for (int i = 0; i < decStr.size(); i ++){
            if(!isdigit(decStr[i])){
                throw("Error");
            }
            digits.push_back(decStr[i]);
        }
    }
    else if ( decStr[0] =='+'){
        decStr.erase(decStr.begin());
        for (int i = 0; i < decStr.size(); i ++){
            if(!isdigit(decStr[i])){
                throw("Error");
            }
            digits.push_back(decStr[i]);
        }
    }
    else{
        for (int i = 0; i < decStr.size(); i ++){
            if(!isdigit(decStr[i])){
                throw("Error");
            }
            digits.push_back(decStr[i]);
        }
    }

}



BigDecimalInt::BigDecimalInt(long long decInt){
    digits = "";
    int i = 0;
    if (decInt < 0){
        decInt *= -1;
        digits.push_back('-');
        i = 1;
    }
    do{
        digits.push_back((decInt % 10) + '0');
        decInt /= 10;
    }
    while(decInt != 0);
    reverse(digits.begin() + i, digits.end());
}


BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt num){
    if (digits.size() > num.digits.size()){
        swap(digits, num.digits);
    }
    reverse(num.digits.begin(), num.digits.end());
    reverse(digits.begin(), digits.end());
    int len1 = digits.size(), len2 = num.digits.size();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;
    string sum = "";
    for (int i = 0; i < len1; i++){
        intSum = (digits[i] - '0') + ((num.digits[i] - '0') + carry);
        sum.push_back((intSum % 10) + '0');
        carry = intSum / 10;
    }
    for (int i= len1; i < len2 ; i++){
        int intSum = ((num.digits[i] - '0') + carry);
        sum.push_back((intSum % 10) + '0');
        carry = intSum / 10;
    }
    if (carry){
        sum.push_back(carry + '0');
    }
    reverse(sum.begin(), sum.end());
    BigDecimalInt bigSum("");
    bigSum.digits = sum;
    return bigSum;
}


//________________________
// Fady Kamal

bool operator<(const BigDecimalInt &a, const BigDecimalInt &b)
{
    bool ans;

    // check by sign first
    if (a.digits[0] == '-'  && b.digits[0] != '-')
    {
        // first is negative and second is positive: first is smaller
        ans = true;
        
    }


    else if ((a.digits[0] != '-')  && (b.digits[0] == '-'))
    {
        // first is positve and second negative: first is bigger
        ans = false;
    }


    else if ((a.digits[0] == '-')  && (b.digits[0] == '-'))
    {
        
        // if a.digits.length > than second or < than second: then compare in terms of length
        if (a.digits.length() != b.digits.length())
        {
            // note: negative comparison is opposite to the positive one
            ans = !(a.digits.length() < b.digits.length());

        }
        
        else
        {
            // if both number have same length then compare each corresponding digit
            // iterate over both string backwords
            // note: iterate backwords without including 0 >> to ignore - sign
            for (int i = a.digits.length() - 1; i > 0; --i)
            {
                int first_digit = a.digits[i] - '0';
                int second_digit = b.digits[i] - '0';

                // if corresponding digits are equal: continue
                if (first_digit == second_digit)
                {
                    continue;
                }

                else
                {
                    // if not equal then compare them, break the loop
                    ans = !(first_digit < second_digit);
                    break;
                }
            }
        }  

                

    }

    else
    {


        // if a.digits.length > than second or < than second: then compare in terms of length
        if (a.digits.length() != b.digits.length())
        {
            ans = (a.digits.length() < b.digits.length());

        }
        
        else
        {
            // if both number have same length then compare each corresponding digit
            // iterate over both string backwords
            for (int i = a.digits.length() - 1; i >= 0; --i)
            {
                int first_digit = a.digits[i] - '0';
                int second_digit = b.digits[i] - '0';

                // if corresponding digits are equal: continue
                if (first_digit == second_digit)
                {
                    continue;
                }

                else
                {
                    // if not equal then compare them, break the loop
                    ans = (first_digit < second_digit);
                    break;
                }
            }
        }
    }

    
    return ans;
}





//________________________
// Mahmoud Mohamed

bool BigDecimalInt:: operator> (BigDecimalInt anotherDec)
{
    bool ans;
    if( digits[0] == '-' && anotherDec.digits[0] != '-')
    {
        ans = 0 ;
    }
    else if(digits[0] != '-' && anotherDec.digits[0] == '-')
    {
        ans = 1 ;
    }
    else if(digits[0] == anotherDec.digits[0] && digits[0] == '-' && digits.length() != anotherDec.digits.length())
    {

        if(digits.length() > anotherDec.digits.length()){
            ans = 0 ;
        }
        else if(digits.length() < anotherDec.digits.length()){
            ans = 1 ;
        }
    }
    else if(digits[0] == anotherDec.digits[0] && digits[0] != '-' && digits.length() != anotherDec.digits.length()){
        if(digits.length() > anotherDec.digits.length()){
            ans = 1 ;
        }
        else if(digits.length() < anotherDec.digits.length()){
            ans = 0 ;
        }
    }
    else if(digits[0] == anotherDec.digits[0] && digits[0] == '-' && digits.length() == anotherDec.digits.length()){
        for(int i = 0 ; i < digits.length() ; i++){
            if(digits[i] != anotherDec.digits[i]){
                int a = (digits[i] - '0') , b = (anotherDec.digits[i] - '0') ;
                if( a > b ){
                    ans = 0 ;
                }
                else if( a < b ){
                    ans = 1 ;
                }
            }
        }
    }
    else if(digits[0] == anotherDec.digits[0] && digits[0] != '-' && digits.length() == anotherDec.digits.length()){
        for(int i = 0 ; i < digits.length() ; i++){
            if(digits[i] != anotherDec.digits[i]){
                int a = (digits[i] - '0') , b = (anotherDec.digits[i] - '0') ;
                if( a > b ){
                    ans = 1 ;
                }
                else if( a < b ){
                    ans = 0 ;
                }
            }
        }
    }

    return ans;
}


bool BigDecimalInt:: operator== (BigDecimalInt anotherDec){
    return digits == anotherDec.digits ;
}

BigDecimalInt& BigDecimalInt :: operator= (BigDecimalInt anotherDec){
    digits = anotherDec.digits ;
    return *this ;
}

int BigDecimalInt:: size(){
    if(digits[0] == '-' || digits[0] == '+' ){
        return digits.length() - 1 ;
    }
    else{
        return digits.length() ;
    }
}

int BigDecimalInt:: sign(){
    if( digits[0] == '-')
    {
        return -1 ;
    }
    else
    {
        return 1 ;
    }
}

ostream& operator << (ostream& out, BigDecimalInt b){
        out << b.digits ;
        return out ;
}

int main(){
    BigDecimalInt n1("-123");
    BigDecimalInt n2("3214");
    BigDecimalInt n3 = n1 + n2 ;
    cout << n3 << endl;
}
