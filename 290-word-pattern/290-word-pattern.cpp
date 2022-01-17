class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        int n,m,i,j;
        map<char,string> mp;
        map<string,char> mp2;
        n=pattern.length();
        m=s.length();
        i=0;
        j=0;
        while(i<n&&j<m)
        {
            string t="";
            while(s[j]!=' '&&j<m)
            {
                t=t+s[j];
                j++;
            }
            if(mp.find(pattern[i])!=mp.end()&&mp2.find(t)!=mp2.end())
            {
                if(mp[pattern[i]]!=t||mp2[t]!=pattern[i])
                {
                    return false;
                }
                else
                {
                    j++;
                    i++;
                }
            }
            else if(mp.find(pattern[i])==mp.end()&&mp2.find(t)==mp2.end())
            {
                mp.insert({pattern[i],t});
                mp2.insert({t,pattern[i]});
                i++;
                j++;
            }
            else
            {
                return false;
            }
        }
     //   cout<<i<<" "<<j<<"\n";
        if(i==n&&j==m+1)
        {
            return true;
        }
        return false;
        
    }
};