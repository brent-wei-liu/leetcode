#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        string result;
        int pos = s.size()-1;

        for (int i=s.size()-1; i>=0; i--){
            if (s[i] == ' '){
                if (i < pos )
                    result +=s.substr(i+1,pos-i) + " ";
                pos = i - 1;
            }
            else if (i == 0)
                result += s.substr(0, pos+1) + " ";
        }
        s = result.substr(0,result.size()-1);
    }
};


int main()
{
    Solution s;
    string str = "one two three";
    s.reverseWords(str);
    cout<<str<<endl;
    str = "a";
    s.reverseWords(str);
    cout<<str<<endl;

    return 0; 
}
