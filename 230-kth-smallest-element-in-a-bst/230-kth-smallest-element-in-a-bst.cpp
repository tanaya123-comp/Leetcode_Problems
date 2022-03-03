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
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> st;
        TreeNode* p;
        p=root;
        while(p!=NULL)
        {
            st.push(p);
            p=p->left;
        }
        int count=0;
        while(!st.empty())
        {
            p=st.top();
            st.pop();
            
            count++;
            if(count==k)
            {
                break;
            }
            
            if(p->right!=NULL)
            {
                p=p->right;
                while(p!=NULL)
                {
                    st.push(p);
                    p=p->left;
                }
                
            }
        }
        return p->val;
        
    }
};