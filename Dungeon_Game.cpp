#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {

        int i,j;
        int m = dungeon.size();
        int n = dungeon[m-1].size();
        vector<int> minHealth( dungeon[m-1].size(), 0 );
        minHealth[n-1] = 1-dungeon[m-1][n-1];
        for(j=n-2;j>=0;j--) {
            if(minHealth[j+1]<=0)   minHealth[j] = 1 - dungeon[m-1][j];
            else minHealth[j] = minHealth[j+1] - dungeon[m-1][j];
        }
        for(j=0;j<n;j++) cout<<minHealth[j]<<" ";
        cout<<endl;
           
        
        for(i=m-2;i>=0;i--){
            if(minHealth[n-1]<=0)    minHealth[n-1] = 1 - dungeon[i][n-1];
            else minHealth[n-1] -= dungeon[i][n-1];
            
            for(j=n-2;j>=0;j--){
                if (minHealth[j]<minHealth[j+1]){
                    if(minHealth[j]<=0)    minHealth[j] = 1-dungeon[i][j];
                    else    minHealth[j] = minHealth[j]-dungeon[i][j];
                }else{
                    if(minHealth[j+1]<=0)    minHealth[j] = 1-dungeon[i][j];
                    else    minHealth[j]  = minHealth[j+1]-dungeon[i][j];
                }
            }
            for(j=0;j<n;j++) cout<<minHealth[j]<<" ";
            cout<<endl;
        }

        if(minHealth[0] <= 0 )    return 1;
        else return minHealth[0];

    }
};
#define M 2
#define N 3
int main(int argc, char** argv)
{
    int i,j;
    int matrix[M][N] = {{3,-20,30},
                      {-3,4,0} };
    vector<vector<int> > d;
    for(i=0;i<M;i++){
        vector<int> temp;
        for(j=0;j<N;j++)   temp.push_back( matrix[i][j] );
        d.push_back(temp);
    }
    for(i=0;i<d.size();i++){
        for(j=0;j<d[i].size();j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    Solution s;
    cout<<"result:"<<s.calculateMinimumHP(d)<<endl;
    for(i=0;i<d.size();i++){
        for(j=0;j<d[i].size();j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
