class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        HashSet<List<Integer>> set=new HashSet<List<Integer>>();  
        Arrays.sort(nums);
        int i,j,n,k;
        n=nums.length;
        int sum=0;
        for(i=0;i<=n-3;i++)
        {
            j=i+1;
            k=n-1;
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    List<Integer> list=new ArrayList<Integer>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(nums[k]);
                    set.add(list);
                    k--;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            
        }
        for(List<Integer> list:set)
        {
            System.out.println(list);
            ans.add(list);
        }
        return ans;
        
        
    }
}