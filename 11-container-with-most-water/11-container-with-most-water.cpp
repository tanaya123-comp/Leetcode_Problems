class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int siz=height.size();
        int i,j;
        int ans=0;
        i=0;
        j=siz-1;
        while(i<j)
        {
            int area=(j-i)*min(height[i],height[j]);
            ans=max(ans,area);
            
            if(height[i]<=height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};