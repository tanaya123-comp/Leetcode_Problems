class Solution {
public:
    
    bool solve(vector<int>& piles,int h,int mid)
    {
        if(mid==0)
        {
            return false;
        }
        int k=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%mid==0)
            {
                k=k+piles[i]/mid;
            }
            else
            {
                k=k+piles[i]/mid;
                k=k+1;
            }
        }
        if(k<=h)
        {
            return true;
        }
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n,i,j,k,ans,maxi;
        n=piles.size();
        maxi=piles[0];
        for(i=0;i<n;i++)
        {
            if(maxi<piles[i])
            {
                maxi=piles[i];
            }
        }
        ans=INT_MAX;
        int low,mid,high;
        low=0;
        high=maxi;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(solve(piles,h,mid)&&ans>mid)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
        }
        return ans;
    }
};