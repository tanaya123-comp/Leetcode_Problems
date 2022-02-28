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
        stack<TreeNode*> s;
        TreeNode* p;
        if(root==NULL)
        {
            return ans;
        }
        p=root;
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        while(!s.empty())
        {
            p=s.top();
            s.pop();
            ans.push_back(p->val);
            p=p->right;
            while(p!=NULL)
            {
                s.push(p);
                p=p->left;
            }
            
        }
        return ans;
        
        
    }
};