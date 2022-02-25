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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        ListNode* head=NULL,*prev;
        ListNode* h1,*h2;
        h1=list1;
        h2=list2;
        while(h1!=NULL&&h2!=NULL)
        {
            if(h1->val<h2->val)
            {
                if(head==NULL)
                {
                    head=h1;
                    prev=h1;
                    h1=h1->next;
                    prev->next=NULL;
                }
                else
                {
                    prev->next=h1;
                    h1=h1->next;
                    prev=prev->next;
                    prev->next=NULL;
                }
            }
            else
            {
                 if(head==NULL)
                {
                    head=h2;
                    prev=h2;
                    h2=h2->next;
                    prev->next=NULL;
                }
                else
                {
                    prev->next=h2;
                    h2=h2->next;
                    prev=prev->next;
                    prev->next=NULL;
                }
            }
            
        }
        if(h1!=NULL)
        {
            prev->next=h1;
        }
        if(h2!=NULL)
        {
            prev->next=h2;
        }
        return head;
        
    }
};