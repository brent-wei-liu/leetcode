#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        long n = numerator;
        long d = denominator;
        result = to_string(n/d) + ".";
        n %= d; 

        long lastN = n;
        while(n<d && n!=0)    n*=10;
        long lastQuotient = n/d;
        long quotient;
        n %= d;
        while(n!=0){
            cout<<lastQuotient<<endl;
            break;
            while(n<d)    n*=10;
            quotient = n/d;
            n %= d;
            if(lastQuotient == quotient)  {
                result += "(" + to_string(lastQuotient) + ")";
                break;
            }else{
                result += to_string(lastQuotient);
                lastQuotient = quotient;
            }
        }
        return  result;
    }
};

int main(int argv, char ** argc)
{
    Solution s;
    cout<<s.fractionToDecimal( 1 , 19 )<<endl;
    return 0;
}
