class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        long long siz,i,j,temp_sum1,temp_sum2;
        siz=cardPoints.size();
        
        vector<long long> prefix(siz);
        
        prefix[0]=cardPoints[0];
        
        for(i=1;i<siz;i++)
        {
            prefix[i]=prefix[i-1]+cardPoints[i];
        }
        
        long long ans=prefix[k-1];
        i=0;
        
        if(siz==k)
        {
            return prefix[siz-1];
        }

        while(i<=k)
        {
            j=k-i;
            
            if(i>0)
            {
                temp_sum1=prefix[i-1];
            }
            else
            {
                temp_sum1=0;
            }
            if(j>0)
            {
                temp_sum2=prefix[siz-1]-prefix[siz-j-1];
            }
            else
            {
                temp_sum2=0;
            }
            
            if(ans<(temp_sum1+temp_sum2))
                ans=temp_sum1+temp_sum2;
            
            i++;
        }
        
        return ans;
        
    }
};