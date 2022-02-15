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
    
    int sizeOfList(ListNode* head)
    {
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=sizeOfList(head);
        int x=len-n+1;
        int num=0;
        ListNode* t,*prev;
        t=head;
        prev=NULL;
        while(t!=NULL)
        {
            num++;
            if(num==x)
            {
                break;
            }
            prev=t;
            t=t->next;
        }
        if(prev!=NULL)
        prev->next=t->next;
        else{
            head=head->next;
        }
        return head;
    }
};