class Solution {
    public int trap(int[] height) {
        int length=height.length;
        int i,j,k;
        int[] left=new int[length];
        int[] right=new int[length];
        left[0]=height[0];
        for(i=1;i<length;i++)
        {
            left[i]=Math.max(height[i],left[i-1]);
        }
        right[length-1]=height[length-1];
        for(i=length-2;i>=0;i--)
        {
            right[i]=Math.max(height[i],right[i+1]);
        }
       // Collections.reverse(right);
        int ans=0;
        for(i=1;i<length-1;i++)
        {
            ans=ans+Math.abs(Math.min(left[i],right[i])-height[i]);
        }
        return ans;
    }
}