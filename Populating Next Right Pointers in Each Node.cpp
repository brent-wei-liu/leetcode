#include <iostream>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p,*currentLevel;
        root->next = NULL;
        currentLevel = root;
        p = root;
        while(p!=NULL){
            if(p->left!=NULL){
                p->left->next = p->right;
            }
            if(p->right!=NULL && p->next!=NULL){
                p->right->next = p->next->left;
            }
            p = p->next;
            if(p==NULL){
                p = currentLevel->left;
                currentLevel = p;
            }
        }
    }
};

int main()
{
    Solution s;
    TreeLinkNode *a, *b;
    TreeLinkNode root(1);
    a = root.left = new TreeLinkNode(2);
    b = root.right = new TreeLinkNode(3);
    a->left = new TreeLinkNode(4);
    b->right = new TreeLinkNode(5);

    s.connect(&root);
    
    cout<<a->next<<endl;
    cout<<b->next<<endl;
    return 0;
}
