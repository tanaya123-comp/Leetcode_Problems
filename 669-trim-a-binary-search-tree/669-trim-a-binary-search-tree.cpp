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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root==NULL)
            return NULL;
        
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        
        if(root->val>=low&&root->val<=high)
        {
            return root;
        }
        
        if(root->left==NULL)
        {
            return root->right;
        }
        if(root->right==NULL)
        {
            return root->left;
        }
        
        
        TreeNode* temp=root->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        temp->left=root->left;
        return root;
    }
};