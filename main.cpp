#include <iostream>
#include "BigInt.h"
#include "BigInt.cpp"
using namespace std;


// Drive code
int main()
{   
    BigDecimalInt first("-34564454"), second("45445");



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
