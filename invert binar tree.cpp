class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->left = right;
        root->right=left;
        return root;
    }
};
