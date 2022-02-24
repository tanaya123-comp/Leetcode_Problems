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
    
    void split(ListNode* h,ListNode** a,ListNode** b)
    {
        
        ListNode* fast,*slow;
        fast=NULL;
        slow=NULL;
        slow=h;
        if(h->next!=NULL)
        fast=h->next;
        while(fast&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        *a=h;
        *b=slow->next;
        slow->next=NULL;
    }
    
    ListNode* merge(ListNode* a,ListNode* b)
    {
        ListNode* result=NULL;
        
        if(a==NULL)
        {
            return b;
        }
        
        if(b==NULL)
        {
            return a;
        }
        
        if(a->val<=b->val)
        {
            result=new ListNode(a->val);
            result->next=merge(a->next,b);
        }
        else
        {
            result=new ListNode(b->val);
            result->next=merge(a,b->next);
        }
        return result;
    }
    
    
    void solve(ListNode** head)
    {
        ListNode* h,*a,*b;
        
        h=*head;
        
        if(h==NULL||h->next==NULL)
        {
            return;
        }
        
        split(*head,&a,&b);
        
        solve(&a);
        
        solve(&b);
        
        *head=merge(a,b);
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        solve(&head);
        return head;
    }
};