class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
       int n,m,i,j;
        n=s.length();
        m=p.length();
        vector<int> pv(26,0),sv(26,0);
        vector<int> ans;
        if(n<m)
        {
            return ans;
        }
        for(i=0;i<m;i++)
        {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        if(pv==sv)
        {
            ans.push_back(0);
        }
        
        for(i=p.size();i<n;i++)
        {
            sv[s[i]-'a']++;
            
            sv[s[i-m]-'a']--;
            
            
            if(pv==sv)
            {
                ans.push_back(i-m+1);
            }
        }
        
        return ans;
        
    }
};