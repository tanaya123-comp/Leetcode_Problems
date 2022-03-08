/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL||head->next==NULL)
        {
            return false;
        }
        ListNode* first=head;
        ListNode* second=head;
        while(first!=NULL&&second!=NULL&&second->next!=NULL)
        {
            first=first->next;
            second=second->next->next;
            if(first==second)
            {
                return true;
            }
        }
        return false;
    }
};