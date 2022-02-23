/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<int,Node*> s;
    
    Node* clone(Node* root)
    {
        if(s.find(root->val)!=s.end())
        {
            return s[root->val];
        }
        Node* newNode=new Node(root->val);
          s.insert({newNode->val,newNode});
        for(auto x:root->neighbors)
        {
            newNode->neighbors.push_back(clone(x));
        }
      
        return newNode;
    }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
        {
            return node;
        }
        
        return clone(node);
        
    }
};