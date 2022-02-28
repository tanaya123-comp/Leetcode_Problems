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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        TreeNode* p,*q,*t;
        p=root;
        while(p!=NULL)
        {
            if(p->left==NULL)
            {
                ans.push_back(p->val);
                p=p->right;
            }
            else
            {
                t=p->left;
                while(t->right!=NULL&&t->right!=p)
                {
                    t=t->right;
                }
                if(t->right==NULL)
                {
                    t->right=p;
                    p=p->left;
                }
                else
                {
                    ans.push_back(p->val);
                    t->right=NULL;
                    p=p->right;
                }
            }
        }
        return ans;   
    }
};