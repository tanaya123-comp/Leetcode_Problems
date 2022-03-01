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
    int widthOfBinaryTree(TreeNode* root) 
    {
       TreeNode* t;
       queue<pair<TreeNode*,int> > q;
       if(root==NULL)
       {
           return 0;
       }
       int ans=0;
       q.push({root,1});
       while(!q.empty())
       {
           int size=q.size();
           
           int first_node_index=q.front().second;
           
           int mn,mx;
           for(int i=0;i<size;i++)
           {
               int curr_index=q.front().second-first_node_index+1;
               pair<TreeNode*,int> p=q.front();
               q.pop();
               
               if(curr_index==1)
               {
                   mn=curr_index;
               }
               if(i==size-1)
               {
                   mx=curr_index;
               }
               
               if(p.first->left!=NULL)
               {
                   q.push({p.first->left,2LL*curr_index});
                   
               }
               if(p.first->right!=NULL)
               {
                   q.push({p.first->right,2LL*curr_index+1});
               }
           }
           ans=max(ans,mx-mn+1);
           
       }
        return ans;
        
    }
};