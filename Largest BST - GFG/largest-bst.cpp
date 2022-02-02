// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    int largestBST(Node* node)
    {
        int min = INT_MAX; 
        int max = INT_MIN; 
         
        int max_size = 0; 
        bool is_bst = 0;
         
        largestBSTUtil(node, &min, &max,
                        &max_size, &is_bst);
         
        return max_size;
    }
    
    int largestBSTUtil(Node* node, int *min_ref, int *max_ref,
                    int *max_size_ref, bool *is_bst_ref)
{
 
   
    if (node == NULL)
    {
        *is_bst_ref = 1;
        return 0; 
    }
     
    int min = INT_MAX;
     
    
    bool left_flag = false;
     
    
    bool right_flag = false;
     
    int ls, rs; 
     
  
    *max_ref = INT_MIN;
    ls = largestBSTUtil(node->left, min_ref, max_ref,
                        max_size_ref, is_bst_ref);
    if (*is_bst_ref == 1 && node->data > *max_ref)
        left_flag = true;
   
    min = *min_ref;
     
    *min_ref = INT_MAX;
    rs = largestBSTUtil(node->right, min_ref,
                        max_ref, max_size_ref, is_bst_ref);
    if (*is_bst_ref == 1 && node->data < *min_ref)
        right_flag = true;
    
    if (min < *min_ref)
        *min_ref = min;
    if (node->data < *min_ref) 
        *min_ref = node->data;
    if (node->data > *max_ref)
        *max_ref = node->data;

    if(left_flag && right_flag)
    {
        if (ls + rs + 1 > *max_size_ref)
            *max_size_ref = ls + rs + 1;
        return ls + rs + 1;
    }
    else
    {
        *is_bst_ref = 0;
        return 0;
    }
}
 
    
    
    
    int largestBst(Node *root)
    {
    	return largestBST(root);
    	
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends