#include <iostream>
using namespace std;

    int getSum(int a, int b) {
        int bit = 1;
        int carry = 0;
        int sum = 0;
        int Sum[2][2][2] = { { {0, 1}, {1, 0} },
                             { {1, 0}, {0, 1} } 
                           };
        int Carry[2][2][2] = { { {0, 0}, {0, 1} },
                               { {0, 1}, {1, 1} } 
                             };

        for(int i=0; i<sizeof(int)*8; i++){
            int abit = a & bit;
            int bbit = b & bit;
            abit = abit == 0 ? 0 : 1;
            bbit = bbit == 0 ? 0 : 1;
            carry = carry == 0 ? 0 : 1;

            //cout <<"i=" << i << " abit=" << abit << " bbit=" << bbit << " carry=" << carry << endl;
            if(Sum[abit][bbit][carry])  sum |= bit;
            else    sum &= ~bit;
            
            carry = Carry[abit][bbit][carry];
            //cout << sum << "\t" << carry << endl;
            bit <<= 1;
        }
        return sum;
    }

int main() {
    // http://blog.yastrebkov.com/2012/01/how-to-set-clear-toggle-and-check.html
    int a = 1;
    for(int i=0; i<sizeof(int)*8 + 4; i++){
        cout << i <<"\t" << a << endl;
        a <<= 1;
    }
    
    cout << endl;
    unsigned int b = 1;
    for(int i=0; i<sizeof(unsigned int)*8 + 4; i++){
        cout << i << "\t" << b << endl;
        b <<= 1;
    }

    a = 1;
    int n = -1;
    for(int i=0; i<sizeof(int)*8; i++){
        cout << i << "\t" ;
        if(n & a)  cout<<"1";
        else       cout<<"0";
        cout << endl;
        a <<= 1;
    }

    cout<<endl;

    cout<<endl;
    int aa = 1; 
    int bb = 1;
    cout<<aa<<"+"<<bb<<"="<< getSum(aa, bb)<<endl<<endl;

    aa = 1; bb = -1;
    cout<<aa<<"+"<<bb<<"="<< getSum(aa, bb)<<endl<<endl;




}
