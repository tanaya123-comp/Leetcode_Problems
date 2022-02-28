/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    
    static bool cmp(pair<int,int> a, pair<int,int> b){

    return (a.first==b.first) ? a.second < b.second : a.first < b.first;
        }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root) return ans;
    queue<pair<TreeNode* , int>> q;
    map<int,vector<pair<int,int>>>mp;
    q.push({root,0});
    int level =0;
    while(!q.empty())
    {
        int x = q.size();
        for(int i=0;i<x;i++){
            TreeNode* temp = q.front().first;
            int h = q.front().second;
            q.pop();
            mp[h].push_back({level,temp->val});
            if(temp->left) q.push({temp->left,h-1});
            if(temp->right) q.push(make_pair(temp->right,h+1));
            
        }
        level++;
    }
    for(auto it : mp){
        vector<pair<int,int>> v = it.second;
        
        sort(v.begin(),v.end(),cmp);
        vector<int> demo;
        for(auto it : v){
            demo.push_back(it.second);
        }
        ans.push_back(demo);
    }
    return ans;
    }
};