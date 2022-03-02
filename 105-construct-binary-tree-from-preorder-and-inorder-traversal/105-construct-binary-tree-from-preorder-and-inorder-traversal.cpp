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
    int curr_index;
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[curr_index]);
        curr_index++;
        int i=mp[root->val];
        root->left=solve(preorder,inorder,start,i-1);
        root->right=solve(preorder,inorder,i+1,end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        if(n==0)
        {
            return NULL;
        }
        for(int i=0;i<n;i++)
        {
            mp.insert({inorder[i],i});
        }
        curr_index=0;
        return solve(preorder,inorder,0,n-1);
        
    }
};