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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* prev;
        ListNode* curr;
        curr=head;
        ListNode* h=NULL;
        while(curr!=NULL)
        {
            int x=0;
            while(curr->next!=NULL&&curr->val==curr->next->val)
            {
                x=1;
                curr=curr->next;
            }
            // cout<<prev->val;
            // if(curr)
            // {
            //     cout<<" "<<curr->val<<"\n";
            // }
            if(x==0)
            {
                if(h==NULL)
                {
                    h=new ListNode(curr->val);
                    prev=h;
                }
                else
                {
                    prev->next=new ListNode(curr->val);
                    prev=prev->next;
                }
            }
            curr=curr->next;
        }
        return h;
        
    }
};