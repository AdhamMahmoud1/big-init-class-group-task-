#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;


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
