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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {  
       if(root==NULL)
       {
           return NULL;
       }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            TreeNode* p=root;
            delete p;
            return NULL;
        }
        else if(root->left==NULL)
        {
            TreeNode* p=root;
            TreeNode* q=root->right;
            delete p;
            return q;
        }
        else if(root->right==NULL)
        {
            TreeNode* p=root;
            TreeNode* q=root->left;
            delete p;
            return q;
        }
        TreeNode* p=root->right;
        TreeNode* q;
        while(p->left!=NULL)
        {
            p=p->left;
        }
        root->val=p->val;
        root->right=deleteNode(root->right,p->val);
        return root;
    }
};