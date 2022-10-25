#include <iostream>
#include "BigInt.h"
#include "BigInt.cpp"
using namespace std;


// Drive code
int main()
{   

    // string first_, second_;
    // cin >> first_ >> second_;
    // BigDecimalInt first(first_), second(second_);

    // // testing of - operator
    // cout << first - second << endl;   

    // if (first < second)
    // {
    //     cout << first << " < " << second;
    // }
    // else
    // {
    //     cout << first << " > " << second;
    // }

    BigDecimalInt a("326") , b("-121") , c ;
    // cout << a << " " << b << " " << c << endl ;
    // c = b ;
    // cout<< c ;
    //cout<< a.sign() << "\n" ;
    //cout<< a.size() ;
    //cout <<  ( a == b ) ;


    // if( a < b ){
    //     cout<< 1 ;
    // }
    // else{
    //     cout<< 0 ;
    // }

    cout << a-b  << endl;
    cout << a  << endl;
    cout<< b ;

    return 0;
}
