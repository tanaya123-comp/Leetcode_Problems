/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* t)
    {
        ListNode* prev,*curr,*next;
        prev=NULL;
        curr=t;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    
    int count(ListNode* root)
    {
        int len=0;
        while(root!=NULL)
        {
            len++;
            root=root->next;
        }
        return len;
    }
    
    
    
    
    
    
    bool isPalindrome(ListNode* head) {
        
        int n=count(head);
        int mid=(n/2)+(n%2);
        
        ListNode* p=head;
        for(int i=0;i<mid-1;i++){
            p=p->next;
        }
        
        p->next=reverse(p->next);
        
        ListNode* q=p->next;
        
        p=head;
        
        
        
        while(p!=NULL&&q!=NULL)
        {
            if(p->val!=q->val)
            {
                return false;
            }
            p=p->next;
            q=q->next;
        }
        return true;
       
        
         
    }
};