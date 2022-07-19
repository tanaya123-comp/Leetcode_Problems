class Solution {
public:
    vector<vector<int>> generate(int n) 
    {    
        vector<vector<int> > ans;
         ans.push_back({1});
        if(n==1)
        {
            return ans;
        }
        
        for(int i=2;i<=n;i++)
        {
           // cout<<i<<"->";
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<=i-2;j++)
            {
                temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
            }
            temp.push_back(1);
            // for(auto x:temp)
            // {
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
            //cout<<temp<<"\n";
            ans.push_back(temp);
        }
        return ans;
    }
};