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
    unordered_map<Node*,Node*> mp;
    
    Node* cloneGraphRec(Node* node)
    {
        if(node==NULL)
        {
            return NULL;
        }
        else if(mp.find(node)!=mp.end())
        {
            return mp[node];
        }
        Node* newNode=new Node(node->val);
        mp.insert({node,newNode});
        for(int i=0;i<node->neighbors.size();i++)
        {
            newNode->neighbors.push_back(cloneGraphRec(node->neighbors[i]));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        
        return cloneGraphRec(node);
    }
};