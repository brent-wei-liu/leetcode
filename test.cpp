#include <iostream>
#include <vector>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,d,in,i;
    vector<int> v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }
    d = (v[n-1] - v[0])/n;
    for(i=0;i<n-1;i++){
        if(v[i+1] != v[i]+d){
            cout<<v[i]+d;
            break;
        }
    }
    
    return 0;
}

