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
    
    pair<ListNode*,ListNode*> reverse(ListNode* root)
    {
        ListNode* curr,*prev,*next;
        curr=root;
        prev=NULL;
        next=NULL;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return {prev,root};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* curr,*prev,*next;
        int ptr;
        
        //get the leftmost node
        ptr=1;
        curr=head;
        prev=NULL;
        while(ptr<left&&curr!=NULL)
        {
            prev=curr;
            curr=curr->next;
            ptr++;
        }
        
        ListNode* leftNode=curr;
        
        //get the rightmost node
        curr=head;
        ptr=1;
        while(ptr<right&&curr!=NULL)
        {
            curr=curr->next;
            ptr++;
        }
        next=curr->next;
        
        //reverse the node from left to right
        curr->next=NULL;
        pair<ListNode*,ListNode*> p=reverse(leftNode);
        
        if(prev==NULL)
        {
            
            if(next==NULL)
            {
                return p.first;
            }
            else
            {
                p.second->next=next;
                return p.first;
            }
        }
        prev->next=p.first;
        if(next==NULL)
        {
            return head;
        }
        else
        {
            p.second->next=next;
            return head;
        }
        return NULL;
        
    }
};