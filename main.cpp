#include <iostream>
#include "BigInt.h"
#include "BigInt.cpp"
using namespace std;


// Drive code
int main()
{   
<<<<<<< HEAD

    string first_, second_;
    cin >> first_ >> second_;
    BigDecimalInt first(first_), second(second_);
=======
    BigDecimalInt first("-34564454"), second("45445");

>>>>>>> b485c3d25da3d85f98c141c99bfa65260e605cd2


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
