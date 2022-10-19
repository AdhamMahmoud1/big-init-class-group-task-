#include "BigInt.h"
using namespace std;
using namespace HelperFunctions;

//_______________
// Adham Mahmoud

BigDecimalInt::BigDecimalInt(string decStr){
    digits = "";
    if (decStr[0] == '-'){
        digits.push_back(decStr[0]);
        decStr.erase(decStr.begin());   
    }
    else if ( decStr[0] =='+'){
        decStr.erase(decStr.begin());
    }
    
    // if length of decStr  != 1, ans first char of it = 0 remove leading zeros
        for (int i = 0; i < decStr.size(); i++){   // This loop if the first digits are zeros
            if ((decStr.length() != 1) && (decStr[0] == '0')){
                decStr.erase(decStr.begin());
                continue;
            }
            else{
                decStr = decStr.substr(i, decStr.length() - i);
                break;
            }
        }
    
    for (int i = 0; i < decStr.size(); i++){
        if(!isdigit(decStr[i])){
            throw("Error");
        }
        digits.push_back(decStr[i]);
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

BigDecimalInt operator+ (BigDecimalInt num1, BigDecimalInt num2){
    string sum = "";
    if (num1.digits[0] == '-' && num2.digits[0] == '-'){  // This condition for adding two negative numbers
        sum.push_back('-');
        num1.digits.erase(num1.digits.begin() + 0);
        num2.digits.erase(num2.digits.begin() + 0);
    }
    if (num1.digits.size() > num2.digits.size()){
        swap(num1.digits, num2.digits);
    } 
    reverse(num1.digits.begin(), num1.digits.end()); // reversing the number two add digits from the smalleset to the greatest
    reverse(num2.digits.begin(), num2.digits.end());
    int len1 = num1.digits.size(), len2 = num2.digits.size();
    int carry = 0;
    int intSum;
    for (int i = 0; i < len1; i++){
        intSum = (num1.digits[i] - '0') + ((num2.digits[i] - '0') + carry);
        sum.push_back((intSum % 10) + '0');
        carry = intSum / 10;
    }
    for (int i = len1; i < len2 ; i++){  // If the number of digits of the number is greater than the other
        int intSum = ((num2.digits[i] - '0') + carry);
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
    BigDecimalInt bigSum("");
    bigSum.digits = sum;
    return bigSum;
}


//________________________
// Fady Kamal


string BigDecimalInt::get_digits()
{
    return digits;
}

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
            // note: iterate without including 0 >> to ignore - sign
            for (int i = 1; i < a.digits.length(); ++i)
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
            // iterate over both string and compare each correspoding digits
            for (int i = 0; i < a.digits.length(); ++i)
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


// - operator overloadin
BigDecimalInt operator-(BigDecimalInt &a, BigDecimalInt &b)
{

    // check if first smaller or not, incase swap
    bool is_first_smaller = (IsFirstSmaller(a, b));

    // get their digits and parse them to get rid of sign
    string a_str = ParseString(a.get_digits()), b_str = ParseString(b.get_digits());

    // to store answer within it  
    string ans;

    if ((IsPositive(a)) && (IsPositive(b)))
    {
        // sub regularly
        ans = find_diff(a_str, b_str, is_first_smaller);

        if (is_first_smaller)
        {
            ans = '-' + ans;
        }
    }

    else if ((IsPositive(a)) && (IsNegative(b)))
    {
        ans = find_sum(a_str, b_str);

        

    }

    else if ((IsNegative(a)) && (IsPositive(b)))
    {
        ans = '-' + find_sum(a_str, b_str);
    }
    
    // if both are negative
    else
    {
        // sub regularly
        ans = find_diff(a_str, b_str, !is_first_smaller);

        if (is_first_smaller)
        {
            ans = '-' + ans;
        }
    }

    BigDecimalInt final(ans);
    return final;
}



//________________________
// Mahmoud Mohamed

bool BigDecimalInt:: operator> (BigDecimalInt anotherDec)
{
    bool ans = false;

    if( digits[0] == '-' && anotherDec.digits[0] != '-'){
        ans = 0 ;
    }
    else if(digits[0] != '-' && anotherDec.digits[0] == '-'){
        ans = 1 ;
    }
    else if(anotherDec.digits[0] == '-' && digits[0] == '-' && digits.length() != anotherDec.digits.length()){
        ans = !(digits.length() > anotherDec.digits.length()) ;
    }
    else if(anotherDec.digits[0] != '-' && digits[0] != '-' && digits.length() != anotherDec.digits.length()){
        ans = (digits.length() > anotherDec.digits.length()) ;
    }
    else if(anotherDec.digits[0] == '-' && digits[0] == '-' && digits.length() == anotherDec.digits.length()){
        for(int i = 0 ; i < digits.length() ; i++){
            if(digits[i] != anotherDec.digits[i]){
                int a = (digits[i] - '0') , b = (anotherDec.digits[i] - '0') ;
                ans = !(a > b) ;
            }
        }
    }
    else if(anotherDec.digits[0] != '-' && digits[0] != '-' && digits.length() == anotherDec.digits.length()){
        for(int i = 0 ; i < digits.length() ; i++){
            if(digits[i] != anotherDec.digits[i]){
                int a = (digits[i] - '0') , b = (anotherDec.digits[i] - '0') ;
                ans = (a > b) ;
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


// new assin


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

// // insertion operator overloaing defination
// istream& operator >> (istream& in, BigDecimalInt &b)
// {
//     // declare string variable to store within it
//     string str;
//     in >> str;

//     // iteravte over string and append letters to b
//     for (int i = str.length() - 1; i >= 0; --i)
//     {
//         if (!isdigit(str[i]))
//         {
//             throw("Error");
//         }


//         // add char to end to digits of b
//         b.digits.push_back(str[i]);
        
//     }

//     return in; 

// }

