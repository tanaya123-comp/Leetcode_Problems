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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* root;
        root=head;
        ListNode* h=NULL;
        ListNode* p=NULL,*q,*t;
        ListNode* curr,*prev,*next;
        int i=0;
        while(root!=NULL)
        {
            i=0;
            p=root;
            while(p!=NULL&&i<k)
            {
                q=p;
                p=p->next;
                i++;
            }
            if(i<k)
            {
                t->next=root;
                break;
            }
            q->next=NULL;
            
            curr=root;
            prev=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            
            if(h==NULL)
            {
                h=prev;
                t=root;
                root=p;
            }
            else
            {
                t->next=prev;
                t=root;
                root=p;
                
            }
            
        }
        return h;
    }
};