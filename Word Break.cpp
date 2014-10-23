#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
using namespace std;
class Solution {
public:
    bool debug;
    unordered_map<string,bool> presub;
    bool wordBreak(string s, unordered_set<string> &dict) {
        debug = false;
        if(debug) cout<<s<<endl;
        if(dict.count(s)>0) {
            if(debug) cout<<s<<" true"<<endl;
            return true;
        }
        for(int i=1; i<s.size(); i++){
            string pre = s.substr(0,i);
            string post = s.substr(i,s.size()-i);
            bool flagpre = false;
            bool flagpost = false;
            if(presub.count(pre)<=0)    flagpre = wordBreak( pre, dict);
            else    flagpre = presub[pre];             
            
            if(flagpre){
                if(presub.count(post)<=0)    flagpost = wordBreak( post, dict);
                else    flagpost = presub[post];                
                if(flagpost){
                    if(debug) cout<<s<<" true"<<endl;
                    presub[s] = true;
                    return true;
                }
            }
        }

        if(debug) cout<<s<<" false"<<endl;
        presub[s] = false;
        return false;
    }
};

int main()
{
    ifstream cin("Word Break test.txt");
    string str,s;
    unordered_set<string>  dict;
    cin>>s;
    while( cin>>str ){
        dict.insert(str);
    }
    Solution so;
    cout<<so.wordBreak(s, dict)<<endl;
    return 0;
}
