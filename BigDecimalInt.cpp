#include <iostream>
#include <string>
using namespace std;

class BigDecimalInt {
    private:
        string digits;
        char sign ;
    public:
        BigDecimalInt(string some_thing){
            digits = some_thing ;
        }

        bool operator> (BigDecimalInt anotherDec){
            for(int i = 0 ; i < anotherDec.digits.length() ; i++){
                
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
            if( sign == '-'){
                return -1 ;
            }
            else if(sign == '+'){
                return 1 ;
            }
        }
    
        friend ostream& operator << (ostream& out, BigDecimalInt b){
            out << b.digits ;
            return out ;
        }  
};

int main(){
//BigDecimalInt a("3246546") , b("-546878464");
    // cout<< a.sign() << " " ;
    // cout<< a.size() << " " ;
    // a = b ;
    // cout<< a ;
    // if( a == b )
    //     cout<< 1 ;
    // else
    //     cout<< 0 ;    
}
