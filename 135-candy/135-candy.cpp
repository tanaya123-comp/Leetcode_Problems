class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int siz=ratings.size(),i,j;
        vector<int> candies(siz,1);
        
        for(i=1;i<siz;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candies[i]=candies[i-1]+1;
            }
        }
        
    
        for(i=siz-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candies[i]=max(candies[i+1]+1,candies[i]);
            }
        }
        
        int result=0;
        
        for(i=0;i<siz;i++)
        {
            //ut<<candies[i]<<"\n";
            result=result+candies[i];
        }
        
        return result;   
    }
};