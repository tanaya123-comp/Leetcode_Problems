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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr,*prev,*next;
        curr=head;
        prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
        
    }
    
    bool isPallindrome(ListNode* head1,ListNode* head2)
    {
        while(head1!=NULL&&head2!=NULL)
        {
            if(head1->val!=head2->val)
            {
                return false;
            }
            else
            {
                head1=head1->next;
                head2=head2->next;
            }
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        
        int n=0;
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* root=head;
        ListNode* first,*second;
        while(root!=NULL)
        {
            n++;
            root=root->next;
        }
        
        if(n%2==0)
        {
            first=head;
            second=head;
            while(first!=NULL&&second!=NULL&&second->next!=NULL)
            {
                first=first->next;
                second=second->next->next;
            }
            second=reverse(first);
            first=head;
          
        }
        else
        {
            first=head;
            second=head;
            while(first!=NULL&&second!=NULL&&second->next!=NULL)
            {
                first=first->next;
                second=second->next->next;
            }
            second=reverse(first->next);
            first=head;
        }
          return isPallindrome(first,second);
    }
};