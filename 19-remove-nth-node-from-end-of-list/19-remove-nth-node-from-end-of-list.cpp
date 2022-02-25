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
    
   
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int siz=0;
        ListNode* h;
        h=head;
        while(h!=NULL)
        {
            siz++;
            h=h->next;
        }
        int i=0;
        h=head;
        ListNode* prev=NULL;
        while(i<(siz-n)&&h!=NULL)
        {
            prev=h;
            h=h->next;
            i++;
        }
        if(prev!=NULL)
        {
            prev->next=h->next;
        }
        else
        {
            head=head->next;
        }
        return head;
        
    }
};