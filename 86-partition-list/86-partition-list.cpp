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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* t1,*t2,*head1,*head2;
        head1=NULL;
        head2=NULL;
        t1=NULL;
        t2=NULL;
        
        ListNode* root=head;
        while(root!=NULL)
        {
            if(root->val<x)
            {
                if(t1==NULL)
                {
                    t1=root;
                    head1=t1;
                }
                else
                {
                    t1->next=root;
                    t1=t1->next;
                }
            }
            else
            {
                if(t2==NULL)
                {
                    t2=root;
                    head2=t2;
                }
                else
                {
                    t2->next=root;
                    t2=t2->next;
                }
            }
            root=root->next;
        }
        if(t1!=NULL)
        {
            t1->next=head2;
            if(t2!=NULL)
                t2->next=NULL;
            return head1;
        }
        if(t2!=NULL)
            t2->next=NULL;
        return head2;
    }
};