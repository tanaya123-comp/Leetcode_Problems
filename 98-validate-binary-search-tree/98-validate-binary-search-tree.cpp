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
    
    bool solve(TreeNode* root,long mini,long maxi)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val<maxi&&root->val>mini)
        {
            return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
        }
        else
        {
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        
        long  maxi=INT_MAX;
        maxi=maxi+1;
        long mini=INT_MIN;
        mini=mini-1;
        return solve(root,mini,maxi);
    }
};