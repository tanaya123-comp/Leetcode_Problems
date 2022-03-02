/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    int height(Node* t)
    {
        if(t==NULL)
        {
            return 0;
        }
        int lh=height(t->left);
        int rh=height(t->right);
        
        return max(lh,rh)+1;
    }
    
    void levelOrder(Node* &root)
    {
        if(root==NULL)
        {
            return;
        }
        int h=height(root);
        Node* prev;
        for(int i=1;i<=h;i++)
        {
            prev=NULL;
            levelOrderRec(root,i,prev);
            if(prev)
            {
                prev->next=NULL;
            }
            cout<<"\n";
        }
    }
    
    void levelOrderRec(Node* &root,int h,Node* &prev)
    {
        if(root==NULL)
        {
            return;
        }
        else if(h==1)
        {
            if(prev==NULL)
            {
                cout<<root->val<<" ";
                prev=root;
            }
            else
            {
                cout<<prev->val<<" "<<root->val<<" ";
                prev->next=root;
                prev=root;
            }
        }
        else
        {
            levelOrderRec(root->left,h-1,prev);
            levelOrderRec(root->right,h-1,prev);
        }
        
    }
    
    Node* connect(Node* root) {
        
        levelOrder(root);
        return root;
    }
};