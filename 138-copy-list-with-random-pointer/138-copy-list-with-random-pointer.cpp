/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* newHead,*temp,*newNode,*prev,*nextRandom;
        unordered_map<Node*,Node*> mp;
        temp=head;
        while(temp!=NULL)
        {
            newNode=new Node(temp->val);
            mp.insert({temp,newNode});
            temp=temp->next;
        }
        //cout<<"here";
        newHead=NULL;
        temp=head;
        while(temp!=NULL)
        {
            newNode=mp[temp];
            if(temp->random!=NULL)
            {
                nextRandom=mp[temp->random];
            }
            else
            {
                nextRandom=NULL;
            }
            if(newHead==NULL)
            {
                newHead=newNode;
                prev=newHead;
                prev->random=nextRandom;
            }
            else
            {
                prev->next=newNode;
                prev=prev->next;
                prev->random=nextRandom;
            }
            temp=temp->next;
        }
        return newHead;
    }
};