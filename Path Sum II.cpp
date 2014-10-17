#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > results;
        preOrder(root, 0 ,sum, path, results);
        return results;
    }
    
    void preOrder(TreeNode *p, int parentSum, int sum, vector<int> &path, vector<vector<int> > &results){
        int currentSum;
        if(p == NULL) return;
        currentSum = p->val + parentSum;
        path.push_back(p->val);
        if(p->left == NULL && p->right == NULL){
            if(currentSum == sum){
                results.push_back(path);
            } 
            path.pop_back();
            return;
        }
        preOrder(p->left, currentSum, sum, path, results);
        preOrder(p->right,currentSum, sum, path, results);
        path.pop_back();
        return;
    }
};

int main()
{
    cout<<"Hello"<<endl;
    Solution s;
    TreeNode *a, *b;
    TreeNode root(1);
    a = new TreeNode(2);
    root.left = a;

    vector<vector<int> > results = s.pathSum(&root, 3);
    
    for(int i= 0; i<results.size(); i++){
        for(int j = 0; j<results[i].size(); j++){
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }


    return -1;
}
