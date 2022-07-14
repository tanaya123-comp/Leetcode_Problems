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
    
    unordered_map<int,int> mp;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &ptr,int start,int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[ptr]);
        
        ptr++;
        
        int index=mp[root->val];
        
        root->left=build(preorder,inorder,ptr,start,index-1);
        root->right=build(preorder,inorder,ptr,index+1,end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start=0;
        int end=preorder.size()-1;
        int ptr=0;
        mp.clear();
        
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,ptr,start,end);
        
    }
};