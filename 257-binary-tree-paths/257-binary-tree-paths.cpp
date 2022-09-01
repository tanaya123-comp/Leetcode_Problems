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
    
    void dp(TreeNode* root,vector<string> &ans,string temp)
    {
        if(root==NULL)
        {
            //ans.push_back(temp);
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
             if(temp=="")
                temp=temp+to_string(root->val);
            else
            {
            temp=temp+"->"+to_string(root->val);
            }
            ans.push_back(temp);
            return;
            
        }
        if(temp=="")
        temp=temp+to_string(root->val);
        else
        {
            temp=temp+"->"+to_string(root->val);
        }
        dp(root->left,ans,temp);
        dp(root->right,ans,temp);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string temp="";
        
        dp(root,ans,temp);
        return ans;
    }
};