class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        
        int i,siz,j;
        siz=flowerbed.size();
        
        for(i=0;i<siz;i++)
        {
            if(n>0&&flowerbed[i]==0)
            {
                j=0;
                if((i-1)>=0&&flowerbed[i-1]==1)
                {
                    j=1;
                }
                if((i+1)<siz&&flowerbed[i+1]==1)
                {
                    j=1;
                }
                if(j==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        
        return n==0;
    }
};