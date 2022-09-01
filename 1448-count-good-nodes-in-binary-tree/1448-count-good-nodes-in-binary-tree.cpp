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
    
    void goodNodesRec(TreeNode* root,int& ans,int x)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=x)
        {
            x=max(x,root->val);
            ans++;
        }
        goodNodesRec(root->left,ans,x);
        goodNodesRec(root->right,ans,x);
    }
    
    int goodNodes(TreeNode* root) {
        
        int ans=0;
        int x=INT_MIN;
        goodNodesRec(root,ans,x);
        return ans;
    }
};