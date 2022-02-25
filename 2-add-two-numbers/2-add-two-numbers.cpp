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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* h=NULL,*prev;
        int carry=0;
        while(l1!=NULL&&l2!=NULL)
        {
            int sum=l1->val+l2->val+carry;
            if(h==NULL)
            {
                h=new ListNode(sum%10);
                carry=sum/10;
                prev=h;
            }
            else
            {
                prev->next=new ListNode(sum%10);
                carry=sum/10;
                prev=prev->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int sum=l1->val+carry;
            if(h==NULL)
            {
                h=new ListNode(sum%10);
                carry=sum/10;
                prev=h;
            }
            else
            {
                prev->next=new ListNode(sum%10);
                carry=sum/10;
                prev=prev->next;
            }
            l1=l1->next; 
        }
         while(l2!=NULL)
        {
            int sum=l2->val+carry;
            if(h==NULL)
            {
                h=new ListNode(sum%10);
                carry=sum/10;
                prev=h;
            }
            else
            {
                prev->next=new ListNode(sum%10);
                carry=sum/10;
                prev=prev->next;
            }
            l2=l2->next; 
        }
        while(carry!=0)
        {
            int sum=carry;
            prev->next=new ListNode(sum%10);
                carry=sum/10;
                prev=prev->next;
        }
        
        return h;
    }
};