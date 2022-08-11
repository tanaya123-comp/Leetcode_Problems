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
    
    bool isValid(TreeNode* root,long mini,long maxi)
    {
        if(root==NULL)
            return true;
        
        if(root->val>mini&&root->val<maxi)
        {
            return isValid(root->left,mini,root->val)&&isValid(root->right,root->val,maxi);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        
        long mini=INT_MIN;
        mini=mini-1;
        long maxi=INT_MAX;
        maxi=maxi+1;
        
        return isValid(root,mini,maxi);
        
    }
};