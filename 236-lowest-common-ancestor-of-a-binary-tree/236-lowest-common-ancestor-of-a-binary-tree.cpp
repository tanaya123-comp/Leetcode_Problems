/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* LCA_rec(TreeNode* root,int x,int y)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==x||root->val==y)
        {
            return root;
        }
        TreeNode* left=LCA_rec(root->left,x,y);
        TreeNode* right=LCA_rec(root->right,x,y);
        if(left!=NULL&&right!=NULL)
        {
            return root;
        }
        if(left==NULL)
        {
            return right;
        }
        return left;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
        {
          return NULL;  
        }
        int x=p->val;
        int y=q->val;
        return LCA_rec(root,x,y);
        
    }
};