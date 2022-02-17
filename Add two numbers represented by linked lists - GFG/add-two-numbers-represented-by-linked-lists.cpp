// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    int getLength(struct Node* head)
    {
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    void addZeros(struct Node* &head,int l)
    {
        
        while(l!=0)
        {
            struct Node* h1=new struct Node(0);
            h1->next=head;
            head=h1;
            l--;
        }
    }
    
    struct Node* solve(struct Node* first,struct Node* second,int &carry)
    {
        if(first==NULL&&second==NULL)
        {
            return NULL;
        }
        struct Node* next=solve(first->next,second->next,carry);
        int sum=first->data+second->data+carry;
        int data=sum%10;
        carry=sum/10;
        struct Node* t=new struct Node(data);
        t->next=next;
        return t;
    }
    
   
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int len1=getLength(first);
        int len2=getLength(second);
        if(len1<len2)
        {
            addZeros(first,len2-len1);
        }
        else if(len2<len1)
        {
            addZeros(second,len1-len2);
        }
        
        int carry=0;
        
        struct Node* t=solve(first,second,carry);
        struct Node* head1;
        while(carry!=0)
        {
            head1=new struct Node(carry%10);
            carry=carry/10;
            head1->next=t;
            t=head1;
        }
        return t;
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends