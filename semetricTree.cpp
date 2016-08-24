
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
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    bool helper(TreeNode* p1, TreeNode* p2){
        if(p1==NULL && p2==NULL)  return true;
        if(p1==NULL && p2!=NULL || p1!=NULL && p2==NULL || p1->val != p2->val)  return false;
        return helper(p1->left, p2->right) && helper(p1->right, p2->left);       
    }
};


bool isSymmetric(TreeNode* root) {
    if(root == NULL)  return false;
    int ret;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()) {
        TreeNode * left  = q.front();  q.pop();
        TreeNode * right = q.front();  q.pop();
        if(left == NULL && right == NULL)   continue;
        if(left==NULL && right!=NULL || left!=NULL && right==NULL || left->val!=right->val)   return false;
        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }
    return true;
}  

