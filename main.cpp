#include <iostream>
#include "BigInt.h"
#include "BigInt.cpp"
using namespace std;


// Drive code
int main()
{   
    BigDecimalInt first("454454"), second("45445");
    cin >> first >> second;


    if (first > second)
    {
        cout << first << " > " << second;
    }
    else
    {
        cout << first << " < " << second;
    }
    
    return 0;
}