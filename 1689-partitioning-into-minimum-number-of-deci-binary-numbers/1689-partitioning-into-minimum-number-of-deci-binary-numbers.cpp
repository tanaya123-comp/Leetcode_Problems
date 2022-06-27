class Solution {
public:
    int minPartitions(string n) {
        
        int len=n.length(),i,j;
        
        int ans=n[0]-'0';
        
        for(i=0;i<len;i++)
            ans=max(ans,n[i]-'0');
        
        return ans;
    }
};