/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode * p = q.pop();
            if(p == NULL) {
                ret.push_back(v);
                v.clear();
                q.push(NULL);
            }else{
                v.push_back(p->val);
                if(p->left  != NULL)  q.push(p->left);
                if(p->right != NULL)  q.push(p->right);
            }
        }
        ret.push_back(v);
        return ret;
    }
    
};

