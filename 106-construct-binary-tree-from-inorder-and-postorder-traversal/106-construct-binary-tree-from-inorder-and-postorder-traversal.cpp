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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[curr_index]);
        curr_index--;
        int index=mp[root->val];
        root->right=solve(inorder,postorder,index+1,end);
        root->left=solve(inorder,postorder,start,index-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        if(n==0)
        {
            return NULL;
        }
        for(int i=0;i<n;i++)
        {
            mp.insert({inorder[i],i});
        }
        curr_index=n-1;
        return solve(inorder,postorder,0,n-1);
        
    }
};