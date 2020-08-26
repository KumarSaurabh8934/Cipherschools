
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        int mn=min(p->val,q->val),mx=max(p->val,q->val);
        if(root->val>=mn and root->val<=mx)return root;
        else if(mn<=root->val and mx<=root->val)
            return lowestCommonAncestor(root->left,p,q);
        else
            return lowestCommonAncestor(root->right,p,q);
    }
};
