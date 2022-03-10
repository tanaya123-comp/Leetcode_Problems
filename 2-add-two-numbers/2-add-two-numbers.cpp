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
        
       ListNode* h=NULL,*p;
       int carry=0,sum;
       while(l1!=NULL&&l2!=NULL)
       {
           sum=l1->val+l2->val+carry;
           if(h==NULL)
           {
               h=new ListNode(sum%10);
               carry=sum/10;
               p=h;
           }
           else
           {
               p->next=new ListNode(sum%10);
               carry=sum/10;
               p=p->next;
           }
           l1=l1->next;
           l2=l2->next;
       }
        while(l1!=NULL)
        {
          sum=l1->val+carry;
           if(h==NULL)
           {
               h=new ListNode(sum%10);
               carry=sum/10;
               p=h;
           }
           else
           {
               p->next=new ListNode(sum%10);
               carry=sum/10;
               p=p->next;
           }
           l1=l1->next;   
        }
        while(l2!=NULL)
        {
            sum=l2->val+carry;
           if(h==NULL)
           {
               h=new ListNode(sum%10);
               carry=sum/10;
               p=h;
           }
           else
           {
               p->next=new ListNode(sum%10);
               carry=sum/10;
               p=p->next;
           }
           l2=l2->next; 
        }
        while(carry>0)
        {
            p->next=new ListNode(carry%10);
            carry=carry/10;
            p=p->next;
        }
        return h;
    }
};