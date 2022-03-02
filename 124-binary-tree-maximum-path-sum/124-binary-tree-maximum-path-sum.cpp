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
    
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=solve(root->left,ans);
        int rh=solve(root->right,ans);
        ans=max(ans,root->val);
        ans=max(ans,max(lh+root->val,rh+root->val));
        ans=max(ans,lh+rh+root->val);
        return max(max(lh+root->val,rh+root->val),root->val);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int ans=INT_MIN;
        if(root==NULL)
        {
            return 0;
        }
        int sum=solve(root,ans);
        return ans;
    }
};