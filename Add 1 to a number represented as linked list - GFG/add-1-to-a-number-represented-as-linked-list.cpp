// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* solve(Node* head,int &carry,int &sum)
    {
        if(head==NULL)
        {
            return NULL;
        }
        head->next=solve(head->next,carry,sum);
        int x=head->data+sum+carry;
        head->data=x%10;
        sum=0;
        carry=x/10;
        return head;
    }
    
    Node* addOne(Node *head) 
    {
        int carry=0;
        int sum=1;
        Node* t=solve(head,carry,sum);
        Node* head1=t;
        while(carry!=0)
        {
            int x=carry;
            head1=new Node(x%10);
            carry=x/10;
            head1->next=t;
            t=head1;
        }
        return head1;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends