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
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> rightSide;
        queue<TreeNode*> q;
        
        if(root==NULL)
        {
            return rightSide;
        }
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* t=q.front();
            //q.pop();
            
            rightSide.push_back(t->val);
            
            int siz=q.size();
            
            while(siz--)
            {
                TreeNode* t=q.front();
                q.pop();
                
                if(t->right!=NULL)
                {
                    q.push(t->right);
                }
                if(t->left!=NULL)
                {
                    q.push(t->left);
                }
                
            }
        }
        
        return rightSide;
        
        
    }
};