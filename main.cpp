#include <iostream>
#include "BigInt.h"
#include "BigInt.cpp"
using namespace std;


// Drive code
int main()
{   

    string first_, second_;
    cin >> first_ >> second_;
    BigDecimalInt first(first_), second(second_);


    if (first < second)
    {
        cout << first << " < " << second;
    }
    else
    {
        cout << first << " > " << second;
    }
    
    return 0;
}
