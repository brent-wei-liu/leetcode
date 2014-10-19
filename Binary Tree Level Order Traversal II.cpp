#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
       vector<vector<int> > result;
       queue<TreeNode*> q;
       vector<int> level;
       TreeNode *p, *nextLevel;
       bool flag = false;
       if(root == NULL) return result;
       q.push(root);
       if(root->left == NULL)    nextLevel = root->right;
       else    nextLevel = root->left;
       while(q.size() != 0 ){
           p = q.front();
           q.pop();
           if(p == nextLevel){
               result.push_back(level);
               level.clear();
               flag = true;
           }
           level.push_back(p->val);// bug 1: anyway p->val must be pushed in the level
           if(p->left != NULL){
               q.push(p->left);
               if(flag){
                   nextLevel = p->left;
                   flag = false;
               }
           }
           if(p->right != NULL){
               q.push(p->right);
               if(flag){
                   nextLevel = p->right;
                   flag = false;
               }
           }
       }
       if(level.size() != 0)    result.push_back(level);
       reverse(result.begin(), result.end());
       return result;
    }
};
int main()
{
    Solution s;
    TreeNode *a, *b;
    TreeNode root(1);
    a = new TreeNode(2);
    a->right = new TreeNode(3);
    root.left = a;
    vector<vector<int> > result = s.levelOrderBottom(&root);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


    return -1;
}



