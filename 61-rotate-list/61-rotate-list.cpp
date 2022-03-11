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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int siz=0;
        ListNode* temp,*lastNode,*newHead;
        int i,j;
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        temp=head;
        while(temp!=NULL)
        {
            siz++;
            lastNode=temp;
            temp=temp->next;
        }
        if(k>=siz)
        {
            k=k%siz;
        }
        if(k==0)
        {
            return head;
        }
        temp=head;
        i=1;
        while(temp!=NULL&&i<siz-k)
        {
           temp=temp->next;
           i++;
        }
        newHead=temp->next;
        temp->next=NULL;
        lastNode->next=head;
        return newHead;
    }
};