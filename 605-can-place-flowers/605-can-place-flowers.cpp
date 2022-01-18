class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int i,j,siz;
        siz=flowerbed.size();
        if(n==0)
        {
            return true;
        }
        i=0;
        while(i<siz)
        {
            if(flowerbed[i]==1)
            {
                i=i+2;
            }
            else if(flowerbed[i]==0&&n>0)
            {
                if((i+1<siz&&flowerbed[i+1]==0)||(i+1)==siz)
                {
                    n--;
                    i=i+2;
                }
                else
                {
                    i=i+1;
                }
            }
            if(n==0)
            {
                break;
            }
        }
        if(n==0)
        {
            return true;
        }
        return false;
        
    }
};