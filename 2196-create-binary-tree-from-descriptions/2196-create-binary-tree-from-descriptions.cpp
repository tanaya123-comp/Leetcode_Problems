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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        map<int,TreeNode*> valueNode;
        map<int,int> childParent;
        
        int n,i,parent,child,isLeft;
        n=descriptions.size();
        
        for(i=0;i<n;i++)
        {
            parent=descriptions[i][0];
            child=descriptions[i][1];
            isLeft=descriptions[i][2];
            TreeNode* p,*c;
            if(valueNode.find(parent)==valueNode.end())
            {
                p=new TreeNode(parent);
                valueNode[parent]=p;
            }
            else
            {
                p=valueNode[parent];
            }
            
             if(valueNode.find(child)==valueNode.end())
            {
                c=new TreeNode(child);
                valueNode[child]=c;
            }
            else
            {
                c=valueNode[child];
            }
            
            if(isLeft==1)
            {
                p->left=c;
            }
            else
            {
                p->right=c;
            }
            childParent[child]=parent;
        }
        
        for(i=0;i<n;i++)
        {
            if(childParent.find(descriptions[i][0])==childParent.end())
            {
                return valueNode[descriptions[i][0]];
            }
        }
        
        return NULL;
        
        
        
        
    }
};