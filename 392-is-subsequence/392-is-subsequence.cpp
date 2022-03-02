class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n,m,i,j;
        n=s.length();
        m=t.length();
        if(n>m)
        {
            return false;
        }
        i=0;
        j=0;
        while(i<n&&j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i==n)
        {
            return true;
        }
        return false;
    }
};