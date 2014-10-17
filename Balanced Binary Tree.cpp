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
    bool isBal;
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        isBal = true;
        postOrder(root, 0);
        return isBal;
    }
    int postOrder(TreeNode *p, int depth){
        int maxD, minD;
        depth ++;
        if(!isBal) return depth;
        if(p == NULL) return depth;
        maxD = postOrder(p->left, depth);
        minD =  postOrder(p->right, depth);
        if(minD>maxD){
            int tmp = maxD;
            maxD = minD;
            minD = tmp;
        }
        
        if( maxD - minD > 1){
            isBal = false;
        }
        return maxD;
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

    cout<< s.isBalanced(&root)<<endl;
    

    return -1;
}
