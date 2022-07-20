class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(),special.end());
        int n,i,j;
        n=special.size();
        
        int ans=0;
        
        if(bottom<special[0])
        {
            ans=special[0]-bottom;
        }
        
        for(i=1;i<n;i++)
        {
            if(special[i]-special[i-1]>1)
                ans=max(ans,special[i]-special[i-1]-1);
        }
        
        
        ans=max(ans,top-special[n-1]);
        
        return ans;
    }
};