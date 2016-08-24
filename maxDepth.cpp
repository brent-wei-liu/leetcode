int maxDepth(TreeNode* root) {
    if(root==NULL)  return 0;
    queue<TreeNode *> q;
    int depth = 0;
    q.push(root);
    q.push(NULL); 
    while(!q.empty()) {
        TreeNode * p = q.front();
        q.pop();
        if(p != NULL) {
            if(p->left  != NULL)  q.push(p->left);
            if(p->right != NULL)  q.push(p->right);
        }else{
            depth ++;
            if(!q.empty())  q.push(NULL);
        }
    }
    return depth;
}

