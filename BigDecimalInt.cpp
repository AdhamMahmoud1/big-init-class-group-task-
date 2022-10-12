#include <iostream>
#include <string>
using namespace std;

class BigDecimalInt {
    private:
        string digits;
    public:
        BigDecimalInt(string some_thing){
            digits = some_thing ;
        }

        bool operator> (BigDecimalInt anotherDec){
            for(int i = 0 ; i < anotherDec.digits.length() ; i++){
                
            }
        }
    
bool operator> (BigDecimalInt anotherDec){
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
    
        bool operator== (BigDecimalInt anotherDec){
            return digits == anotherDec.digits ;
        }

        BigDecimalInt& operator= (BigDecimalInt anotherDec){
            digits = anotherDec.digits;
            return *this ;
        }

        int size(){
            if(digits[0] == '-' || digits[0] == '+' ){
                return digits.length() - 1 ;
            }
            else{
                return digits.length() ;    
            }
        }

        int sign(){
            if( digits[0] == '-'){
                return -1 ;
            }
            else if(digits[0] == '+'){
                return 1 ;
            }
        }
    
        friend ostream& operator << (ostream& out, BigDecimalInt b){
            out << b.digits ;
            return out ;
        }  
};

int main(){
   
}
