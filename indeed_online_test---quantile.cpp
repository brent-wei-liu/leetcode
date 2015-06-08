#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int value;
    int count;
};
bool myComp(Node a,Node b)
{
    return a.value < b.value;
}
int main()
{
    int M,Q,v,c,i,j,N;
    ifstream cin("in.txt");
    vector<Node> V;
    cin>>Q>>M;
    for(i=0;i<M;i++){
        cin>>v>>c;
        Node node;
        node.value = v;
        node.count = c;
        V.push_back( node );
    }
    sort(V.begin(), V.end(), myComp);
    V[0].count --;
    for(i=1;i<V.size();i++){
        V[i].count += V[i-1].count;
        cout<<V[i].value<<" "<<V[i].count<<endl;
    }
    cout<<endl;
    N = V[V.size()-1].count + 1;
    int k = 1;
    int l = N*k/Q -1;
    while(l<N && k<Q){
        for(i=0;V[i].count<=l;i++){
        }
        if(i>0 && l==V[i-1].count) i = i-1;
        cout<<l<<" V["<<i<<"]="<<V[i].value<<endl;
        k++;
        l = N*k/Q - 1;
    }
    return 0;
}

