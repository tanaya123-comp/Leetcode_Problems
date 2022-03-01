/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int solve(TreeNode* root,bool &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=solve(root->left,ans);
        int rh=solve(root->right,ans);
        if(abs(lh-rh)>1)
        {
            ans=false;
        }
        return max(lh,rh)+1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        bool ans=true;
        if(root==NULL)
        {
            return ans;
        }
        int h=solve(root,ans);
        return ans;
    }
};