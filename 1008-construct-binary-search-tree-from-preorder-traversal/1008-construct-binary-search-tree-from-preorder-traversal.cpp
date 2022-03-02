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
    

    
    TreeNode* solve(vector<int>& preorder,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[start]);
        if(start==end)
        {
            return root;
        }
        int i;
        for(i=start+1;i<=end;i++)
        {
            if(preorder[i]>root->val)
            {
                break;
            }
        }
        root->left=solve(preorder,start+1,i-1);
        root->right=solve(preorder,i,end);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        if(n==0)
        {
            return NULL;
        }
        return solve(preorder,0,n-1);
        
        
    }
};