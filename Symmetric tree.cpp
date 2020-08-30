class Solution {
public:

bool The_Same(TreeNode*Right , TreeNode*Left)
{
    if (!Right||!Left)
        return (Right==Left) ;
    else if (Right->val!=Left->val)
        return 0 ;
    return The_Same(Right->right , Left->left) && The_Same(Right->left , Left->right) ;
}
bool isSymmetric(TreeNode* root) {
    if (!root)
        return true ;
    return The_Same(root->right , root->left) ;
}
};
