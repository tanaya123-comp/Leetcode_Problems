class Solution {
public:
    
   int countPairs(vector<int> &nums,int low,int mid,int high)
   {
       //  // two pointers;
       //  int l = start, r = mid + 1;
       //  while(l <= mid && r <= end){
       //      if((long)nums[l] > (long) 2 * nums[r]){
       //          count += (mid - l + 1);
       //          r++;
       //      }else{
       //          l++;
       //      }
       //  }
       // // worst case might be nlog(n) 
       //  sort(nums.begin() + start, nums.begin() + end + 1);
       //  return;
        
       
       
       int i,j,k;
       long long t;
       i=low;
       j=mid+1;
       int count=0;
       while(i<=mid&&j<=high)
       {
           //t=nums[j]*2;
           if((long)nums[i] > (long) 2 * nums[j])
           {
               count=count+mid-i+1;
               j++;
           }
           else
           {
               i++;
           }
       }
       sort(nums.begin()+low,nums.begin()+high+1);
       return count;
   }
    
    int partitions(vector<int> &nums,int low,int high)
    {
        int count=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            count=count+partitions(nums,low,mid);
            count=count+partitions(nums,mid+1,high);
            count=count+countPairs(nums,low,mid,high);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        int count=partitions(nums,0,n-1);
        // for(auto x:nums)
        // {
        //     cout<<x<<"\n";
        // }
        return count;

    }
};