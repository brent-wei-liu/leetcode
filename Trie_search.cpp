#include <string>
#include <iostream>

using namespace std;
class WordDictionary {
public:
    static const int N = 26;
    struct TrieNode{
        char c;
        bool wordEnd;
        TrieNode *nexts[N];
        TrieNode(char ch):c(ch){
            for(int i=0;i<N;i++)     nexts[i] = NULL;
        };
        TrieNode(){
            for(int i=0;i<N;i++)     nexts[i] = NULL;
        };
    };
    TrieNode * root;
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * p,*pre = root;
        char ch;
        for(int i=0;i<word.length();i++){
            ch = word[i];
            p = pre->nexts[ch-'a'];
            if(p==NULL){
                p =  new TrieNode(ch);
                pre->nexts[ch-'a'] = p;
            }
            pre = p;
        }
        pre->wordEnd = true;
    }

    bool matchhere(TrieNode *node, string pattern){
        if(node==NULL) return false;
        if(pattern.length()==1 && (pattern[0]=='.' || pattern[0] == node->c) && node->wordEnd)  return true;
//        cout<<"matchhere("<<node->c<<" ,"<<pattern<<")"<<endl;
        if(pattern[0]=='.' || pattern[0] == node->c)  {
            string sub = pattern.substr(1,pattern.length()-1);
            for(int i=0;i<N;i++){
//                cout<<"node->nexts[i]:"<<node->nexts[i]<<"  sub:"<<sub<<endl;
                if(matchhere(node->nexts[i],sub)==true)   {
                    return true;
                }
            }
            return false;
        }
    }
    bool search(string word) {
        for(int i=0;i<N;i++){
            if(matchhere(root->nexts[i],word)==true)   {
                return true;
            }
        }
        return false;
    }
    void printTrie()
    {
        printTrie(root);
    }
    void printTrie(TrieNode *node){
        TrieNode* p;
        cout<<node->c;
        if(node->wordEnd)  cout<<"$";
        cout<<"(";
        for(int i=0;i<N;i++){
            p = node->nexts[i];
            if(p!=NULL) printTrie(p);
        }
        cout<<')';
    }
};

int main()
{
    WordDictionary w;
;w.addWord("nsx")
;w.addWord("nsy")
;w.addWord("nsz")
;w.addWord("nta")
;w.addWord("ntb")
;w.addWord("ntc")
;w.addWord("ntd")
;w.addWord("nte")
;w.addWord("ntf")
;w.addWord("ntg")
;w.addWord("nth")
;w.addWord("nti")
;w.addWord("ntj")
;w.addWord("ntk")
;w.addWord("ntl")
;w.addWord("ntm")
;w.addWord("ntn")
;w.addWord("nto")
;w.addWord("ntp");
    w.printTrie();
    cout<<endl;
/*    cout<<w.search(".")<<endl;
    cout<<w.search("a")<<endl;
    cout<< w.search("aa")<<endl;
    cout<<w.search("a")<<endl;
    cout<<w.search(".a")<<endl;
    */
    cout<<w.search(".")<<endl;
    return 1;
}
    


