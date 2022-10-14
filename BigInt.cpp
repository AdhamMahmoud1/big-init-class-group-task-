#include <iostream>
#include <string>
#include "BigInt.h"

using namespace std;

BigDecimalInt::BigDecimalInt(string decStr): digits(decStr){
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


// I think it's not compeleted yet.
BigDecimalInt& BigDecimalInt:: operator+ (BigDecimalInt num1){
    string sum = ""; // Here I will put the sum of two big numbers
    if (digits.size() > num1.digits.size()){
        swap(digits, num1.digits);
    }
    reverse(num1.digits.begin(), num1.digits.end());
    reverse(digits.begin(), digits.end());
    int len1 = digits.size(), len2 = num1.digits.size();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;
    for (int i = len1 - 1; i <= 0; i--){
        intSum = (digits[i] - '0') + ((num1.digits[i] - '0') + carry);
        sum.push_back((intSum % 10) - '0');
        carry = intSum / 10;
    }
    for (int i= len1; i< len2; i++)
    {
        int intSum = ((num1.digits[i]-'0')+carry);
        sum.push_back(intSum%10 + '0');
        carry = intSum/10;
    }
    if (carry){
        sum.push_back(carry+'0');
    }
    reverse(sum.begin(), sum.end());
    digits = sum;
    return *this;
}


bool BigDecimalInt:: operator> (BigDecimalInt anotherDec){
            if( digits[0] == '-' && anotherDec.digits[0] != '-'){
                return 0 ;
            }
            else if(digits[0] != '-' && anotherDec.digits[0] == '-'){
                return 1 ;
            }
            else if(digits[0] == anotherDec.digits[0] && digits[0] == '-' && digits.length() != anotherDec.digits.length()){
                if(digits.length() > anotherDec.digits.length()){
                    return 0 ;
                }
                else if(digits.length() < anotherDec.digits.length()){
                    return 1 ;
                }
            }
            else if(digits[0] == anotherDec.digits[0] && digits[0] != '-' && digits.length() != anotherDec.digits.length()){
                if(digits.length() > anotherDec.digits.length()){
                    return 1 ;
                }
                else if(digits.length() < anotherDec.digits.length()){
                    return 0 ;
                }
            }
            else if(digits[0] == anotherDec.digits[0] && digits[0] == '-' && digits.length() == anotherDec.digits.length()){
                for(int i = 0 ; i < digits.length() ; i++){
                    if(digits[i] != anotherDec.digits[i]){
                        int a = (digits[i] - '0') , b = (anotherDec.digits[i] - '0') ;
                        if( a > b ){
                            return 0 ;
                        }
                        else if( a < b ){
                            return 1 ;
                        }
                    }
                }
            }
            else if(digits[0] == anotherDec.digits[0] && digits[0] != '-' && digits.length() == anotherDec.digits.length()){
                for(int i = 0 ; i < digits.length() ; i++){
                    if(digits[i] != anotherDec.digits[i]){
                        int a = (digits[i] - '0') , b = (anotherDec.digits[i] - '0') ;
                        if( a > b ){
                            return 1 ;
                        }
                        else if( a < b ){
                            return 0 ;
                        }
                    }
                }
            }        
        }
    
bool BigDecimalInt:: operator== (BigDecimalInt anotherDec){
            return digits == anotherDec.digits ;
}
BigDecimalInt& BigDecimalInt ::operator= (BigDecimalInt anotherDec){
            digits = anotherDec.digits;
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
            if( digits[0] == '-'){
                return -1 ;
            }
            else if(digits[0] == '+'){
                return 1 ;
            }
}
    
ostream& operator << (ostream& out, BigDecimalInt b){
            out << b.digits ;
            return out ;
}  
