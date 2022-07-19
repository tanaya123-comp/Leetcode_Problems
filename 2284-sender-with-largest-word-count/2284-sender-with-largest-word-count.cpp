class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        int n,i,j,k;
        n=messages.size();
        vector<int> vec(n,0);
        for(i=0;i<n;i++)
        {
            int cnt=0;
            j=0;
            k=messages[i].length();
            while(j<k)
            {
                while(j<k&&messages[i][j]!=' ')
                {
                    j++;
                }
                cnt++;
                j++;
            }
            vec[i]=cnt;
        }
        
        map<string,int> mp;
        
        for(i=0;i<n;i++)
        {
            mp[senders[i]]+=vec[i];
        }
        
        auto it=mp.begin();
        int ans=it->second;
        string sender=it->first;
        for(auto it:mp)
        {
            if(it.second>=ans)
            {
                ans=it.second;
                sender=it.first;
            }
        }
        return sender;
        
        
        
        
    }
};