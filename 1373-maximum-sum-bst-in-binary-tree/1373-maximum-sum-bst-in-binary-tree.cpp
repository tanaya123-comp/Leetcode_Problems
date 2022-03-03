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

class node {
    
    public:
        int mini;
        int maxi;
        bool isBST;
        int sum;
    
    node ()
    {
        mini=0;
        maxi=0;
        isBST=false;
        sum=0;
    }
    
    node(int mini,int maxi,bool isBST,int sum)
    {
        this->mini=mini;
        this->maxi=maxi;
        this->isBST=isBST;
        this->sum=sum;
    }
    
};

class Solution {
public:
    
    int currmax;
    
    node solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return *(new node(INT_MAX,INT_MIN,true,0));
        }
        
        if(root->left==NULL&&root->right==NULL)
        {
            cout<<root->val;
            currmax=max(currmax,root->val);
            return *(new node(root->val,root->val,true,root->val));
        }
        
        node left=solve(root->left);
        node right=solve(root->right);
        
        node* t;
        
        t=new node();
        
        if(left.isBST==true&&right.isBST==true&&root->val>left.maxi&&root->val<right.mini)
        {
            t->isBST=true;
            t->mini=min(root->val,min(left.mini,right.mini));
            t->maxi=max(root->val,max(left.maxi,right.maxi));
            t->sum=root->val+left.sum+right.sum;
            cout<<root->val<<"\n";
            currmax=max(currmax,t->sum);
        }
        else
        {
            t->isBST=false;
        }
        
        
        return *t;
    }
    
    int maxSumBST(TreeNode* root) {
        currmax=0;
        node p=solve(root);
        return currmax;
        
        
    }
};