class Solution {
public:
    int minDeletions(string s) {
        
        int len,i,j;
        int arr[26]={0};
        len=s.length();
        
        for(i=0;i<len;i++)
        {
            arr[s[i]-'a']++;
        }
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                 // cout<<arr[i]<<"\n";
                mp[arr[i]]++;
            }
        }
        
        int minimum_num_deletions=0;
        
        for(auto x:mp)
        {
            if(x.second>1)
            {
                int siz=x.first-1;
                int t=x.second-1;
                //cout<<siz<<" "<<t<<"\n";
                while(t--)
                {
                    siz=x.first;
                    while(siz>0&&mp.find(siz)!=mp.end())
                    {
                        siz--;
                        minimum_num_deletions++;
                    }
                    if(siz>0)
                    {
                        mp[siz]=1; 
                    }  
                }
                
            }
        }
        
        return minimum_num_deletions;
        
    }
};