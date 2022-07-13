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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int> > levelOrderTraversal;
        if(root==NULL)
            return levelOrderTraversal;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int siz=q.size();
            
            vector<int> level;
            
            while(siz--)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                level.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
            
            levelOrderTraversal.push_back(level);
        }
        
        return levelOrderTraversal;
    }
};