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
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> s;
        ListNode* p=head;
        while(p!=NULL)
        {
            if(s.count(p)==1)
            {
                return p;
            }
            s.insert(p);
            p=p->next;
        }
        
        return NULL;
        
    }
};