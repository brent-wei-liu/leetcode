#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;


class Solution {
struct Node{
    int count;
    struct Node *pA, *pC, *pG, *pT;
    Node():count(0), pA(NULL), pC(NULL), pG(NULL), pT(NULL){}
};

public:
    vector<string> findRepeatedDnaSequences(string s) {
        Node head, *p, **pChild;
        vector<string> result;
        if(s.length()<=10)   return result;
        for(int i=0;i<s.length()-10;i++){
            p = &head;
            for( int j=i;j<10;j++){
                switch(s[j])
                {
                    case 'A':
                        pChild = &p->pA;
                        break;
                    case 'C':
                        pChild = &p->pA;
                        break;
                    case 'G':
                        pChild = &p->pA;
                        break;
                    case 'T':
                        pChild = &p->pA;
                        break;
                }
                if(*pChild == NULL){
                    *pChild = new Node;
                }
                if(j==9)    (*pChild)->count++;

            }
        }
        
        return result;
        
    }
};

int main(int argc, char** argv)
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solution;
    vector<string> re = solution.findRepeatedDnaSequences( s );
    for(int i=0; i<re.size(); i++){
        cout<<re[i]<<endl;
    }

    return 0;
}
