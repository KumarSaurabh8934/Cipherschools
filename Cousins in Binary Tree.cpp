class Solution {
public:
    int parent(TreeNode * root,int x)
    {
        if(root==NULL)
        {
            return -1;
        }
        if(root->left!=NULL && root->left->val==x)
        {
            return root->val;
        }
        
        if(root->right!=NULL && root->right->val==x)
        {
            return root->val;
        }
        
        int a= parent(root->left,x);
        if(a!=-1)
        {
            return a;
        }
        int b= parent(root->right,x);
        if(b!=-1)
        {
            return b;
        }
       return -1; 
    }
    int depth(TreeNode *root, int x,int d)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->val==x)
        {
            return d;
        }
        
        int a= depth(root->left,x,d+1);
        if(a!=0)
        {
            return a;
        }
        int b= depth(root->right,x,d+1);
        if(b!=0)
        {
            return b;
        }
        return 0;
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
       int p1= parent(root, x);
        int p2= parent(root, y);
        int d1= depth(root, x,0);
        int d2=depth(root, y,0);
        if(d1==d2 && p1!=p2)
        {
            return true;
        }
        else return false;
    }
};
