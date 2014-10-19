#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        string t;
        int a,b,num;
        vector<int> stack;
        for(int i=0; i<tokens.size(); i++){
            t = tokens[i];
            num = 1;
            num = atoi(t.c_str());
            if(t.compare("0")==0){
                num = 0;
                stack.push_back(num);
            }else if( num == 0){
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                if(t.compare("+")==0){
                    stack.push_back( a + b);
                }else if(t.compare("-")==0){
                    stack.push_back( a - b);
                }else if(t.compare("*")==0){
                    stack.push_back( a * b);
                }else if(t.compare("/")==0){
                    stack.push_back( a / b);
                }
            }else{
                stack.push_back(num);
            }
        }
        return stack[0];
    }
};
int main(){
    vector<string> tokens;
    tokens.push_back(string("4"));
    tokens.push_back(string("3"));
    tokens.push_back(string("-"));
    Solution s;
    cout<< s.evalRPN(tokens)<<endl;
    return 0;
}
