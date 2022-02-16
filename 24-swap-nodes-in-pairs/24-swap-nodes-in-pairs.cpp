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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* curr,*prev,*next;
        ListNode* head1,*p;
        prev=NULL;
        curr=head;
        next=head->next;
        head1=head;
        while(curr!=NULL&&next!=NULL)
        {
            if(prev!=NULL)
            {
                prev->next=next;
                prev=curr;
                curr=next->next;
                next->next=prev;  
                if(curr!=NULL)
                {
                    next=curr->next;
                   // curr->next=NULL;
                }
                else
                {
                   //rev->next=curr;
                    next=NULL;
                }
                prev->next=NULL;
                
            }
            else
            {
                head1=next;
                p=next->next;
                next->next=curr;
                prev=curr;
                curr=p;
                if(curr!=NULL)
                {
                    next=curr->next;
                   // prev->next=NULL;
                  //  curr->next=NULL;
                }
                
                else
                {
                  //rev->next=curr;
                    next=NULL;
                }
                prev->next=NULL;
                
            }
            if(curr!=NULL&&next==NULL)
            {
                prev->next=curr;
            }
        }
       
        return head1;
        
    }
};