class Solution {
public:
    int result;
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        result = max(result, left + right);
        return max(left, right)+1;
    }
};
