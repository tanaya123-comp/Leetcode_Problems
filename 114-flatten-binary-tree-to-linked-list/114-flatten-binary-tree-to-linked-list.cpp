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
    
    void preorder(TreeNode* root,queue<TreeNode*> &st)
    {
        if(root!=NULL)
        {
            st.push(root);
            preorder(root->left,st);
            preorder(root->right,st);
        }
    }
    
    void flatten(TreeNode* root) {
        
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        {
            return;
        }
        
        queue<TreeNode*> st;
        preorder(root,st);
        
        while(!st.empty())
        {
            TreeNode* t=st.front();
            st.pop();
            t->left=NULL;
            if(!st.empty())
            {
                t->right=st.front();
            }
            else
            {
                t->right=NULL;
            }
        }
        
        
    }
};