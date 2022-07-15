class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int  n,m,i,j;
        n=spells.size();
        m=potions.size();  
        
        vector<int> ans(n,0);

        sort(potions.begin(),potions.end());
        
       int low,mid,high,x;
        for(i=0;i<n;i++)
        {
            low=0;
            high=m-1;
            x=m;
            while(low<=high)
            {
                mid=low+(high-low)/2;
                long long t=spells[i];
                long long s=potions[mid];
                long long prod=s*t;
                if(prod>=success)
                {
                    x=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }    
            }
            ans[i]=(m-1)-x+1;
            
        }
        return ans;
        
        
    }
};