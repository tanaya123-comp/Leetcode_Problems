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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode*> s;
        TreeNode* p;
        p=root;
        while(p!=NULL)
        {
            ans.push_back(p->val);
            s.push(p);
            p=p->right;
        }
        while(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->left;
            while(p!=NULL)
            {
                ans.push_back(p->val);
                s.push(p);
                p=p->right;   
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};