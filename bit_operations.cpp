#include <iostream>
#include <stdint.h>
using namespace std;

void printBinary(uint32_t n)
{
    for(int i=0;i<32;i++){
        if (n & 1)
            cout<<"1";
        else
            cout<<"0";
        n >>= 1;
    }
    cout<<"\n";

}

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        cout<<"n:\t";
        printBinary( n );
        int i;
        uint32_t result = 0;
        for(i=1;i<=31;i++){

            if(n&1==1){
                result ++;
            }
            n = n>>1;
            result <<= 1;
            cout<<i<<"\t";
            printBinary( result );
        }
        if(n!=0) result ++;
        return result;
    }
};

int main()
{
    Solution s;
    uint32_t n = 2147483649;
    printBinary(s.reverseBits( n ));
    return 0;
}
