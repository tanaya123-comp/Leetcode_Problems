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
    
    int getMaxPathSum(TreeNode* root,int &maxpathsum)
    {
        if(root==NULL)
            return 0;
        
        int left=getMaxPathSum(root->left,maxpathsum);
        int right=getMaxPathSum(root->right,maxpathsum);
        
        maxpathsum=max(maxpathsum,root->val);
        maxpathsum=max(maxpathsum,root->val+left);
        maxpathsum=max(maxpathsum,root->val+right);
        maxpathsum=max(maxpathsum,root->val+right+left);
        return max(root->val,max(root->val+left,root->val+right));
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int maxpathsum=INT_MIN;
        int x=getMaxPathSum(root,maxpathsum);
        return maxpathsum;
    }
};